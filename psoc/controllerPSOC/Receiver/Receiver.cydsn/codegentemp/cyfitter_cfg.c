/*******************************************************************************
* FILENAME: cyfitter_cfg.c
* PSoC Creator 2.0
*
* Description:
* This file is automatically generated by PSoC Creator with device 
* initialization code.
*
* THIS FILE SHOULD NOT BE MODIFIED.
*
********************************************************************************
* Copyright 2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include <string.h>
#include <cytypes.h>
#include <cydevice_trm.h>
#include <cyfitter.h>
#include <CyLib.h>
#include <CyDmac.h>
#include <cyfitter_cfg.h>

/* Clock startup error codes                                                   */
#define CYCLOCKSTART_NO_ERROR    0
#define CYCLOCKSTART_XTAL_ERROR  1
#define CYCLOCKSTART_32KHZ_ERROR 2
#define CYCLOCKSTART_PLL_ERROR   3

/*******************************************************************************
* Function Name: CyClockStartupError
********************************************************************************
* Summary:
*  If an error is encountered during clock configuration (crystal startup error,
*  PLL lock error, etc) the system will end up here.  Unless reimplemented by 
*  the customer, an infinite loop will be encountered.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
__attribute__ ((unused))
#endif
static void CyClockStartupError(uint8 errorCode)
{
    /* To remove the compiler warning if errorCode not used.                */
    errorCode = errorCode;

    /* `#START CyClockStartupError` */

    /* If we have a clock startup error (bad MHz crystal, PLL lock, etc)    */
    /* we will end up here to allow the customer to implement something to  */
    /* deal with the clock condition.                                       */

    /* `#END` */

    /* If nothing else, stop here since the clocks have not started         */
    /* correctly.                                                           */
    while(1) {}
}


#undef CYCODE
#undef CYDATA
#undef CYXDATA
#undef CYFAR
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
	#define CYCODE
	#define CYDATA
	#define CYXDATA
	#define CYFAR

	#define CYPACKED __attribute__ ((packed))
	#define CYALIGNED __attribute__ ((aligned))
	
    #if CYDEV_CONFIGURATION_DMA
        #define DMAINITSEC __attribute__ ((section (".dma_init")))
    #else
        #define DMAINITSEC
    #endif

	#if defined(__ARMCC_VERSION)
		#define CY_CFG_MEMORY_BARRIER() __memory_changed()
	#else
		#define CY_CFG_MEMORY_BARRIER() __sync_synchronize()
	#endif
	
    /*******************************************************************************
    * Function Name: cymemzero8
    ********************************************************************************
    * Summary:
    *  This function is provided as a way to initialize a block of memory to zero
    *  one byte at a time.  While this is a 32bit processor, some of the 
    *  configuration registers are only 8bits wide.  This allows us to initialize
    *  just the registers we care about.
    *
    * Parameters:  
    *   addr  - The first address to start writing zero to.
    *   count - The number of bytes to write 0 to.
    *
    * Return:
    *   void
    *
    *******************************************************************************/
    __attribute__ ((unused))
    static void cymemzero8(void *addr, unsigned int count)
    {
	    volatile uint8 *addr8 = (uint8 *)addr;
	    while (count--)
	    {
		    *addr8 = 0;
		    addr8++;
	    }
    }

    /*******************************************************************************
    * Function Name: cymemcpy8
    ********************************************************************************
    * Summary:
    *  This function is provided as a way to copy data from one location to another
    *  one byte at a time.  While this is a 32bit processor, some of the 
    *  configuration registers are only 8bits wide.  This allows us to initialize
    *  just the registers we care about.
    *
    * Parameters:  
    *   dest  - The destination address to copy data to.
    *   src   - The source address to copy data from.
    *   count - The number of bytes to copy from 'src' to 'dest'.
    *
    * Return:
    *   void
    *
    *******************************************************************************/
    __attribute__ ((unused))
    static void cymemcpy8(void *dest, const void *src, unsigned int count)
    {
	    volatile uint8 *dest8 = (uint8 *)dest;
	    const uint8 *src8 = (const uint8 *)src;

	    while (count--)
	    {
		    *dest8 = *src8;
		    dest8++;
		    src8++;
	    }
    }

    #define CYMEMZERO8(a,c) cymemzero8((a),(c))
    #define CYCONFIGCPY8(d,s,c) cymemcpy8((d),(s),(c))
    #define CYCONFIGCPYCODE8(d,s,c) cymemcpy8((d),(s),(c))
	
	#define CYMEMZERO(a,c) memset((a),0,(c))
	#define CYCONFIGCPY(d,s,c) memcpy((d),(s),(c))
	#define CYCONFIGCPYCODE(d,s,c) memcpy((d),(s),(c))
#else
	#error Unsupported toolchain
#endif

/* Defines the layout and meaning of each entry in the cfg_memset_list used for clearing registers */
typedef struct {
	void CYFAR *address;
	uint16 size;
} CYPACKED cfg_memset_t;

/* Defines the layout and meaning of each entry in the cfg_memcpy_list used for initializing registers */
typedef struct {
	void CYFAR *dest;
	const void CYFAR *src;
	uint16 size;
} CYPACKED cfg_memcpy_t;

/* TD structure for little-endian systems. Does not require endian swap */
struct td_t {
	uint16 size;
	uint8 next_td_ptr;
	uint8 flags;
	uint16 src;
	uint16 dest;
} CYPACKED;

/* UDB_1_0_0_CONFIG Address: CYDEV_UCFG_B1_P2_U0_BASE Size (bytes): 128 */
#define BS_UDB_1_0_0_CONFIG_VAL ((const uint8 CYFAR *)0x48000000)

/* UDB_1_0_1_CONFIG Address: CYDEV_UCFG_B1_P2_U1_BASE Size (bytes): 128 */
#define BS_UDB_1_0_1_CONFIG_VAL ((const uint8 CYFAR *)0x48000080)

/* UDB_1_1_0_CONFIG Address: CYDEV_UCFG_B1_P3_U1_BASE Size (bytes): 128 */
#define BS_UDB_1_1_0_CONFIG_VAL ((const uint8 CYFAR *)0x48000100)

/* UWRK_B1_WRK_STATCTL_BITS Address: CYDEV_UWRK_UWRK8_B1_BASE + 0x00000070 Size (bytes): 32 */
#define BS_UWRK_B1_WRK_STATCTL_BITS_VAL ((const uint8 CYFAR *)0x48000180)

/* DSISWITCH_0_0 Address: CYDEV_UCFG_DSI13_BASE Size (bytes): 128 */
#define BS_DSISWITCH_0_0_VAL ((const uint8 CYFAR *)0x480001A0)

/* DSI0_0_HV_ROUTING Address: CYDEV_UCFG_DSI13_BASE + 0x00000080 Size (bytes): 128 */
#define BS_DSI0_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x48000220)

/* UDB_1_0_HV_ROUTING Address: CYDEV_UCFG_B1_P5_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_1_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480002A0)

/* UDBSWITCH_1_0 Address: CYDEV_UCFG_B1_P2_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_1_0_VAL ((const uint8 CYFAR *)0x48000320)

/* UDB_2_0_HV_ROUTING Address: CYDEV_UCFG_B1_P2_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_2_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480003A0)

/* UDBSWITCH_1_1 Address: CYDEV_UCFG_B1_P3_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_1_1_VAL ((const uint8 CYFAR *)0x48000420)

/* UDB_2_1_HV_ROUTING Address: CYDEV_UCFG_B1_P3_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_2_1_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480004A0)

/* DSISWITCH_1_0 Address: CYDEV_UCFG_DSI9_BASE Size (bytes): 128 */
#define BS_DSISWITCH_1_0_VAL ((const uint8 CYFAR *)0x48000520)

/* DSI3_0_HV_ROUTING Address: CYDEV_UCFG_DSI9_BASE + 0x00000080 Size (bytes): 128 */
#define BS_DSI3_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480005A0)

/* UCFG_BCTL1 Address: CYREG_BCTL1_MDCLK_EN Size (bytes): 16 */
#define BS_UCFG_BCTL1_VAL ((const uint8 CYFAR *)0x48000620)

/* IOPINS0_1 Address: CYREG_PRT1_DM0 Size (bytes): 8 */
#define BS_IOPINS0_1_VAL ((const uint8 CYFAR *)0x48000630)

/* IOPINS0_2 Address: CYREG_PRT2_DM0 Size (bytes): 8 */
#define BS_IOPINS0_2_VAL ((const uint8 CYFAR *)0x48000638)

/* IOPORT_1 Address: CYDEV_PRTDSI_PRT1_BASE Size (bytes): 7 */
#define BS_IOPORT_1_VAL ((const uint8 CYFAR *)0x48000640)

/* IOPORT_2 Address: CYDEV_PRTDSI_PRT2_BASE Size (bytes): 7 */
#define BS_IOPORT_2_VAL ((const uint8 CYFAR *)0x48000648)


/* PHUB_CH1_CFGMEM_CFG0/1 initialization data */
static const uint8 CYCODE CH1_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x40 };

/* PHUB_CH2_CFGMEM_CFG0/1 initialization data */
static const uint8 CYCODE CH2_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x20, 0x01, 0x40 };

/* PHUB_CH5_CFGMEM_CFG0/1 initialization data */
static const uint8 CYCODE CH5_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x40 };

/* PHUB_CH6_CFGMEM_CFG0/1 initialization data */
static const uint8 CYCODE CH6_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x48, 0x01, 0x40 };

/* Initialization data for each DMA channel's TD registers */
static const uint8 CYCODE DMA_TD_START_CMD[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x01 };

static uint32 CYXDATA DMA_ZERO_VAL CYALIGNED;

/* This table holds all of the initialization data necessary for the DMA
   process to transfer data from the source location to the destination. */
/* Source addresses can be relocated, but only when in 32bit addresses.
   Because the standard TD table only has 16bit addresses, we generate a
   seperate CFG_TD_ADDR table for the source addresses that supports 32bit
   addresses. */
static const struct td_t CYCODE CFG_TD_LIST0[] DMAINITSEC = {
/* Size, Next, Flags, Source, Destination */
	{ 8, 0x02, 0x23, (uint16)(0), (uint16)(CYREG_PHUB_CFGMEM1_CFG0) },	/* TD 1 */
	{ 8, 0x03, 0x23, (uint16)(0), (uint16)(CYREG_PHUB_CFGMEM2_CFG0) },	/* TD 2 */
	{ 8, 0x04, 0x23, (uint16)(0), (uint16)(CYREG_PHUB_CFGMEM5_CFG0) },	/* TD 3 */
	{ 8, 0x05, 0x23, (uint16)(0), (uint16)(CYREG_PHUB_CFGMEM6_CFG0) },	/* TD 4 */
	{ 5, 0x06, 0x23, (uint16)(0), (uint16)(CYREG_PHUB_CH1_BASIC_CFG) },	/* TD 5 */
	{ 5, 0x07, 0x23, (uint16)(0), (uint16)(CYREG_PHUB_CH2_BASIC_CFG) },	/* TD 6 */
	{ 5, 0x08, 0x23, (uint16)(0), (uint16)(CYREG_PHUB_CH5_BASIC_CFG) },	/* TD 7 */
	{ 5, 0xFF, 0x23, (uint16)(0), (uint16)(CYREG_PHUB_CH6_BASIC_CFG) },	/* TD 8 */
	{ 16, 0x0A, 0x22, (uint16)(0), (uint16)(CYREG_PRT0_DR) },	/* TD 9 */
	{ 64, 0x0B, 0x22, (uint16)(0), (uint16)(CYREG_PRT3_DR) },	/* TD 10 */
	{ 16, 0x0C, 0x22, (uint16)(0), (uint16)(CYREG_PRT12_DR) },	/* TD 11 */
	{ 16, 0xFF, 0x22, (uint16)(0), (uint16)(CYREG_PRT15_DR) },	/* TD 12 */
	{ 4095, 0x0E, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P0_U0_BASE) },	/* TD 13 */
	{ 1, 0x0F, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P7_ROUTE_BASE + 0x00000080 + 0x7F) },	/* TD 14 */
	{ 128, 0x10, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P3_U0_BASE) },	/* TD 15 */
	{ 896, 0x11, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P4_U0_BASE) },	/* TD 16 */
	{ 2304, 0x12, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_DSI0_BASE) },	/* TD 17 */
	{ 256, 0xFF, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_DSI12_BASE) },	/* TD 18 */
	{ 32, 0xFF, 0x23, (uint16)(0), (uint16)(CYDEV_UWRK_UWRK8_B1_BASE + 0x00000070) },	/* TD 19 */
	{ 128, 0x15, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P2_U0_BASE) },	/* TD 20 */
	{ 128, 0x16, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P2_U1_BASE) },	/* TD 21 */
	{ 128, 0x17, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P3_U1_BASE) },	/* TD 22 */
	{ 128, 0x18, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI13_BASE) },	/* TD 23 */
	{ 128, 0x19, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI13_BASE + 0x00000080) },	/* TD 24 */
	{ 128, 0x1A, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P5_ROUTE_BASE + 0x00000080) },	/* TD 25 */
	{ 128, 0x1B, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P2_ROUTE_BASE) },	/* TD 26 */
	{ 128, 0x1C, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P2_ROUTE_BASE + 0x00000080) },	/* TD 27 */
	{ 128, 0x1D, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P3_ROUTE_BASE) },	/* TD 28 */
	{ 128, 0x1E, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P3_ROUTE_BASE + 0x00000080) },	/* TD 29 */
	{ 128, 0x1F, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI9_BASE) },	/* TD 30 */
	{ 128, 0x20, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI9_BASE + 0x00000080) },	/* TD 31 */
	{ 16, 0xFF, 0x23, (uint16)(0), (uint16)(CYREG_BCTL1_MDCLK_EN) },	/* TD 32 */
};
/* Source addresses can be relocated, but only when in 32bit addresses.
   Because the standard TD table only has 16bit addresses, we generate a
   seperate table for the source addresses that does use 32bit addresses. This
   table will be remerged with the corresponding CFG_TD_LIST table during
   initialization. */
static const void * const CFG_TD_ADDR0[] = {
	(const void *)(&CH1_ADDR_DATA0),	/* TD 1 */
	(const void *)(&CH2_ADDR_DATA0),	/* TD 2 */
	(const void *)(&CH5_ADDR_DATA0),	/* TD 3 */
	(const void *)(&CH6_ADDR_DATA0),	/* TD 4 */
	(const void *)(&DMA_TD_START_CMD),	/* TD 5 */
	(const void *)(&DMA_TD_START_CMD),	/* TD 6 */
	(const void *)(&DMA_TD_START_CMD),	/* TD 7 */
	(const void *)(&DMA_TD_START_CMD),	/* TD 8 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 9 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 10 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 11 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 12 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 13 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 14 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 15 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 16 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 17 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 18 */
	(const void *)(BS_UWRK_B1_WRK_STATCTL_BITS_VAL),	/* TD 19 */
	(const void *)(BS_UDB_1_0_0_CONFIG_VAL),	/* TD 20 */
	(const void *)(BS_UDB_1_0_1_CONFIG_VAL),	/* TD 21 */
	(const void *)(BS_UDB_1_1_0_CONFIG_VAL),	/* TD 22 */
	(const void *)(BS_DSISWITCH_0_0_VAL),	/* TD 23 */
	(const void *)(BS_DSI0_0_HV_ROUTING_VAL),	/* TD 24 */
	(const void *)(BS_UDB_1_0_HV_ROUTING_VAL),	/* TD 25 */
	(const void *)(BS_UDBSWITCH_1_0_VAL),	/* TD 26 */
	(const void *)(BS_UDB_2_0_HV_ROUTING_VAL),	/* TD 27 */
	(const void *)(BS_UDBSWITCH_1_1_VAL),	/* TD 28 */
	(const void *)(BS_UDB_2_1_HV_ROUTING_VAL),	/* TD 29 */
	(const void *)(BS_DSISWITCH_1_0_VAL),	/* TD 30 */
	(const void *)(BS_DSI3_0_HV_ROUTING_VAL),	/* TD 31 */
	(const void *)(BS_UCFG_BCTL1_VAL),	/* TD 32 */
};
/*******************************************************************************
* Function Name: cfg_dma_init
********************************************************************************
* Summary:
*  This function is used to copy device configuration data from constant values
*  stored in memory into the proper chip configuration registers using DMA.  It
*  pulls data out of the CFG_TD_LISTs to know exactly how/what to configure.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/
static void cfg_dma_init(void)
{
	int i;

	DMA_ZERO_VAL = 0u;
	DMAC_CFGMEM[0].CFG0[0] = 0x10;		/* set burstcount */
	DMAC_CH[0].basic_cfg[0] = 0x01u;	/* enable channel0 */
	DMAC_CH[0].basic_status[1] = 0;		/* set channel0's first td to 0 */
	
	DMAC_TDMEM[0].TD0[2] = 0x01;		/* set td0's next td to 1 */
	DMAC_TDMEM[0].TD0[3] = 0x03;		/* set td0's flags */
	CY_SET_REG16((reg16 *) &DMAC_TDMEM[0].TD0[0], 32*8);					/* set td0's size */
	CY_SET_REG16((reg16 *) &DMAC_TDMEM[0].TD1[0], (uint16)(uint32)CFG_TD_LIST0);	/* set td0's src addr */
	CY_SET_REG16((reg16 *) &DMAC_TDMEM[0].TD1[2], CYDEV_PHUB_TDMEM1_BASE);	/* set td0's dst addr */
	CY_SET_REG16((reg16 *) &DMAC_CFGMEM[0].CFG1[0], (uint16)(CYDEV_FLASH_BASE >> 16));				/* set ch0's src high addr */
	CY_SET_REG16((reg16 *) &DMAC_CFGMEM[0].CFG1[2], (uint16)(CYDEV_PHUB_TDMEM1_BASE >> 16));				/* set ch0's dst high addr */
	DMAC_CH[1].basic_status[1] = 0x09; /* First TD = 9 */
	DMAC_CH[2].basic_status[1] = 0x0D; /* First TD = 13 */
	DMAC_CH[5].basic_status[1] = 0x13; /* First TD = 19 */
	DMAC_CH[6].basic_status[1] = 0x14; /* First TD = 20 */

	CY_CFG_MEMORY_BARRIER();
	DMAC_CH[0].action[0] = CPU_REQ;    /* initiate the DMA transfer */
	CY_CFG_MEMORY_BARRIER();

	/* Wait for TDs to be copied into TDMEM */
	while ((*(volatile uint16 *)(DMAC_TDMEM[0].TD0))) {}

	/* Recombine TD source table (CFG_TD_ADDR) with full TD table (CFG_TD_LIST) */
	for (i = 0; i < 32; i++)
	{
		volatile uint8 *srcAddrPtr = &DMAC_TDMEM[i+1].TD1[0];
		CY_SET_REG16(srcAddrPtr, (uint16)(uint32)CFG_TD_ADDR0[i]);
	}

	CY_CFG_MEMORY_BARRIER();
	DMAC_CH[0].action[0] = CPU_REQ;    /* initiate the DMA transfer */
	CY_CFG_MEMORY_BARRIER();

	/* Wait for all DMA transfers to complete */
	while((CY_GET_REG8(CYREG_PHUB_CH0_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH1_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH2_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH5_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH6_BASIC_STATUS) & 0x01u)){}

	/* DMA initialization is complete, disable all channels */
	CY_SET_REG8(CYREG_PHUB_CH0_BASIC_CFG, 0x00);
	CY_SET_REG8(CYREG_PHUB_CH1_BASIC_CFG, 0x00);
	CY_SET_REG8(CYREG_PHUB_CH2_BASIC_CFG, 0x00);
	CY_SET_REG8(CYREG_PHUB_CH5_BASIC_CFG, 0x00);
	CY_SET_REG8(CYREG_PHUB_CH6_BASIC_CFG, 0x00);

}
/*******************************************************************************
* Function Name: ClockSetup
********************************************************************************
*
* Summary:
*  Performs the initialization of all of the clocks in the device based on the
*  settings in the Clock tab of the DWR.  This includes enabling the requested
*  clocks and setting the necessary dividers to produce the desired frequency. 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void ClockSetup(void)
{
	reg32  timeout;
	reg32* timeout_p = &timeout;
	reg8   pllLock;


	/* Configure Digital Clocks based on settings from Clock DWR */
	CY_SET_XTND_REG24((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0), 0x180005);

	/* Configure ILO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_SLOWCLK_ILO_CR0), 0x02);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_CR), 0x08);

	/* Configure IMO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_FASTCLK_IMO_CR), 0x03);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_IMO_TR1), (CY_GET_XTND_REG8(CYREG_FLSHID_CUST_TABLES_IMO_3MHZ)));

	/* Configure PLL based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_P), 0x0008);
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_CFG0), 0x1051);
	/* Wait up to 250us for the PLL to lock */
	pllLock = 0;
	for (timeout = 250 / 10; *timeout_p && (pllLock != 0x03u); timeout--) { 
		pllLock = 0x03u & ((pllLock << 1) | ((CY_GET_XTND_REG8(CYREG_FASTCLK_PLL_SR) & 0x01u) >> 0));
		CyDelayCycles(10 * 12); /* Delay 10us based on 12MHz clock */
	}

	/* Configure Bus/Master Clock based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x0103);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x00);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x07);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG0), 0x00);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG2), 0x48);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x00);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_LD), 0x02);

	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PM_ACT_CFG2), ((CY_GET_XTND_REG8(CYREG_PM_ACT_CFG2) | 0x01)));
}


/* Analog API Functions */

/*******************************************************************************
* Function Name: AnalogSetDefault
********************************************************************************
*
* Summary:
*  Sets up the analog portions of the chip to default values based on chip
*  configuration options from the project.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AnalogSetDefault(void)
{
	CY_SET_XTND_REG16(CYREG_PM_ACT_CFG10, 0x0310);
	CY_SET_XTND_REG8(CYREG_DAC0_CR0, 0x1E);
	CY_SET_XTND_REG8(CYREG_DAC1_CR0, 0x1E);
	CY_SET_XTND_REG8(CYREG_DAC2_CR0, 0x1E);
	CY_SET_XTND_REG8(CYREG_DAC3_CR0, 0x1E);
	CY_SET_XTND_REG8(CYREG_SAR0_CSR0, 0xC0);
	CY_SET_XTND_REG8(CYREG_SAR0_CSR3, 0x0C);
	CY_SET_XTND_REG8(CYREG_SAR1_CSR0, 0xC0);
	CY_SET_XTND_REG8(CYREG_SAR1_CSR3, 0x0C);
	CY_SET_XTND_REG8(CYREG_PUMP_CR0, 0x44);
}

#define CY_AMUX_UNUSED CYREG_BOOST_SR


/*******************************************************************************
* Function Name: cyfitter_cfg
********************************************************************************
* Summary:
*  This function is called by the start-up code for the selected device. It
*  performs all of the necessary device configuration based on the design
*  settings.  This includes settings from the Design Wide Resources (DWR) such
*  as Clocks and Pins as well as any component configuration that is necessary.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/
void cyfitter_cfg(void)
{
#ifdef CYGlobalIntDisable
	/* Disable interrupts by default. Let user enable if/when they want. */
	CYGlobalIntDisable;
#endif

	/* Setup Flash Cycles based on 12MHz clock startup frequency. */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), ((CYDEV_INSTRUCT_CACHE_ENABLED) ? 0x40 : 0x41));

	/* Disable DMA channels so they can be configured for chip initialization */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PHUB_CH0_BASIC_CFG), 0x00);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PHUB_CH1_BASIC_CFG), 0x00);

	/* Enable analog pulldown switches */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_ANAIF_CFG_MISC_CR0), 0x01);

	/* Enable/Disable Debug functionality based on settings from System DWR */
	CY_SET_XTND_REG8(CYREG_MLOGIC_DBG_DBE, (CY_GET_XTND_REG8(CYREG_MLOGIC_DBG_DBE) | 0x01));

	{
		cfg_dma_init();

		/* Perform normal device configuration. Order is not critical for these items. */
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT0_BASE), 7);
		CYCONFIGCPY8((void CYFAR *)(CYDEV_PRTDSI_PRT1_BASE), (void CYFAR *)(BS_IOPORT_1_VAL), 7);
		CYCONFIGCPY8((void CYFAR *)(CYDEV_PRTDSI_PRT2_BASE), (void CYFAR *)(BS_IOPORT_2_VAL), 7);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT3_BASE), 7);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT4_BASE), 7);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT5_BASE), 7);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT6_BASE), 7);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT12_BASE), 6);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT15_BASE), 7);

		/* Enable digital routing */
		CY_SET_XTND_REG8(CYREG_BCTL0_BANK_CTL, CY_GET_XTND_REG8(CYREG_BCTL0_BANK_CTL) | 0x02u);
		CY_SET_XTND_REG8(CYREG_BCTL1_BANK_CTL, CY_GET_XTND_REG8(CYREG_BCTL1_BANK_CTL) | 0x02u);

		/* Enable UDB array */
		CY_SET_XTND_REG8(CYREG_PM_ACT_CFG0, CY_GET_XTND_REG8(CYREG_PM_ACT_CFG0) | 0x40u);
		CY_SET_XTND_REG8(CYREG_PM_AVAIL_CR2, CY_GET_XTND_REG8(CYREG_PM_AVAIL_CR2) | 0x10u);
	}

	/* Perform second pass device configuration. These items must be configured in specific order after the regular configuration is done. */
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT1_DM0), (void CYFAR *)(BS_IOPINS0_1_VAL), 8);
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT2_DM0), (void CYFAR *)(BS_IOPINS0_2_VAL), 8);


	/* Set Flash Cycles based on max possible frequency in case a glitch occurs during ClockSetup(). */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), ((CYDEV_INSTRUCT_CACHE_ENABLED) ? 0x00 : 0x01));
	/* Setup clocks based on selections from Clock DWR */
	ClockSetup();
	/* Set Flash Cycles based on newly configured 24.00MHz Bus Clock. */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), ((CYDEV_INSTRUCT_CACHE_ENABLED) ? 0x80 : 0x81));

	/* Perform basic analog initialization to defaults */
	AnalogSetDefault();

	/* Configure alternate active mode */
	CYCONFIGCPY((void CYFAR *)CYDEV_PM_STBY_BASE, (void CYFAR *)CYDEV_PM_ACT_BASE, 12);
	CY_SET_XTND_REG8(CYREG_PM_STBY_CFG0, CY_GET_XTND_REG8(CYREG_PM_STBY_CFG0) & ~0x02u);	/* Disable CPU */
}
