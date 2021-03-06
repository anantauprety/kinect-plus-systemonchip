#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include <cydevice.h>
#include <cydevice_trm.h>

/* CapSense_CompCH0_ctComp */
#define CapSense_CompCH0_ctComp__CLK CYREG_CMP0_CLK
#define CapSense_CompCH0_ctComp__CMP_MASK 0x01u
#define CapSense_CompCH0_ctComp__CMP_NUMBER 0
#define CapSense_CompCH0_ctComp__CR CYREG_CMP0_CR
#define CapSense_CompCH0_ctComp__LUT__CR CYREG_LUT0_CR
#define CapSense_CompCH0_ctComp__LUT__MSK CYREG_LUT_MSK
#define CapSense_CompCH0_ctComp__LUT__MSK_MASK 0x01u
#define CapSense_CompCH0_ctComp__LUT__MSK_SHIFT 0
#define CapSense_CompCH0_ctComp__LUT__MX CYREG_LUT0_MX
#define CapSense_CompCH0_ctComp__LUT__SR CYREG_LUT_SR
#define CapSense_CompCH0_ctComp__LUT__SR_MASK 0x01u
#define CapSense_CompCH0_ctComp__LUT__SR_SHIFT 0
#define CapSense_CompCH0_ctComp__PM_ACT_CFG CYREG_PM_ACT_CFG7
#define CapSense_CompCH0_ctComp__PM_ACT_MSK 0x01u
#define CapSense_CompCH0_ctComp__PM_STBY_CFG CYREG_PM_STBY_CFG7
#define CapSense_CompCH0_ctComp__PM_STBY_MSK 0x01u
#define CapSense_CompCH0_ctComp__SW0 CYREG_CMP0_SW0
#define CapSense_CompCH0_ctComp__SW2 CYREG_CMP0_SW2
#define CapSense_CompCH0_ctComp__SW3 CYREG_CMP0_SW3
#define CapSense_CompCH0_ctComp__SW4 CYREG_CMP0_SW4
#define CapSense_CompCH0_ctComp__SW6 CYREG_CMP0_SW6
#define CapSense_CompCH0_ctComp__TR CYREG_CMP0_TR
#define CapSense_CompCH0_ctComp__TRIM__TR0 CYREG_FLSHID_MFG_CFG_CMP0_TR0
#define CapSense_CompCH0_ctComp__TRIM__TR0_HS CYREG_FLSHID_CUST_TABLES_CMP0_TR0_HS
#define CapSense_CompCH0_ctComp__WRK CYREG_CMP_WRK
#define CapSense_CompCH0_ctComp__WRK_MASK 0x01u
#define CapSense_CompCH0_ctComp__WRK_SHIFT 0

/* CapSense_MeasureCH0 */
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_A0_REG CYREG_B1_UDB08_09_A0
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_A1_REG CYREG_B1_UDB08_09_A1
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_D0_REG CYREG_B1_UDB08_09_D0
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_D1_REG CYREG_B1_UDB08_09_D1
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB08_09_ACTL
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_F0_REG CYREG_B1_UDB08_09_F0
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_F1_REG CYREG_B1_UDB08_09_F1
#define CapSense_MeasureCH0_UDB_Counter_u0__A0_A1_REG CYREG_B1_UDB08_A0_A1
#define CapSense_MeasureCH0_UDB_Counter_u0__A0_REG CYREG_B1_UDB08_A0
#define CapSense_MeasureCH0_UDB_Counter_u0__A1_REG CYREG_B1_UDB08_A1
#define CapSense_MeasureCH0_UDB_Counter_u0__D0_D1_REG CYREG_B1_UDB08_D0_D1
#define CapSense_MeasureCH0_UDB_Counter_u0__D0_REG CYREG_B1_UDB08_D0
#define CapSense_MeasureCH0_UDB_Counter_u0__D1_REG CYREG_B1_UDB08_D1
#define CapSense_MeasureCH0_UDB_Counter_u0__DP_AUX_CTL_REG CYREG_B1_UDB08_ACTL
#define CapSense_MeasureCH0_UDB_Counter_u0__F0_F1_REG CYREG_B1_UDB08_F0_F1
#define CapSense_MeasureCH0_UDB_Counter_u0__F0_REG CYREG_B1_UDB08_F0
#define CapSense_MeasureCH0_UDB_Counter_u0__F1_REG CYREG_B1_UDB08_F1
#define CapSense_MeasureCH0_UDB_Window_u0__A0_A1_REG CYREG_B1_UDB11_A0_A1
#define CapSense_MeasureCH0_UDB_Window_u0__A0_REG CYREG_B1_UDB11_A0
#define CapSense_MeasureCH0_UDB_Window_u0__A1_REG CYREG_B1_UDB11_A1
#define CapSense_MeasureCH0_UDB_Window_u0__D0_D1_REG CYREG_B1_UDB11_D0_D1
#define CapSense_MeasureCH0_UDB_Window_u0__D0_REG CYREG_B1_UDB11_D0
#define CapSense_MeasureCH0_UDB_Window_u0__D1_REG CYREG_B1_UDB11_D1
#define CapSense_MeasureCH0_UDB_Window_u0__DP_AUX_CTL_REG CYREG_B1_UDB11_ACTL
#define CapSense_MeasureCH0_UDB_Window_u0__F0_F1_REG CYREG_B1_UDB11_F0_F1
#define CapSense_MeasureCH0_UDB_Window_u0__F0_REG CYREG_B1_UDB11_F0
#define CapSense_MeasureCH0_UDB_Window_u0__F1_REG CYREG_B1_UDB11_F1

/* CapSense_ClockGen */
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__0__MASK 0x01u
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__0__POS 0
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__1__MASK 0x02u
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__1__POS 1
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB09_10_CTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB09_10_CTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__16BIT_MASK_MASK_REG CYREG_B0_UDB09_10_MSK
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB09_10_MSK
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__2__MASK 0x04u
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__2__POS 2
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__CONTROL_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__CONTROL_REG CYREG_B0_UDB09_CTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__CONTROL_ST_REG CYREG_B0_UDB09_ST_CTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__COUNT_REG CYREG_B0_UDB09_CTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__COUNT_ST_REG CYREG_B0_UDB09_ST_CTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__MASK 0x07u
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define CapSense_ClockGen_AsyncCtrl_CtrlReg__PERIOD_REG CYREG_B0_UDB09_MSK
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_A0_REG CYREG_B0_UDB08_09_A0
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_A1_REG CYREG_B0_UDB08_09_A1
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_D0_REG CYREG_B0_UDB08_09_D0
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_D1_REG CYREG_B0_UDB08_09_D1
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB08_09_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_F0_REG CYREG_B0_UDB08_09_F0
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_F1_REG CYREG_B0_UDB08_09_F1
#define CapSense_ClockGen_sC16_PRSdp_u0__A0_A1_REG CYREG_B0_UDB08_A0_A1
#define CapSense_ClockGen_sC16_PRSdp_u0__A0_REG CYREG_B0_UDB08_A0
#define CapSense_ClockGen_sC16_PRSdp_u0__A1_REG CYREG_B0_UDB08_A1
#define CapSense_ClockGen_sC16_PRSdp_u0__D0_D1_REG CYREG_B0_UDB08_D0_D1
#define CapSense_ClockGen_sC16_PRSdp_u0__D0_REG CYREG_B0_UDB08_D0
#define CapSense_ClockGen_sC16_PRSdp_u0__D1_REG CYREG_B0_UDB08_D1
#define CapSense_ClockGen_sC16_PRSdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB08_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u0__F0_F1_REG CYREG_B0_UDB08_F0_F1
#define CapSense_ClockGen_sC16_PRSdp_u0__F0_REG CYREG_B0_UDB08_F0
#define CapSense_ClockGen_sC16_PRSdp_u0__F1_REG CYREG_B0_UDB08_F1
#define CapSense_ClockGen_sC16_PRSdp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_A0_REG CYREG_B0_UDB09_10_A0
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_A1_REG CYREG_B0_UDB09_10_A1
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_D0_REG CYREG_B0_UDB09_10_D0
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_D1_REG CYREG_B0_UDB09_10_D1
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_F0_REG CYREG_B0_UDB09_10_F0
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_F1_REG CYREG_B0_UDB09_10_F1
#define CapSense_ClockGen_sC16_PRSdp_u1__A0_A1_REG CYREG_B0_UDB09_A0_A1
#define CapSense_ClockGen_sC16_PRSdp_u1__A0_REG CYREG_B0_UDB09_A0
#define CapSense_ClockGen_sC16_PRSdp_u1__A1_REG CYREG_B0_UDB09_A1
#define CapSense_ClockGen_sC16_PRSdp_u1__D0_D1_REG CYREG_B0_UDB09_D0_D1
#define CapSense_ClockGen_sC16_PRSdp_u1__D0_REG CYREG_B0_UDB09_D0
#define CapSense_ClockGen_sC16_PRSdp_u1__D1_REG CYREG_B0_UDB09_D1
#define CapSense_ClockGen_sC16_PRSdp_u1__DP_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u1__F0_F1_REG CYREG_B0_UDB09_F0_F1
#define CapSense_ClockGen_sC16_PRSdp_u1__F0_REG CYREG_B0_UDB09_F0
#define CapSense_ClockGen_sC16_PRSdp_u1__F1_REG CYREG_B0_UDB09_F1
#define CapSense_ClockGen_sC16_PRSdp_u1__MSK_DP_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u1__PER_DP_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define CapSense_ClockGen_ScanSpeed__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB08_09_ACTL
#define CapSense_ClockGen_ScanSpeed__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB08_09_CTL
#define CapSense_ClockGen_ScanSpeed__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB08_09_CTL
#define CapSense_ClockGen_ScanSpeed__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB08_09_CTL
#define CapSense_ClockGen_ScanSpeed__16BIT_COUNT_COUNT_REG CYREG_B0_UDB08_09_CTL
#define CapSense_ClockGen_ScanSpeed__16BIT_MASK_MASK_REG CYREG_B0_UDB08_09_MSK
#define CapSense_ClockGen_ScanSpeed__16BIT_MASK_PERIOD_REG CYREG_B0_UDB08_09_MSK
#define CapSense_ClockGen_ScanSpeed__16BIT_PERIOD_MASK_REG CYREG_B0_UDB08_09_MSK
#define CapSense_ClockGen_ScanSpeed__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB08_09_MSK
#define CapSense_ClockGen_ScanSpeed__CONTROL_AUX_CTL_REG CYREG_B0_UDB08_ACTL
#define CapSense_ClockGen_ScanSpeed__CONTROL_REG CYREG_B0_UDB08_CTL
#define CapSense_ClockGen_ScanSpeed__CONTROL_ST_REG CYREG_B0_UDB08_ST_CTL
#define CapSense_ClockGen_ScanSpeed__COUNT_REG CYREG_B0_UDB08_CTL
#define CapSense_ClockGen_ScanSpeed__COUNT_ST_REG CYREG_B0_UDB08_ST_CTL
#define CapSense_ClockGen_ScanSpeed__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define CapSense_ClockGen_ScanSpeed__PER_CTL_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define CapSense_ClockGen_ScanSpeed__PERIOD_REG CYREG_B0_UDB08_MSK
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_A0_REG CYREG_B1_UDB09_10_A0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_A1_REG CYREG_B1_UDB09_10_A1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_D0_REG CYREG_B1_UDB09_10_D0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_D1_REG CYREG_B1_UDB09_10_D1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB09_10_ACTL
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_F0_REG CYREG_B1_UDB09_10_F0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_F1_REG CYREG_B1_UDB09_10_F1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__A0_A1_REG CYREG_B1_UDB09_A0_A1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__A0_REG CYREG_B1_UDB09_A0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__A1_REG CYREG_B1_UDB09_A1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__D0_D1_REG CYREG_B1_UDB09_D0_D1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__D0_REG CYREG_B1_UDB09_D0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__D1_REG CYREG_B1_UDB09_D1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__DP_AUX_CTL_REG CYREG_B1_UDB09_ACTL
#define CapSense_ClockGen_UDB_PrescalerDp_u0__F0_F1_REG CYREG_B1_UDB09_F0_F1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__F0_REG CYREG_B1_UDB09_F0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__F1_REG CYREG_B1_UDB09_F1

/* CapSense_IntClock */
#define CapSense_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define CapSense_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define CapSense_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define CapSense_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define CapSense_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define CapSense_IntClock__PM_ACT_MSK 0x01u
#define CapSense_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define CapSense_IntClock__PM_STBY_MSK 0x01u

/* CapSense_CmodCH0 */
#define CapSense_CmodCH0__0__MASK 0x20u
#define CapSense_CmodCH0__0__PC CYREG_PRT15_PC5
#define CapSense_CmodCH0__0__PORT 15
#define CapSense_CmodCH0__0__SHIFT 5
#define CapSense_CmodCH0__AG CYREG_PRT15_AG
#define CapSense_CmodCH0__AMUX CYREG_PRT15_AMUX
#define CapSense_CmodCH0__BIE CYREG_PRT15_BIE
#define CapSense_CmodCH0__BIT_MASK CYREG_PRT15_BIT_MASK
#define CapSense_CmodCH0__BYP CYREG_PRT15_BYP
#define CapSense_CmodCH0__Cmod_CH0__MASK 0x20u
#define CapSense_CmodCH0__Cmod_CH0__PC CYREG_PRT15_PC5
#define CapSense_CmodCH0__Cmod_CH0__PORT 15
#define CapSense_CmodCH0__Cmod_CH0__SHIFT 5
#define CapSense_CmodCH0__CTL CYREG_PRT15_CTL
#define CapSense_CmodCH0__DM0 CYREG_PRT15_DM0
#define CapSense_CmodCH0__DM1 CYREG_PRT15_DM1
#define CapSense_CmodCH0__DM2 CYREG_PRT15_DM2
#define CapSense_CmodCH0__DR CYREG_PRT15_DR
#define CapSense_CmodCH0__INP_DIS CYREG_PRT15_INP_DIS
#define CapSense_CmodCH0__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define CapSense_CmodCH0__LCD_EN CYREG_PRT15_LCD_EN
#define CapSense_CmodCH0__PORT 15
#define CapSense_CmodCH0__PRT CYREG_PRT15_PRT
#define CapSense_CmodCH0__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define CapSense_CmodCH0__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define CapSense_CmodCH0__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define CapSense_CmodCH0__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define CapSense_CmodCH0__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define CapSense_CmodCH0__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define CapSense_CmodCH0__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define CapSense_CmodCH0__PS CYREG_PRT15_PS
#define CapSense_CmodCH0__SLW CYREG_PRT15_SLW

/* CapSense_IdacCH0 */
#define CapSense_IdacCH0__CR0 CYREG_DAC0_CR0
#define CapSense_IdacCH0__CR1 CYREG_DAC0_CR1
#define CapSense_IdacCH0__D CYREG_DAC0_D
#define CapSense_IdacCH0__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define CapSense_IdacCH0__PM_ACT_MSK 0x01u
#define CapSense_IdacCH0__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define CapSense_IdacCH0__PM_STBY_MSK 0x01u
#define CapSense_IdacCH0__STROBE CYREG_DAC0_STROBE
#define CapSense_IdacCH0__SW0 CYREG_DAC0_SW0
#define CapSense_IdacCH0__SW2 CYREG_DAC0_SW2
#define CapSense_IdacCH0__SW3 CYREG_DAC0_SW3
#define CapSense_IdacCH0__SW4 CYREG_DAC0_SW4
#define CapSense_IdacCH0__TR CYREG_DAC0_TR
#define CapSense_IdacCH0__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC0_M1
#define CapSense_IdacCH0__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC0_M2
#define CapSense_IdacCH0__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC0_M3
#define CapSense_IdacCH0__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC0_M4
#define CapSense_IdacCH0__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC0_M5
#define CapSense_IdacCH0__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC0_M6
#define CapSense_IdacCH0__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC0_M7
#define CapSense_IdacCH0__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC0_M8
#define CapSense_IdacCH0__TRIM__TR CYREG_FLSHID_MFG_CFG_DAC0_TR
#define CapSense_IdacCH0__TST CYREG_DAC0_TST

/* CapSense_PortCH0 */
#define CapSense_PortCH0__0__MASK 0x20u
#define CapSense_PortCH0__0__PC CYREG_PRT0_PC5
#define CapSense_PortCH0__0__PORT 0
#define CapSense_PortCH0__0__SHIFT 5
#define CapSense_PortCH0__1__MASK 0x40u
#define CapSense_PortCH0__1__PC CYREG_PRT0_PC6
#define CapSense_PortCH0__1__PORT 0
#define CapSense_PortCH0__1__SHIFT 6
#define CapSense_PortCH0__2__MASK 0x01u
#define CapSense_PortCH0__2__PC CYREG_PRT0_PC0
#define CapSense_PortCH0__2__PORT 0
#define CapSense_PortCH0__2__SHIFT 0
#define CapSense_PortCH0__3__MASK 0x02u
#define CapSense_PortCH0__3__PC CYREG_PRT0_PC1
#define CapSense_PortCH0__3__PORT 0
#define CapSense_PortCH0__3__SHIFT 1
#define CapSense_PortCH0__4__MASK 0x04u
#define CapSense_PortCH0__4__PC CYREG_PRT0_PC2
#define CapSense_PortCH0__4__PORT 0
#define CapSense_PortCH0__4__SHIFT 2
#define CapSense_PortCH0__5__MASK 0x08u
#define CapSense_PortCH0__5__PC CYREG_PRT0_PC3
#define CapSense_PortCH0__5__PORT 0
#define CapSense_PortCH0__5__SHIFT 3
#define CapSense_PortCH0__6__MASK 0x10u
#define CapSense_PortCH0__6__PC CYREG_PRT0_PC4
#define CapSense_PortCH0__6__PORT 0
#define CapSense_PortCH0__6__SHIFT 4
#define CapSense_PortCH0__AG CYREG_PRT0_AG
#define CapSense_PortCH0__AMUX CYREG_PRT0_AMUX
#define CapSense_PortCH0__BIE CYREG_PRT0_BIE
#define CapSense_PortCH0__BIT_MASK CYREG_PRT0_BIT_MASK
#define CapSense_PortCH0__Button0__BTN__MASK 0x20u
#define CapSense_PortCH0__Button0__BTN__PC CYREG_PRT0_PC5
#define CapSense_PortCH0__Button0__BTN__PORT 0
#define CapSense_PortCH0__Button0__BTN__SHIFT 5
#define CapSense_PortCH0__Button1__BTN__MASK 0x40u
#define CapSense_PortCH0__Button1__BTN__PC CYREG_PRT0_PC6
#define CapSense_PortCH0__Button1__BTN__PORT 0
#define CapSense_PortCH0__Button1__BTN__SHIFT 6
#define CapSense_PortCH0__BYP CYREG_PRT0_BYP
#define CapSense_PortCH0__CTL CYREG_PRT0_CTL
#define CapSense_PortCH0__DM0 CYREG_PRT0_DM0
#define CapSense_PortCH0__DM1 CYREG_PRT0_DM1
#define CapSense_PortCH0__DM2 CYREG_PRT0_DM2
#define CapSense_PortCH0__DR CYREG_PRT0_DR
#define CapSense_PortCH0__INP_DIS CYREG_PRT0_INP_DIS
#define CapSense_PortCH0__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define CapSense_PortCH0__LCD_EN CYREG_PRT0_LCD_EN
#define CapSense_PortCH0__LinearSlider0_e0__LS__MASK 0x01u
#define CapSense_PortCH0__LinearSlider0_e0__LS__PC CYREG_PRT0_PC0
#define CapSense_PortCH0__LinearSlider0_e0__LS__PORT 0
#define CapSense_PortCH0__LinearSlider0_e0__LS__SHIFT 0
#define CapSense_PortCH0__LinearSlider0_e1__LS__MASK 0x02u
#define CapSense_PortCH0__LinearSlider0_e1__LS__PC CYREG_PRT0_PC1
#define CapSense_PortCH0__LinearSlider0_e1__LS__PORT 0
#define CapSense_PortCH0__LinearSlider0_e1__LS__SHIFT 1
#define CapSense_PortCH0__LinearSlider0_e2__LS__MASK 0x04u
#define CapSense_PortCH0__LinearSlider0_e2__LS__PC CYREG_PRT0_PC2
#define CapSense_PortCH0__LinearSlider0_e2__LS__PORT 0
#define CapSense_PortCH0__LinearSlider0_e2__LS__SHIFT 2
#define CapSense_PortCH0__LinearSlider0_e3__LS__MASK 0x08u
#define CapSense_PortCH0__LinearSlider0_e3__LS__PC CYREG_PRT0_PC3
#define CapSense_PortCH0__LinearSlider0_e3__LS__PORT 0
#define CapSense_PortCH0__LinearSlider0_e3__LS__SHIFT 3
#define CapSense_PortCH0__LinearSlider0_e4__LS__MASK 0x10u
#define CapSense_PortCH0__LinearSlider0_e4__LS__PC CYREG_PRT0_PC4
#define CapSense_PortCH0__LinearSlider0_e4__LS__PORT 0
#define CapSense_PortCH0__LinearSlider0_e4__LS__SHIFT 4
#define CapSense_PortCH0__PORT 0
#define CapSense_PortCH0__PRT CYREG_PRT0_PRT
#define CapSense_PortCH0__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define CapSense_PortCH0__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define CapSense_PortCH0__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define CapSense_PortCH0__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define CapSense_PortCH0__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define CapSense_PortCH0__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define CapSense_PortCH0__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define CapSense_PortCH0__PS CYREG_PRT0_PS
#define CapSense_PortCH0__SLW CYREG_PRT0_SLW

/* CapSense_BufCH0 */
#define CapSense_BufCH0__CFG0 CYREG_CAPSL_CFG0
#define CapSense_BufCH0__CFG1 CYREG_CAPSL_CFG1
#define CapSense_BufCH0__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define CapSense_BufCH0__PM_ACT_MSK 0x10u
#define CapSense_BufCH0__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define CapSense_BufCH0__PM_STBY_MSK 0x10u

/* CapSense_IsrCH0 */
#define CapSense_IsrCH0__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define CapSense_IsrCH0__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define CapSense_IsrCH0__INTC_MASK 0x10000u
#define CapSense_IsrCH0__INTC_NUMBER 16
#define CapSense_IsrCH0__INTC_PRIOR_NUM 7
#define CapSense_IsrCH0__INTC_PRIOR_REG CYREG_NVIC_PRI_16
#define CapSense_IsrCH0__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define CapSense_IsrCH0__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* LCD_LCDPort */
#define LCD_LCDPort__0__MASK 0x01u
#define LCD_LCDPort__0__PC CYREG_PRT2_PC0
#define LCD_LCDPort__0__PORT 2
#define LCD_LCDPort__0__SHIFT 0
#define LCD_LCDPort__1__MASK 0x02u
#define LCD_LCDPort__1__PC CYREG_PRT2_PC1
#define LCD_LCDPort__1__PORT 2
#define LCD_LCDPort__1__SHIFT 1
#define LCD_LCDPort__2__MASK 0x04u
#define LCD_LCDPort__2__PC CYREG_PRT2_PC2
#define LCD_LCDPort__2__PORT 2
#define LCD_LCDPort__2__SHIFT 2
#define LCD_LCDPort__3__MASK 0x08u
#define LCD_LCDPort__3__PC CYREG_PRT2_PC3
#define LCD_LCDPort__3__PORT 2
#define LCD_LCDPort__3__SHIFT 3
#define LCD_LCDPort__4__MASK 0x10u
#define LCD_LCDPort__4__PC CYREG_PRT2_PC4
#define LCD_LCDPort__4__PORT 2
#define LCD_LCDPort__4__SHIFT 4
#define LCD_LCDPort__5__MASK 0x20u
#define LCD_LCDPort__5__PC CYREG_PRT2_PC5
#define LCD_LCDPort__5__PORT 2
#define LCD_LCDPort__5__SHIFT 5
#define LCD_LCDPort__6__MASK 0x40u
#define LCD_LCDPort__6__PC CYREG_PRT2_PC6
#define LCD_LCDPort__6__PORT 2
#define LCD_LCDPort__6__SHIFT 6
#define LCD_LCDPort__AG CYREG_PRT2_AG
#define LCD_LCDPort__AMUX CYREG_PRT2_AMUX
#define LCD_LCDPort__BIE CYREG_PRT2_BIE
#define LCD_LCDPort__BIT_MASK CYREG_PRT2_BIT_MASK
#define LCD_LCDPort__BYP CYREG_PRT2_BYP
#define LCD_LCDPort__CTL CYREG_PRT2_CTL
#define LCD_LCDPort__DM0 CYREG_PRT2_DM0
#define LCD_LCDPort__DM1 CYREG_PRT2_DM1
#define LCD_LCDPort__DM2 CYREG_PRT2_DM2
#define LCD_LCDPort__DR CYREG_PRT2_DR
#define LCD_LCDPort__INP_DIS CYREG_PRT2_INP_DIS
#define LCD_LCDPort__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LCD_LCDPort__LCD_EN CYREG_PRT2_LCD_EN
#define LCD_LCDPort__MASK 0x7Fu
#define LCD_LCDPort__PORT 2
#define LCD_LCDPort__PRT CYREG_PRT2_PRT
#define LCD_LCDPort__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LCD_LCDPort__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LCD_LCDPort__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LCD_LCDPort__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LCD_LCDPort__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LCD_LCDPort__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LCD_LCDPort__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LCD_LCDPort__PS CYREG_PRT2_PS
#define LCD_LCDPort__SHIFT 0
#define LCD_LCDPort__SLW CYREG_PRT2_SLW

/* SPIM_BSPIM */
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB13_14_CTL
#define SPIM_BSPIM_BitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define SPIM_BSPIM_BitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB13_14_CTL
#define SPIM_BSPIM_BitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB13_14_MSK
#define SPIM_BSPIM_BitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define SPIM_BSPIM_BitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB13_14_MSK
#define SPIM_BSPIM_BitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define SPIM_BSPIM_BitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define SPIM_BSPIM_BitCounter__CONTROL_REG CYREG_B0_UDB13_CTL
#define SPIM_BSPIM_BitCounter__CONTROL_ST_REG CYREG_B0_UDB13_ST_CTL
#define SPIM_BSPIM_BitCounter__COUNT_REG CYREG_B0_UDB13_CTL
#define SPIM_BSPIM_BitCounter__COUNT_ST_REG CYREG_B0_UDB13_ST_CTL
#define SPIM_BSPIM_BitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define SPIM_BSPIM_BitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define SPIM_BSPIM_BitCounter__PERIOD_REG CYREG_B0_UDB13_MSK
#define SPIM_BSPIM_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define SPIM_BSPIM_BitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB13_14_ST
#define SPIM_BSPIM_BitCounter_ST__MASK_REG CYREG_B0_UDB13_MSK
#define SPIM_BSPIM_BitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define SPIM_BSPIM_BitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define SPIM_BSPIM_BitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define SPIM_BSPIM_BitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB13_ST_CTL
#define SPIM_BSPIM_BitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB13_ST_CTL
#define SPIM_BSPIM_BitCounter_ST__STATUS_REG CYREG_B0_UDB13_ST
#define SPIM_BSPIM_RxStsReg__4__MASK 0x10u
#define SPIM_BSPIM_RxStsReg__4__POS 4
#define SPIM_BSPIM_RxStsReg__5__MASK 0x20u
#define SPIM_BSPIM_RxStsReg__5__POS 5
#define SPIM_BSPIM_RxStsReg__6__MASK 0x40u
#define SPIM_BSPIM_RxStsReg__6__POS 6
#define SPIM_BSPIM_RxStsReg__MASK 0x70u
#define SPIM_BSPIM_RxStsReg__MASK_REG CYREG_B0_UDB15_MSK
#define SPIM_BSPIM_RxStsReg__STATUS_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define SPIM_BSPIM_RxStsReg__STATUS_REG CYREG_B0_UDB15_ST
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_A0_REG CYREG_B0_UDB12_13_A0
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_A1_REG CYREG_B0_UDB12_13_A1
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_D0_REG CYREG_B0_UDB12_13_D0
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_D1_REG CYREG_B0_UDB12_13_D1
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_F0_REG CYREG_B0_UDB12_13_F0
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_F1_REG CYREG_B0_UDB12_13_F1
#define SPIM_BSPIM_sR8_Dp_u0__A0_A1_REG CYREG_B0_UDB12_A0_A1
#define SPIM_BSPIM_sR8_Dp_u0__A0_REG CYREG_B0_UDB12_A0
#define SPIM_BSPIM_sR8_Dp_u0__A1_REG CYREG_B0_UDB12_A1
#define SPIM_BSPIM_sR8_Dp_u0__D0_D1_REG CYREG_B0_UDB12_D0_D1
#define SPIM_BSPIM_sR8_Dp_u0__D0_REG CYREG_B0_UDB12_D0
#define SPIM_BSPIM_sR8_Dp_u0__D1_REG CYREG_B0_UDB12_D1
#define SPIM_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define SPIM_BSPIM_sR8_Dp_u0__F0_F1_REG CYREG_B0_UDB12_F0_F1
#define SPIM_BSPIM_sR8_Dp_u0__F0_REG CYREG_B0_UDB12_F0
#define SPIM_BSPIM_sR8_Dp_u0__F1_REG CYREG_B0_UDB12_F1
#define SPIM_BSPIM_TxStsReg__0__MASK 0x01u
#define SPIM_BSPIM_TxStsReg__0__POS 0
#define SPIM_BSPIM_TxStsReg__1__MASK 0x02u
#define SPIM_BSPIM_TxStsReg__1__POS 1
#define SPIM_BSPIM_TxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define SPIM_BSPIM_TxStsReg__16BIT_STATUS_REG CYREG_B0_UDB12_13_ST
#define SPIM_BSPIM_TxStsReg__2__MASK 0x04u
#define SPIM_BSPIM_TxStsReg__2__POS 2
#define SPIM_BSPIM_TxStsReg__3__MASK 0x08u
#define SPIM_BSPIM_TxStsReg__3__POS 3
#define SPIM_BSPIM_TxStsReg__4__MASK 0x10u
#define SPIM_BSPIM_TxStsReg__4__POS 4
#define SPIM_BSPIM_TxStsReg__MASK 0x1Fu
#define SPIM_BSPIM_TxStsReg__MASK_REG CYREG_B0_UDB12_MSK
#define SPIM_BSPIM_TxStsReg__STATUS_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define SPIM_BSPIM_TxStsReg__STATUS_REG CYREG_B0_UDB12_ST

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x02u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x02u

/* MISO */
#define MISO__0__MASK 0x10u
#define MISO__0__PC CYREG_PRT1_PC4
#define MISO__0__PORT 1
#define MISO__0__SHIFT 4
#define MISO__AG CYREG_PRT1_AG
#define MISO__AMUX CYREG_PRT1_AMUX
#define MISO__BIE CYREG_PRT1_BIE
#define MISO__BIT_MASK CYREG_PRT1_BIT_MASK
#define MISO__BYP CYREG_PRT1_BYP
#define MISO__CTL CYREG_PRT1_CTL
#define MISO__DM0 CYREG_PRT1_DM0
#define MISO__DM1 CYREG_PRT1_DM1
#define MISO__DM2 CYREG_PRT1_DM2
#define MISO__DR CYREG_PRT1_DR
#define MISO__INP_DIS CYREG_PRT1_INP_DIS
#define MISO__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define MISO__LCD_EN CYREG_PRT1_LCD_EN
#define MISO__MASK 0x10u
#define MISO__PORT 1
#define MISO__PRT CYREG_PRT1_PRT
#define MISO__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define MISO__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define MISO__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define MISO__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define MISO__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define MISO__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define MISO__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define MISO__PS CYREG_PRT1_PS
#define MISO__SHIFT 4
#define MISO__SLW CYREG_PRT1_SLW

/* MOSI */
#define MOSI__0__MASK 0x80u
#define MOSI__0__PC CYREG_PRT1_PC7
#define MOSI__0__PORT 1
#define MOSI__0__SHIFT 7
#define MOSI__AG CYREG_PRT1_AG
#define MOSI__AMUX CYREG_PRT1_AMUX
#define MOSI__BIE CYREG_PRT1_BIE
#define MOSI__BIT_MASK CYREG_PRT1_BIT_MASK
#define MOSI__BYP CYREG_PRT1_BYP
#define MOSI__CTL CYREG_PRT1_CTL
#define MOSI__DM0 CYREG_PRT1_DM0
#define MOSI__DM1 CYREG_PRT1_DM1
#define MOSI__DM2 CYREG_PRT1_DM2
#define MOSI__DR CYREG_PRT1_DR
#define MOSI__INP_DIS CYREG_PRT1_INP_DIS
#define MOSI__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define MOSI__LCD_EN CYREG_PRT1_LCD_EN
#define MOSI__MASK 0x80u
#define MOSI__PORT 1
#define MOSI__PRT CYREG_PRT1_PRT
#define MOSI__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define MOSI__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define MOSI__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define MOSI__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define MOSI__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define MOSI__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define MOSI__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define MOSI__PS CYREG_PRT1_PS
#define MOSI__SHIFT 7
#define MOSI__SLW CYREG_PRT1_SLW

/* SCLK */
#define SCLK__0__MASK 0x40u
#define SCLK__0__PC CYREG_PRT1_PC6
#define SCLK__0__PORT 1
#define SCLK__0__SHIFT 6
#define SCLK__AG CYREG_PRT1_AG
#define SCLK__AMUX CYREG_PRT1_AMUX
#define SCLK__BIE CYREG_PRT1_BIE
#define SCLK__BIT_MASK CYREG_PRT1_BIT_MASK
#define SCLK__BYP CYREG_PRT1_BYP
#define SCLK__CTL CYREG_PRT1_CTL
#define SCLK__DM0 CYREG_PRT1_DM0
#define SCLK__DM1 CYREG_PRT1_DM1
#define SCLK__DM2 CYREG_PRT1_DM2
#define SCLK__DR CYREG_PRT1_DR
#define SCLK__INP_DIS CYREG_PRT1_INP_DIS
#define SCLK__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define SCLK__LCD_EN CYREG_PRT1_LCD_EN
#define SCLK__MASK 0x40u
#define SCLK__PORT 1
#define SCLK__PRT CYREG_PRT1_PRT
#define SCLK__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define SCLK__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define SCLK__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define SCLK__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define SCLK__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define SCLK__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define SCLK__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define SCLK__PS CYREG_PRT1_PS
#define SCLK__SHIFT 6
#define SCLK__SLW CYREG_PRT1_SLW

/* nSS */
#define nSS__0__MASK 0x80u
#define nSS__0__PC CYREG_PRT2_PC7
#define nSS__0__PORT 2
#define nSS__0__SHIFT 7
#define nSS__AG CYREG_PRT2_AG
#define nSS__AMUX CYREG_PRT2_AMUX
#define nSS__BIE CYREG_PRT2_BIE
#define nSS__BIT_MASK CYREG_PRT2_BIT_MASK
#define nSS__BYP CYREG_PRT2_BYP
#define nSS__CTL CYREG_PRT2_CTL
#define nSS__DM0 CYREG_PRT2_DM0
#define nSS__DM1 CYREG_PRT2_DM1
#define nSS__DM2 CYREG_PRT2_DM2
#define nSS__DR CYREG_PRT2_DR
#define nSS__INP_DIS CYREG_PRT2_INP_DIS
#define nSS__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define nSS__LCD_EN CYREG_PRT2_LCD_EN
#define nSS__MASK 0x80u
#define nSS__PORT 2
#define nSS__PRT CYREG_PRT2_PRT
#define nSS__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define nSS__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define nSS__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define nSS__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define nSS__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define nSS__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define nSS__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define nSS__PS CYREG_PRT2_PS
#define nSS__SHIFT 7
#define nSS__SLW CYREG_PRT2_SLW

/* Miscellaneous */
/* -- WARNING: define names containting LEOPARD or PANTHER are deprecated and will be removed in a future release */
#define CYDEV_CHIP_REVISION_5A_ES1 1
#define CYDEV_CHIP_REV_PANTHER_ES1 1
#define CYDEV_CHIP_MEMBER_5A 2
#define CYDEV_CHIP_FAMILY_PSOC5 2
#define CYDEV_CHIP_DIE_PANTHER 2
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_DIE_PANTHER
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CyBtldr_Custom_Interface 0
#define CYDEV_BOOTLOADER_CHECKSUM 0
#define CYDEV_BOOTLOADER_CHECKSUM_BASIC 0
#define CYDEV_BOOTLOADER_CHECKSUM_CRC 1
#define CYDEV_BOOTLOADER_WAIT_COMMAND 1
#define CYDEV_BOOTLOADER_WAIT_TIME 10
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_DIE_LEOPARD 1
#define CYDEV_CHIP_DIE_UNKNOWN 0
#define CYDEV_CHIP_FAMILY_PSOC3 1
#define CYDEV_CHIP_FAMILY_UNKNOWN 0
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x0E13C069
#define CYDEV_CHIP_MEMBER_3A 1
#define CYDEV_CHIP_MEMBER_UNKNOWN 0
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5A
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REV_PANTHER_ES1
#define CYDEV_CHIP_REV_LEOPARD_ES1 0
#define CYDEV_CHIP_REV_LEOPARD_ES2 1
#define CYDEV_CHIP_REV_LEOPARD_ES3 3
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
#define CYDEV_CHIP_REV_PANTHER_ES0 0
#define CYDEV_CHIP_REVISION_3A_ES1 0
#define CYDEV_CHIP_REVISION_3A_ES2 1
#define CYDEV_CHIP_REVISION_3A_ES3 3
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
#define CYDEV_CHIP_REVISION_5A_ES0 0
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5A_ES1
#define CYDEV_CONFIG_FORCE_ROUTE 0
#define CYDEV_CONFIG_UNUSED_IO 0
#define CYDEV_CONFIGURATION_COMPRESSED 0
#define CYDEV_CONFIGURATION_DMA 1
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED 1
#define CYDEV_CONFIGURATION_MODE 2
#define CYDEV_DATA_CACHE_ENABLED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x01
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DBG_DBE
#define CYDEV_DEBUGGING_DPS 2
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_REQXRES 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 4096
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 16384
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5
#define CYDEV_VIO3_MV 5000
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
