/*******************************************************************************
* FILENAME: cyfitter_cfg.c
* PSoC Creator 1.0 Service Pack 2
*
* Description:
* This file contains device initialization code. This file is automatically
* generated by PSoC Creator.
*
********************************************************************************
* Copyright 2010, Cypress Semiconductor Corporation.  All rights reserved.
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
*   void.
*
*
* Return:
*   void.
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

/* This file contains the data used to initialize the device. */

#undef CYCODE
#undef CYDATA
#undef CYXDATA
#undef CYFAR
#if defined(__C51__) || defined(__CX51__)
#define CYCODE code
#define CYDATA data
#define CYXDATA xdata
#define CYFAR far
extern void cymemzero(void CYFAR *addr, uint16 size);
extern void cyconfigcpy(uint16 size, const void CYFAR *src, void CYFAR *dest) small;
extern void cyconfigcpycode(uint16 size, const void CYCODE *src, void CYFAR *dest);
#define CYMEMZERO(a,c) cymemzero((a),(c))
#define CYCONFIGCPY(d,s,c) cyconfigcpy((c),(s),(d))
#define CYCONFIGCPYCODE(d,s,c) cyconfigcpycode((c),(s),(d))
#else
#define CYCODE
#define CYDATA
#define CYXDATA
#define CYFAR
#define CYMEMZERO(a,c) cymemset((a),0,(c))
#define CYCONFIGCPY(d,s,c) cymemcpy((d),(s),(c))
#define CYCONFIGCPYCODE(d,s,c) cymemcpy((d),(s),(c))
#endif

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
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
#else
/* Keil C51 and others */
#define CYPACKED
#define CYALIGNED
#define DMAINITSEC
#define CY_CFG_MEMORY_BARRIER()
#endif

typedef struct {
	void CYFAR *address;
	uint16 size;
} CYPACKED cfg_memset_t;

typedef struct {
	void CYFAR *dest;
	const void CYFAR *src;
	uint16 size;
} CYPACKED cfg_memcpy_t;

/* TD structure for little-endian systems
 * Does not require endian swap */
struct td_t {
	uint16 size;
	uint8 next_td_ptr;
	uint8 flags;
	uint16 src;
	uint16 dest;
} CYPACKED;


#if defined(__C51__) || defined(__CX51__)
#define CYMEMZERO8(a,c) cymemzero((a),(c))
#define CYCONFIGCPY8(d,s,c) cyconfigcpy((c),(s),(d))
#define CYCONFIGCPYCODE8(d,s,c) cyconfigcpycode((c),(s),(d))
#else
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
__attribute__ ((unused))
#endif
static void cymemzero8(void *addr, unsigned int count)
{
	volatile uint8 *addr8 = (uint8 *)addr;
	while (count--)
	{
		*addr8 = 0;
		addr8++;
	}
}

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
__attribute__ ((unused))
#endif
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
#endif

/* UDB_1_3_0_CONFIG Address: CYDEV_UCFG_B0_P2_U0_BASE Size (bytes): 128 */
#define BS_UDB_1_3_0_CONFIG_VAL ((const uint8 CYFAR *)0x48000000)

/* UDB_1_3_1_CONFIG Address: CYDEV_UCFG_B0_P2_U1_BASE Size (bytes): 128 */
#define BS_UDB_1_3_1_CONFIG_VAL ((const uint8 CYFAR *)0x48000080)

/* UDB_1_2_0_CONFIG Address: CYDEV_UCFG_B0_P3_U1_BASE Size (bytes): 128 */
#define BS_UDB_1_2_0_CONFIG_VAL ((const uint8 CYFAR *)0x48000100)

/* UDB_1_1_1_CONFIG Address: CYDEV_UCFG_B1_P3_U0_BASE Size (bytes): 128 */
#define BS_UDB_1_1_1_CONFIG_VAL ((const uint8 CYFAR *)0x48000180)

/* UDB_1_1_0_CONFIG Address: CYDEV_UCFG_B1_P3_U1_BASE Size (bytes): 128 */
#define BS_UDB_1_1_0_CONFIG_VAL ((const uint8 CYFAR *)0x48000200)

/* UWRK_B0_WRK_STATCTL_BITS Address: CYDEV_UWRK_UWRK8_B0_BASE + 0x00000070 Size (bytes): 32 */
#define BS_UWRK_B0_WRK_STATCTL_BITS_VAL ((const uint8 CYFAR *)0x48000280)

/* DSISWITCH_0_0 Address: CYDEV_UCFG_DSI13_BASE Size (bytes): 128 */
#define BS_DSISWITCH_0_0_VAL ((const uint8 CYFAR *)0x480002A0)

/* DSI0_0_HV_ROUTING Address: CYDEV_UCFG_DSI13_BASE + 0x00000080 Size (bytes): 128 */
#define BS_DSI0_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x48000320)

/* UDB_1_0_HV_ROUTING Address: CYDEV_UCFG_B1_P5_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_1_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480003A0)

/* UDB_2_0_HV_ROUTING Address: CYDEV_UCFG_B1_P2_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_2_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x48000420)

/* UDB_1_1_HV_ROUTING Address: CYDEV_UCFG_B1_P4_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_1_1_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480004A0)

/* UDBSWITCH_1_1 Address: CYDEV_UCFG_B1_P3_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_1_1_VAL ((const uint8 CYFAR *)0x48000520)

/* UDB_2_1_HV_ROUTING Address: CYDEV_UCFG_B1_P3_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_2_1_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480005A0)

/* UDBSWITCH_1_2 Address: CYDEV_UCFG_B0_P3_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_1_2_VAL ((const uint8 CYFAR *)0x48000620)

/* UDB_2_2_HV_ROUTING Address: CYDEV_UCFG_B0_P3_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_2_2_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480006A0)

/* UDBSWITCH_1_3 Address: CYDEV_UCFG_B0_P2_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_1_3_VAL ((const uint8 CYFAR *)0x48000720)

/* UDB_2_3_HV_ROUTING Address: CYDEV_UCFG_B0_P2_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_2_3_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480007A0)

/* DSISWITCH_1_0 Address: CYDEV_UCFG_DSI9_BASE Size (bytes): 128 */
#define BS_DSISWITCH_1_0_VAL ((const uint8 CYFAR *)0x48000820)

/* DSI3_0_HV_ROUTING Address: CYDEV_UCFG_DSI9_BASE + 0x00000080 Size (bytes): 128 */
#define BS_DSI3_0_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480008A0)

/* DSISWITCH_1_1 Address: CYDEV_UCFG_DSI8_BASE Size (bytes): 128 */
#define BS_DSISWITCH_1_1_VAL ((const uint8 CYFAR *)0x48000920)

/* DSI3_1_HV_ROUTING Address: CYDEV_UCFG_DSI8_BASE + 0x00000080 Size (bytes): 128 */
#define BS_DSI3_1_HV_ROUTING_VAL ((const uint8 CYFAR *)0x480009A0)

/* UCFG_BCTL1 Address: CYREG_BCTL1_MDCLK_EN Size (bytes): 16 */
#define BS_UCFG_BCTL1_VAL ((const uint8 CYFAR *)0x48000A20)

/* UCFG_BCTL0 Address: CYREG_BCTL0_MDCLK_EN Size (bytes): 16 */
#define BS_UCFG_BCTL0_VAL ((const uint8 CYFAR *)0x48000A30)

/* IOPINS0_1 Address: CYREG_PRT1_DM0 Size (bytes): 8 */
#define BS_IOPINS0_1_VAL ((const uint8 CYFAR *)0x48000A40)

/* IOPINS0_2 Address: CYREG_PRT2_DM0 Size (bytes): 8 */
#define BS_IOPINS0_2_VAL ((const uint8 CYFAR *)0x48000A48)

/* IOPORT_1 Address: CYDEV_PRTDSI_PRT1_BASE Size (bytes): 7 */
#define BS_IOPORT_1_VAL ((const uint8 CYFAR *)0x48000A50)

/* IOPORT_2 Address: CYDEV_PRTDSI_PRT2_BASE Size (bytes): 7 */
#define BS_IOPORT_2_VAL ((const uint8 CYFAR *)0x48000A58)


static const uint8 CYCODE CH1_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x40 };

static const uint8 CYCODE CH2_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x20, 0x01, 0x40 };

static const uint8 CYCODE CH5_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x40 };

static const uint8 CYCODE CH6_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x48, 0x01, 0x40 };

static const uint8 CYCODE DMA_TD_START_CMD[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x01 };

static uint32 CYXDATA DMA_ZERO_VAL CYALIGNED;

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
	{ 1024, 0x0E, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P0_U0_BASE) },	/* TD 13 */
	{ 128, 0x0F, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P3_U0_BASE) },	/* TD 14 */
	{ 2048, 0x10, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P4_U0_BASE) },	/* TD 15 */
	{ 384, 0x11, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P2_U0_BASE) },	/* TD 16 */
	{ 384, 0x12, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P4_U0_BASE) },	/* TD 17 */
	{ 384, 0x13, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P5_U0_BASE) },	/* TD 18 */
	{ 2048, 0x14, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_DSI0_BASE) },	/* TD 19 */
	{ 256, 0xFF, 0x22, (uint16)(0), (uint16)(CYDEV_UCFG_DSI12_BASE) },	/* TD 20 */
	{ 32, 0xFF, 0x23, (uint16)(0), (uint16)(CYDEV_UWRK_UWRK8_B0_BASE + 0x00000070) },	/* TD 21 */
	{ 128, 0x17, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P2_U0_BASE) },	/* TD 22 */
	{ 128, 0x18, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P2_U1_BASE) },	/* TD 23 */
	{ 128, 0x19, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P3_U1_BASE) },	/* TD 24 */
	{ 128, 0x1A, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P3_U0_BASE) },	/* TD 25 */
	{ 128, 0x1B, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P3_U1_BASE) },	/* TD 26 */
	{ 128, 0x1C, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI13_BASE) },	/* TD 27 */
	{ 128, 0x1D, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI13_BASE + 0x00000080) },	/* TD 28 */
	{ 128, 0x1E, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P5_ROUTE_BASE + 0x00000080) },	/* TD 29 */
	{ 128, 0x1F, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P2_ROUTE_BASE + 0x00000080) },	/* TD 30 */
	{ 128, 0x20, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P4_ROUTE_BASE + 0x00000080) },	/* TD 31 */
	{ 128, 0x21, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P3_ROUTE_BASE) },	/* TD 32 */
	{ 128, 0x22, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B1_P3_ROUTE_BASE + 0x00000080) },	/* TD 33 */
	{ 128, 0x23, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P3_ROUTE_BASE) },	/* TD 34 */
	{ 128, 0x24, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P3_ROUTE_BASE + 0x00000080) },	/* TD 35 */
	{ 128, 0x25, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P2_ROUTE_BASE) },	/* TD 36 */
	{ 128, 0x26, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_B0_P2_ROUTE_BASE + 0x00000080) },	/* TD 37 */
	{ 128, 0x27, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI9_BASE) },	/* TD 38 */
	{ 128, 0x28, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI9_BASE + 0x00000080) },	/* TD 39 */
	{ 128, 0x29, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI8_BASE) },	/* TD 40 */
	{ 128, 0x2A, 0x23, (uint16)(0), (uint16)(CYDEV_UCFG_DSI8_BASE + 0x00000080) },	/* TD 41 */
	{ 16, 0x2B, 0x23, (uint16)(0), (uint16)(CYREG_BCTL1_MDCLK_EN) },	/* TD 42 */
	{ 16, 0xFF, 0x23, (uint16)(0), (uint16)(CYREG_BCTL0_MDCLK_EN) },	/* TD 43 */
};
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
	(const void *)(&DMA_ZERO_VAL),	/* TD 19 */
	(const void *)(&DMA_ZERO_VAL),	/* TD 20 */
	(const void *)(BS_UWRK_B0_WRK_STATCTL_BITS_VAL),	/* TD 21 */
	(const void *)(BS_UDB_1_3_0_CONFIG_VAL),	/* TD 22 */
	(const void *)(BS_UDB_1_3_1_CONFIG_VAL),	/* TD 23 */
	(const void *)(BS_UDB_1_2_0_CONFIG_VAL),	/* TD 24 */
	(const void *)(BS_UDB_1_1_1_CONFIG_VAL),	/* TD 25 */
	(const void *)(BS_UDB_1_1_0_CONFIG_VAL),	/* TD 26 */
	(const void *)(BS_DSISWITCH_0_0_VAL),	/* TD 27 */
	(const void *)(BS_DSI0_0_HV_ROUTING_VAL),	/* TD 28 */
	(const void *)(BS_UDB_1_0_HV_ROUTING_VAL),	/* TD 29 */
	(const void *)(BS_UDB_2_0_HV_ROUTING_VAL),	/* TD 30 */
	(const void *)(BS_UDB_1_1_HV_ROUTING_VAL),	/* TD 31 */
	(const void *)(BS_UDBSWITCH_1_1_VAL),	/* TD 32 */
	(const void *)(BS_UDB_2_1_HV_ROUTING_VAL),	/* TD 33 */
	(const void *)(BS_UDBSWITCH_1_2_VAL),	/* TD 34 */
	(const void *)(BS_UDB_2_2_HV_ROUTING_VAL),	/* TD 35 */
	(const void *)(BS_UDBSWITCH_1_3_VAL),	/* TD 36 */
	(const void *)(BS_UDB_2_3_HV_ROUTING_VAL),	/* TD 37 */
	(const void *)(BS_DSISWITCH_1_0_VAL),	/* TD 38 */
	(const void *)(BS_DSI3_0_HV_ROUTING_VAL),	/* TD 39 */
	(const void *)(BS_DSISWITCH_1_1_VAL),	/* TD 40 */
	(const void *)(BS_DSI3_1_HV_ROUTING_VAL),	/* TD 41 */
	(const void *)(BS_UCFG_BCTL1_VAL),	/* TD 42 */
	(const void *)(BS_UCFG_BCTL0_VAL),	/* TD 43 */
};
static void cfg_dma_init(void)
{
	int i;

	DMA_ZERO_VAL = 0u;
	DMAC_CFGMEM[0].CFG0[0] = 0x10;		/* set burstcount */
	DMAC_CH[0].basic_cfg[0] = 0x01u;	/* enable channel0 */
	DMAC_CH[0].basic_status[1] = 0;		/* set channel0's first td to 0 */
	
	DMAC_TDMEM[0].TD0[2] = 0x01;		/* set td0's next td to 1 */
	DMAC_TDMEM[0].TD0[3] = 0x03;		/* set td0's flags */
	CY_SET_REG16((reg16 *) &DMAC_TDMEM[0].TD0[0], 43*8);					/* set td0's size */
	CY_SET_REG16((reg16 *) &DMAC_TDMEM[0].TD1[0], (uint16)(uint32)CFG_TD_LIST0);	/* set td0's src addr */
	CY_SET_REG16((reg16 *) &DMAC_TDMEM[0].TD1[2], CYDEV_PHUB_TDMEM1_BASE);	/* set td0's dst addr */
	CY_SET_REG16((reg16 *) &DMAC_CFGMEM[0].CFG1[0], (uint16)(CYDEV_FLASH_BASE >> 16));				/* set ch0's src high addr */
	CY_SET_REG16((reg16 *) &DMAC_CFGMEM[0].CFG1[2], (uint16)(CYDEV_PHUB_TDMEM1_BASE >> 16));				/* set ch0's dst high addr */
	DMAC_CH[1].basic_status[1] = 0x09;
	DMAC_CH[2].basic_status[1] = 0x0D;
	DMAC_CH[5].basic_status[1] = 0x15;
	DMAC_CH[6].basic_status[1] = 0x16;

	CY_CFG_MEMORY_BARRIER();
	DMAC_CH[0].action[0] = CPU_REQ;    /* initiate the DMA transfer */
	CY_CFG_MEMORY_BARRIER();

	while ((*(volatile uint16 *)(DMAC_TDMEM[0].TD0))) {}

	for (i = 0; i < 43; i++)
	{
		volatile uint8 *srcAddrPtr = &DMAC_TDMEM[i+1].TD1[0];
		CY_SET_REG16(srcAddrPtr, (uint16)(uint32)CFG_TD_ADDR0[i]);
	}

	CY_CFG_MEMORY_BARRIER();
	DMAC_CH[0].action[0] = CPU_REQ;    /* initiate the DMA transfer */
	CY_CFG_MEMORY_BARRIER();

	while((CY_GET_REG8(CYREG_PHUB_CH0_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH1_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH2_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH5_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH6_BASIC_STATUS) & 0x01u)){}

	CY_SET_REG8(CYREG_PHUB_CH0_BASIC_CFG, 0x00);
	CY_SET_REG8(CYREG_PHUB_CH1_BASIC_CFG, 0x00);
	CY_SET_REG8(CYREG_PHUB_CH2_BASIC_CFG, 0x00);
	CY_SET_REG8(CYREG_PHUB_CH5_BASIC_CFG, 0x00);
	CY_SET_REG8(CYREG_PHUB_CH6_BASIC_CFG, 0x00);

}
static void ClockSetup(void)
{
	reg32  timeout;
	reg32* timeout_p = &timeout;
	reg8   pllLock;

	CY_SET_XTND_REG24((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0), 0x180005);
	CY_SET_XTND_REG24((void CYFAR *)(CYREG_CLKDIST_DCFG1_CFG0), 0x180033);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_SLOWCLK_ILO_CR0), 0x02);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_CR), 0x08);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_FASTCLK_IMO_CR), 0x03);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_IMO_TR1), (CY_GET_XTND_REG8(CYREG_FLSHID_CUST_TABLES_IMO_3MHZ)));
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_P), 0x0008);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_CR), 0x08);
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_CFG0), 0x1051);
	pllLock = 0;
	for (timeout = 1216; *timeout_p && (pllLock != 0x03u); timeout--) { pllLock = 0x03u & ((pllLock << 1) | ((CY_GET_XTND_REG8(CYREG_FASTCLK_PLL_SR) & 0x01u) >> 0)); }
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x0103);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x00);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x07);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG0), 0x00);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG2), 0x48);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x00);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_LD), 0x02);

	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PM_ACT_CFG2), ((CY_GET_XTND_REG8(CYREG_PM_ACT_CFG2) | 0x03)));
}

/* Analog API Functions */
void AnalogSetDefault(void)
{
	CY_SET_XTND_REG8(CYREG_PUMP_CR0, 0x44);
}

#define CY_AMUX_UNUSED CYREG_BOOST_SR

/* This function is called by the start-up code for the selected device. */
void cyfitter_cfg(void)
{
#ifdef CYGlobalIntDisable
	CYGlobalIntDisable;
#endif

	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), ((CYDEV_INSTRUCT_CACHE_ENABLED) ? 0xC0 : 0xC1));
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PHUB_CH0_BASIC_CFG), 0x00);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PHUB_CH1_BASIC_CFG), 0x00);

	CY_SET_XTND_REG8((void CYFAR *)(CYREG_ANAIF_CFG_MISC_CR0), 0x01);

	CY_SET_XTND_REG8(CYREG_MLOGIC_DBG_DBE, (CY_GET_XTND_REG8(CYREG_MLOGIC_DBG_DBE) | 0x01));
	cfg_dma_init();

	CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT0_BASE), 7);
	CYCONFIGCPY8((void CYFAR *)(CYDEV_PRTDSI_PRT1_BASE), (void CYFAR *)(BS_IOPORT_1_VAL), 7);
	CYCONFIGCPY8((void CYFAR *)(CYDEV_PRTDSI_PRT2_BASE), (void CYFAR *)(BS_IOPORT_2_VAL), 7);
	CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT3_BASE), 7);
	CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT4_BASE), 7);
	CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT5_BASE), 7);
	CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT6_BASE), 7);
	CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT12_BASE), 6);
	CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT15_BASE), 7);
	/* BYTES WRITTEN: 62 */

	/* Enable digital routing */
	CY_SET_XTND_REG8(CYREG_BCTL0_BANK_CTL, CY_GET_XTND_REG8(CYREG_BCTL0_BANK_CTL) | 0x02u);
	CY_SET_XTND_REG8(CYREG_BCTL1_BANK_CTL, CY_GET_XTND_REG8(CYREG_BCTL1_BANK_CTL) | 0x02u);

	/* Enable UDB array */
	CY_SET_XTND_REG8(CYREG_PM_ACT_CFG0, CY_GET_XTND_REG8(CYREG_PM_ACT_CFG0) | 0x40u);
	CY_SET_XTND_REG8(CYREG_PM_AVAIL_CR2, CY_GET_XTND_REG8(CYREG_PM_AVAIL_CR2) | 0x10u);

	CYCONFIGCPY((void CYFAR *)(CYREG_PRT1_DM0), (void CYFAR *)(BS_IOPINS0_1_VAL), 8);
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT2_DM0), (void CYFAR *)(BS_IOPINS0_2_VAL), 8);
	/* BYTES WRITTEN: 16 */

	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), ((CYDEV_INSTRUCT_CACHE_ENABLED) ? 0x00 : 0x01));
	ClockSetup();
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), ((CYDEV_INSTRUCT_CACHE_ENABLED) ? 0x80 : 0x81));

	AnalogSetDefault();

	/* Configure alternate active mode */
	CYCONFIGCPY((void CYFAR *)CYDEV_PM_STBY_BASE, (void CYFAR *)CYDEV_PM_ACT_BASE, 12);
	CY_SET_XTND_REG8(CYREG_PM_STBY_CFG0, CY_GET_XTND_REG8(CYREG_PM_STBY_CFG0) & ~0x02u);	/* Disable CPU */
}
