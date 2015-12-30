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
void radioStartReceive();
uint8 radioGetState();
uint8 radioEndReceive(uint8);
uint16 radioReadBuf(uint16);

void main()
{
    CYGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
	uint16 rxState=0x00;	
	uint16 val=0x00;
	uint16 i=0x00;
	
	 LCD_Start();
	 LCD_ClearDisplay();
	 LCD_Position(0,0);
	 LCD_PrintString("RX");
	 
	 SPIM_Start();
	 SPIM_ClearRxBuffer();
	 SPIM_ClearTxBuffer();
	 SPIM_ClearFIFO();
	
	radioInit();
	
	radioWrite(0x01,0x02);
	val=radioRead(0x01);
	if (val==0x02){
	LCD_Position(1,0);
	LCD_PrintString("S");
	}
		
		
	radioStartReceive();
	
	while (1){
	
	rxState=radioGetState();
	   // store the packet onto a local buffer if
	   LCD_Position(1,5);
	   LCD_PrintInt8(rxState);
	   
	   if (rxState==8 || rxState==7){
		radioStartReceive();
		 LCD_Position(1,4);
		LCD_PrintString("A");
		}
   //receive operation complete
   if (rxState & RXC_IRQ)
    {
	
   if (radioEndReceive(rxState))
    {
	
    val=radioReadBuf(RX_BUFFER_ADR);
	//retrieved data displayed on the LCD screen

    LCD_Position(0,3);
	LCD_PrintInt8(val);
    //generate a small delay before receiving the next data
	//CyDelay(100);
	
	}
	
	//restart the receive operation
	radioStartReceive();
	i++;
	 // store the packet onto a local buffer if
	LCD_Position(0,14);
	LCD_PrintInt8(i);
	}
    }
}

	 
	


void radioWrite(uint16 addr,uint16 dat){
	SPIM_ClearRxBuffer();
	SPIM_ClearTxBuffer();
	
	SPIM_WriteTxData(0x80+addr);
	SPIM_WriteTxData(dat);
	while(!SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE);
}

uint16 radioReadBuf(uint16 addr){
	uint16 val=0x00;
	uint16 i=0;
	SPIM_ClearRxBuffer();
	SPIM_ClearTxBuffer();
	
	SPIM_WriteTxData(addr);
	SPIM_WriteTxData(0x00);
	SPIM_WriteTxData(0x00);
	SPIM_WriteTxData(0x00);

	while(!SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE);
	
	//for (i=0;i<4;i++){
			val=SPIM_ReadRxData();
			LCD_Position(0,5);
			LCD_PrintInt8(val);
			i=SPIM_ReadRxData();
			LCD_Position(0,7);
			LCD_PrintInt8(i);
			val=SPIM_ReadRxData();
			LCD_Position(0,9);
			LCD_PrintInt8(val);
			val=SPIM_ReadRxData();
			LCD_Position(0,11);
			LCD_PrintInt8(val);
	return i;
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
		//	CyDelay(1000);
		}
	return val;
}

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
   radioWrite(XACT_CFG_ADR, 0x90);
	
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

void radioStartReceive(){
	uint16 val=0x00;
    radioWrite(RX_CTRL_ADR, (RX_GO | RXC_IRQ | RXE_IRQ));
    /* Clear RSSI */
    radioRead(RSSI_ADR);
	val=radioRead(RX_CTRL_ADR);
	LCD_Position(1,2);
	LCD_PrintInt8(val);
}

uint8 radioGetState()
{
    uint8 Status = 0;
   
	/* This register needs to be debounced. */
     Status  = radioRead(RX_IRQ_STATUS_ADR);
     Status |= radioRead(RX_IRQ_STATUS_ADR);
     if (Status & (RXBERR_IRQ | RXE_IRQ))
        {
             /* If overflow, set the completion bit to force the end of packet. */
            Status |= (RXC_IRQ | RXE_IRQ);
        }
    
    return Status;
}	

uint8 radioEndReceive(uint8 RadioState)
{
    uint8 Count;
	uint8 val=0x00;
    Count = radioRead(RX_LENGTH_ADR);
	LCD_Position(1,11);
	LCD_PrintInt8(Count);
    
	if (RadioState & RXE_IRQ)
    {
        uint8 index;

        /* burp the buffer */
        for (index = 15; index; --index)
        {
            radioRead(RX_BUFFER_ADR);
        }
        /* Packet was bad. */
        Count = 0;
    }
    /* Abort by writing the FRC_END_STATE bit in the XACT_CFG register. */
   radioWrite(XACT_CFG_ADR, radioRead(XACT_CFG_ADR) | FRC_END_STATE);
    /*
     * Wait for the FRC_END_STATE bit in the XACT_CFG register to clear
     * indicating the force has completed.
     */

    while(radioRead( XACT_CFG_ADR) &  FRC_END_STATE) {};
	
	val=radioRead(RX_STATUS_ADR);
	LCD_Position(1,8);
	LCD_PrintInt8(val);
	
	
	
    return Count;
}
