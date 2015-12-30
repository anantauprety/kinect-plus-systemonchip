/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <device.h>
#include <lpregs.h>

void radioWrite(uint16,uint16);
uint16 radioRead(uint16);
void radioInit();
uint16 prepareData();
uint16 xyz=0x00;
uint16 red=0;
uint16 green=0;
uint16 blue=0;
uint16 active=0;
uint16 newData=0;

void main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    CYGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
	uint16 dat=0x69;
	uint16 val=0x00;
	uint16 irqStat=0x00;
	uint16 pos=0;

    LCD_Start();
	LCD_ClearDisplay();
	LCD_Position(0,0);
	LCD_PrintString("TX");
	 
	 SPIM_Start();
	 SPIM_ClearRxBuffer();
	 SPIM_ClearTxBuffer();
	 SPIM_ClearFIFO();
	
	CapSense_Start();
	CapSense_InitializeAllBaselines();
	CapSense_ScanEnabledWidgets();
	
	radioInit();
	
	radioWrite(0x01,0x02);
	val=radioRead(0x01);
	if (val==0x02){
	LCD_Position(1,0);
	LCD_PrintString("S");
	}
	
	
	
	for(;;)
    {
	if (CapSense_IsBusy()==0){
		CapSense_UpdateEnabledBaselines();
		
		if (CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN)&! CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN))
            {
              	LCD_Position(0,0);
               LCD_PrintString("Red  "); 
			   active=1;
                /* Turn ON the LED_1*/
             //  Pin_LED_1_Write(1);
             LCD_Position(0,6);
		LCD_PrintNumber(red);
			
            }
		else if (CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN)&! CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN))
        {
          LCD_Position(0,0);
          LCD_PrintString("Green "); 
		   active=2;
            /* Turn ON the LED_1*/
         //  Pin_LED_1_Write(1);
		LCD_Position(0,6);
		LCD_PrintNumber(green);
		}
		else if (CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN)&& CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN) ){
		LCD_Position(0,0);
          LCD_PrintString("Blue "); 
		   active=3;
		LCD_Position(0,6);
		LCD_PrintNumber(blue);
		}
		
		
		pos=CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS);
		
		if (pos!=65535){
		if (active==1) {
			red=pos;
			newData=1;
			}
		else if (active==2) {
		green=pos;
		newData=1;
		}
		else if (active==3) {
		blue=pos;
		newData=1;
		}

	if (newData==1){		
		radioWrite(TX_CTRL_ADR, TX_CLR);
		
		// Set the length of data to 3 byte
		 radioWrite(TX_LENGTH_ADR,0x03);
		val=radioRead(TX_LENGTH_ADR);
		//LCD_Position(1,2);
		LCD_PrintInt8(val);
		 //Write the byte to the radio 
		radioWrite(TX_BUFFER_ADR,red);
		radioWrite(TX_BUFFER_ADR,green);
		radioWrite(TX_BUFFER_ADR,blue);
		
	//Start transmission
		// radioWrite(TX_CTRL_ADR, TXC_IRQ | TX_GO);
		 radioWrite(TX_CTRL_ADR, 0x83);

	//	val=radioRead(TX_CTRL_ADR);
	//LCD_Position(1,4);
	//LCD_PrintInt8(val);

	
		newData=0;
	//	while (!(irqStat & TXC_IRQ)){
	//irqStat=radioRead(TX_IRQ_STATUS_ADR);
	//LCD_Position(1,8);
	//LCD_PrintInt8(irqStat); 
//	}
}

   	active=0;
	
   }
   CapSense_ScanEnabledWidgets();
   }
}
}


uint16 prepareData(){
	xyz=xyz+1;
	
	if (xyz==99) xyz=0;
	
	 
	
	return xyz;




}
/* [] END OF FILE */
void radioInit(){
 
	 /* Reset the LP through the SPI (soft reset). */
	radioWrite(MODE_OVERRIDE_ADR, RST);

    /* Set up to use auto-cal for VCO. */
   radioWrite(AUTO_CAL_TIME_ADR, AUTO_CAL_TIME_MAX); /* Extend autoCal time to max. */

    radioWrite(AUTO_CAL_OFFSET_ADR, AUTO_CAL_OFFSET_MINUS_4); /* AutoCal offset to -4. */

    /* Set IRQ polarity to positive. */
    radioWrite(IO_CFG_ADR, IRQ_POL);

    /* Set the XTAL Startup delay to 150uSec to handle warm restarts of the XTAL. */
    radioWrite(XTAL_CFG_ADR, 0x08);
    /*
     * Enable HiLo for quick-turn-around. Use low side injection for receive 
     * this should result in non-inverted data, so no need to hit the invert
     * bit. Turn off AGC and force the LNA on.
     */
   radioWrite(RX_CFG_ADR,
                 ((RX_CFG_RST | FASTTURN_EN | LNA_EN ) & ~( HI | RXOW_EN | AUTO_AGC_EN)));

    /*
     * Set the TX Offset to +1MHz.
     * THIS MEANS THE ACTUAL TRANSMIT CARRIER WILL BE 1MHz ABOVE THE PLL
     * FREQUENCY PROGRAMMED IN THE CHANNEL OR A & N REGISTERS.
     * RadioSetFrequency COMPENSATES FOR THIS OFFSET.
     */
    radioWrite(TX_OFFSET_LSB_ADR, 0x55);
    radioWrite(TX_OFFSET_MSB_ADR, 0x05);
	radioWrite(DATA32_THOLD_ADR,0x05);
	radioWrite(FRAMING_CFG_ADR,0xA4);
    /* Set Data Mode to 250kbps */
   radioWrite(TX_CFG_ADR, TX_CFG_RST | DATMODE_8DR);
}

void radioWrite(uint16 addr,uint16 dat){
	SPIM_ClearRxBuffer();
	SPIM_ClearTxBuffer();
	
	SPIM_WriteTxData(0x80+addr);
	SPIM_WriteTxData(dat);
	while(!SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE);
}


uint16 radioRead(uint16 addr){
	uint16 val=0x00;
	uint16 i=0;
	SPIM_ClearRxBuffer();
	SPIM_ClearTxBuffer();
	
	SPIM_WriteTxData(addr);
	SPIM_WriteTxData(0x00);
	SPIM_WriteTxData(0x00);
	SPIM_WriteTxData(0x00);

	while(!SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE);
	
	for (i=0;i<2;i++){
			val=SPIM_ReadRxData();
			LCD_Position(1,14);
			LCD_PrintInt8(val);
			//CyDelay(1000);
		}
	return val;
}