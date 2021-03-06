/*******************************************************************************
* File Name: CapSense_CompCH0.c  
* Version 1.60
*
*  Description:
*    This file provides the source code to the API for the Comparator component.
*
*   Note:
*     
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "CapSense_CompCH0.h"
#include "CyLib.h"

uint8 CapSense_CompCH0_initVar = 0u;


/*******************************************************************************
* Function Name: CapSense_CompCH0_Init
********************************************************************************
*
* Summary:
*  Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void CapSense_CompCH0_Init(void) 
{
    /* Set default speed/power */
    CapSense_CompCH0_SetSpeed(CapSense_CompCH0_DEFAULT_SPEED);

    /* Set default Hysteresis */
    if ( CapSense_CompCH0_DEFAULT_HYSTERESIS == 0u )
    {
        CapSense_CompCH0_CR |= CapSense_CompCH0_HYST_OFF;
    }
    else
    {
        CapSense_CompCH0_CR &= ~CapSense_CompCH0_HYST_OFF; 
    }
    
    /* Set default Power Down Override */
    if ( CapSense_CompCH0_DEFAULT_PWRDWN_OVRD == 0u )
    {
        CapSense_CompCH0_CR &= ~CapSense_CompCH0_PWRDWN_OVRD;
    }
    else 
    {
        CapSense_CompCH0_CR |= CapSense_CompCH0_PWRDWN_OVRD;
    }

    /* Set default sync */
    CapSense_CompCH0_CLK &= ~CapSense_CompCH0_SYNCCLK_MASK;
    if ( CapSense_CompCH0_DEFAULT_BYPASS_SYNC == 0u )
    {
        CapSense_CompCH0_CLK |= CapSense_CompCH0_SYNC_CLK_EN;
    }
    else
    {
        CapSense_CompCH0_CLK |= CapSense_CompCH0_BYPASS_SYNC;
    }
    /* Set trim value for high speed compator */
    if(CapSense_CompCH0_DEFAULT_SPEED == CapSense_CompCH0_HIGHSPEED)
    {
        /* PSoC3 ES2 or early, PSoC5 ES1 or early */
        #if (CapSense_CompCH0_PSOC3_ES2 || CapSense_CompCH0_PSOC5_ES1)
        CapSense_CompCH0_TR = CapSense_CompCH0_HS_TRIM_TR0;
        #endif 
        
        /* PSoC3 ES3 or later, PSoC5 ES2 or later */
        #if (CapSense_CompCH0_PSOC3_ES3 || CapSense_CompCH0_PSOC5_ES2) 
        CapSense_CompCH0_TR0 = CapSense_CompCH0_HS_TRIM_TR0;
        CapSense_CompCH0_TR1 = CapSense_CompCH0_HS_TRIM_TR1;
        #endif 
        
    }    
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_Enable
********************************************************************************
*
* Summary:
*  Enable the Comparator
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void CapSense_CompCH0_Enable(void) 
{
    CapSense_CompCH0_PWRMGR |= CapSense_CompCH0_ACT_PWR_EN;
    CapSense_CompCH0_STBY_PWRMGR |= CapSense_CompCH0_STBY_PWR_EN;
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_Start
********************************************************************************
*
* Summary:
*  The start function initializes the Analog Comparator with the default values.
*
* Parameters:
*  void
*
* Return:  
*  void 
*
* Global variables:
*  CapSense_CompCH0_initVar: Is modified when this function is called for the first 
*   time. Is used to ensure that initialization happens only once.
*  
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_CompCH0_Start(void) 
{
    if ( CapSense_CompCH0_initVar == 0u )
    {
        CapSense_CompCH0_Init();
        
        CapSense_CompCH0_initVar = 1u;
    }    

    /* Enable power to comparator */
    CapSense_CompCH0_Enable();    
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:  
*  void
*
* Return: 
*  void 
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void CapSense_CompCH0_Stop(void) 
{
    /* Disable power to comparator */
    CapSense_CompCH0_PWRMGR &= ~CapSense_CompCH0_ACT_PWR_EN;
    CapSense_CompCH0_STBY_PWRMGR &= ~CapSense_CompCH0_STBY_PWR_EN;    
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_SetSpeed
********************************************************************************
*
* Summary:
*  This function sets the speed of the Analog Comparator.  The faster the speed
*  the more power that is used.
*
* Parameters:  
*  speed:   (uint8) Sets operation mode of Comparator
*
* Return:  
*  void 
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void CapSense_CompCH0_SetSpeed(uint8 speed) 
{
    /* Clear and Set power level */    
    CapSense_CompCH0_CR = (CapSense_CompCH0_CR & ~CapSense_CompCH0_PWR_MODE_MASK) |
                           (speed & CapSense_CompCH0_PWR_MODE_MASK);
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_GetCompare
********************************************************************************
*
* Summary:
*  This function returns the comparator output value.
*
* Parameters:  
*   None
*
* Return:  
*  (uint8)  0  if Pos_Input less than Neg_input
*           1  if Pos_Input greater than Neg_input. 
*
* Reentrant:
*  Yes
*
*******************************************************************************/
uint8 CapSense_CompCH0_GetCompare(void) 
{
    return( CapSense_CompCH0_WRK & CapSense_CompCH0_CMP_OUT_MASK);
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_trimAdjust
********************************************************************************
*
* Summary:
*  This function adjusts the value in the low nibble/high nibble of the Analog 
*  Comparator trim register
*
* Parameters:  
*  nibble:
*      0 -- adjusts the value in the low nibble
*      1 -- adjusts the value in the high nibble
*
* Return:
*  None
*
* Theory: 
*  Function assumes comparator block is setup for trim adjust.
*  Intended to be called from Comp_ZeroCal()
* 
* Side Effects:
*  Routine uses a course 1ms delay following each trim adjustment to allow 
*  the comparator output to respond.
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_CompCH0_trimAdjust(uint8 nibble)
{
    uint8 trimCnt;
    uint8 cmpState;   

    /* get current state of comparator output */
    cmpState = CapSense_CompCH0_WRK & CapSense_CompCH0_CMP_OUT_MASK;
    
    if (nibble == 0u)
    {    
        /* if comparator output is high, negative offset adjust is required */
        if ( cmpState != 0u )
        {
            /* PSoC3 ES2 or early, PSoC5 ES1 or early */
            #if (CapSense_CompCH0_PSOC3_ES2 || CapSense_CompCH0_PSOC5_ES1)
                CapSense_CompCH0_TR |= CapSense_CompCH0_CMP_TRIM1_DIR;
            #endif
            
            /* PSoC3 ES3 or later, PSoC5 ES2 or later */
            #if (CapSense_CompCH0_PSOC3_ES3 || CapSense_CompCH0_PSOC5_ES2)
                CapSense_CompCH0_TR0 |= CapSense_CompCH0_CMP_TR0_DIR;
            #endif
        }
    }
    else
    {
        /* if comparator output is low, positive offset adjust is required */
        if ( cmpState == 0u )
        {
            /* PSoC3 ES2 or early, PSoC5 ES1 or early */
            #if (CapSense_CompCH0_PSOC3_ES2 || CapSense_CompCH0_PSOC5_ES1)
                CapSense_CompCH0_TR |= CapSense_CompCH0_CMP_TRIM2_DIR; 
            #endif
            
            /* PSoC3 ES3 or later, PSoC5 ES2 or later */
            #if (CapSense_CompCH0_PSOC3_ES3 || CapSense_CompCH0_PSOC5_ES2)
                CapSense_CompCH0_TR1 |= CapSense_CompCH0_CMP_TR1_DIR;
            #endif
        }
    }

    /* Increment trim value until compare output changes state */
    for ( trimCnt = 0; trimCnt < 7; trimCnt++ )
    {
        if (nibble == 0u)
        {
            /* PSoC3 ES2 or early, PSoC5 ES1 or early */
            #if (CapSense_CompCH0_PSOC3_ES2 || CapSense_CompCH0_PSOC5_ES1)
                CapSense_CompCH0_TR += 1u;
            #endif
            
            /* PSoC3 ES3 or later, PSoC5 ES2 or later */
            #if (CapSense_CompCH0_PSOC3_ES3 || CapSense_CompCH0_PSOC5_ES2)
                CapSense_CompCH0_TR0 += 1u;
            #endif            
        }
        else
        {
            /* PSoC3 ES2 or early, PSoC5 ES1 or early */
            #if (CapSense_CompCH0_PSOC3_ES2 || CapSense_CompCH0_PSOC5_ES1)
                CapSense_CompCH0_TR += 0x10u;
            #endif
            
            /* PSoC3 ES3 or later, PSoC5 ES2 or later */
            #if (CapSense_CompCH0_PSOC3_ES3 || CapSense_CompCH0_PSOC5_ES2)
                CapSense_CompCH0_TR1 += 0x10u;
            #endif            
        }
        
        CyDelay(1);
        
        /* Check for change in comparator output */
        if ((CapSense_CompCH0_WRK & CapSense_CompCH0_CMP_OUT_MASK) != cmpState)
        {
            break;      /* output changed state, trim phase is complete */
        }        
    }    
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_ZeroCal
********************************************************************************
*
* Summary:
*  This function calibrates the offset of the Analog Comparator.
*
* Parameters:  
*  None
*
* Return:  
*  (uint16)  value written in trim register when calibration complete.
*
* Theory: 
*  This function is used to optimize the calibration for user specific voltage
*  range.  The comprator trim is adjusted to counter transitor offsets
*   - offset is defined as positive if the output transitions to high before inP
*     is greater than inN
*   - offset is defined as negative if the output transitions to high avter inP
*     is greater than inP
*
*  The Analog Comparator provides 1 byte for offset trim.  The byte contains two
*  4 bit trim fields - one is a course trim and the other allows smaller
*  offset adjustments.
*  - low nibble - fine trim for Fast mode, course trim for Slow mode
*  - high nibble - fine trim for Slow mode, course trim
*    for Fast mode
*  - trim[3] selects postive or negative offset adjust
*  - for low nibble: trim[3]is set high to add negative offset
*  - for high nibble: trim[3]is set high to add positive offset  
*
*  Trim algorithm is a two phase process
*  The first phase performs course offset adjustment
*  The second phase serves one of two purposes depending on the outcome of the
*  first phase
*  - if the first trim value was maxed out without a comparator output 
*    transition, more offset will be added by adjusting the second trim value.
*  - if the first trim phase resulted in a comparator output transition, the
*    second trim value will serve as fine trim (in the opposite direction)to
*    ensure the offset is < 1mv.
*
*  Trim Process:   
*  1) User applies a voltage to the negative input.  Voltage should in the
*     comparator operating range or an average of the operating voltage range.
*  2) Clear registers associted analog routing to the positive input.
*  3) Disable Hysteresis
*  4) Set the calibration bit to short the negative and positive inputs to
*     the users calibration voltage.
*  5) Clear the TR register  ( TR = 0x00 )
*  ** SLOW MODE
*  6) Check if compare output is high, if so, set trim[3] of lower nibble to a 1.
*  7) Increment trim[2:0] of lower nibble until the compare output changes
*     (course trim).
*  8) Check if compare output is low, if so, set trim[3] of higher nibble to a 1.
*  9) Increment trim[2:0] of higher nibble until the compare output changes state
*     (fine trim)
*  ** FAST MODE - change order of steps 6,7 vs. steps 8,9
*
* Side Effects:
*  Routine clears analog routing associated with the comparator positive input.  
*  This may affect routing of signals from other components that are connected
*  to the positive input of the comparator.
*
* Reentrant:
*  Yes
*
*******************************************************************************/
uint16 CapSense_CompCH0_ZeroCal(void) 
{
    uint8 tmpSW0;
    uint8 tmpSW2;
    uint8 tmpSW3;
    uint8 tmpCR;

    /* Save a copy of routing registers associated with inP */
    tmpSW0 = CapSense_CompCH0_SW0;
    tmpSW2 = CapSense_CompCH0_SW2;
    tmpSW3 = CapSense_CompCH0_SW3;

     /* Clear routing for inP, retain routing for inN */
    CapSense_CompCH0_SW0 = 0x00u;
    CapSense_CompCH0_SW2 = 0x00u;
    CapSense_CompCH0_SW3 = tmpSW3 & ~CapSense_CompCH0_CMP_SW3_INPCTL_MASK;

    /* Preserve original configuration
     * - turn off Hysteresis
     * - set calibration bit - shorts inN to inP
    */
    tmpCR = CapSense_CompCH0_CR;
    CapSense_CompCH0_CR |= (CapSense_CompCH0_CAL_ON | CapSense_CompCH0_HYST_OFF);
    
    /* Write default low values to trim register - no offset adjust */
    /* PSoC3 ES2 or early, PSoC5 ES1 or early */
    #if (CapSense_CompCH0_PSOC3_ES2 || CapSense_CompCH0_PSOC5_ES1)
        CapSense_CompCH0_TR = CapSense_CompCH0_DEFAULT_CMP_TRIM;
    #endif
    
    /* PSoC3 ES3 or later, PSoC5 ES2 or later */
    #if (CapSense_CompCH0_PSOC3_ES3 || CapSense_CompCH0_PSOC5_ES2)
        CapSense_CompCH0_TR0 = CapSense_CompCH0_DEFAULT_CMP_TRIM;
        CapSense_CompCH0_TR1 = CapSense_CompCH0_DEFAULT_CMP_TRIM;
    #endif

    /* Two phase trim - mode determines which value is trimed first */   
    if ( (CapSense_CompCH0_CR & CapSense_CompCH0_PWR_MODE_MASK) == CapSense_CompCH0_PWR_MODE_FAST)
    {
        CapSense_CompCH0_trimAdjust(1);          /* course trim */
        CapSense_CompCH0_trimAdjust(0);          /* fine trim */
    }
    else /* default to trim for slow mode */
    {
        CapSense_CompCH0_trimAdjust(0);          /* course trim */
        CapSense_CompCH0_trimAdjust(1);          /* fine trim */
    }
   
    /* Restore Config Register */
    CapSense_CompCH0_CR = tmpCR;
    
    /* Restore routing registers for inP */
    CapSense_CompCH0_SW0 = tmpSW0;
    CapSense_CompCH0_SW2 = tmpSW2;
    CapSense_CompCH0_SW3 = tmpSW3;
    
    /* PSoC3 ES2 or early, PSoC5 ES1 or early */
    #if (CapSense_CompCH0_PSOC3_ES2 || CapSense_CompCH0_PSOC5_ES1)
        return (uint16) CapSense_CompCH0_TR;
    #endif
    
    /* PSoC3 ES3 or later, PSoC5 ES2 or later */
    #if (CapSense_CompCH0_PSOC3_ES3 || CapSense_CompCH0_PSOC5_ES2)
        return ((CapSense_CompCH0_TR0)|(CapSense_CompCH0_TR1));        
    #endif
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_LoadTrim
********************************************************************************
*
* Summary:
*  This function stores a value in the Analog Comparator trim register.
*
* Parameters:  
*  uint8    trimVal - trim value.  This value is the same format as the value 
*           returned by the _ZeroCal routine.
*
* Return:  
*  None
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void CapSense_CompCH0_LoadTrim(uint16 trimVal) 
{
    /* Stores value in the Analog Comparator trim register */
    /* PSoC3 ES2 or early, PSoC5 ES1 or early */
    #if (CapSense_CompCH0_PSOC3_ES2 || CapSense_CompCH0_PSOC5_ES1)
        CapSense_CompCH0_TR = (uint8) trimVal;
    #endif
    
    /* PSoC3 ES3 or later, PSoC5 ES2 or later */
    #if (CapSense_CompCH0_PSOC3_ES3 || CapSense_CompCH0_PSOC5_ES2)
        /* Stores value in the Analog Comparator trim register for P-type load */
        CapSense_CompCH0_TR0 = (uint8) trimVal;
        
        /* Stores value in the Analog Comparator trim register for N-type load */
        CapSense_CompCH0_TR1 = (uint8) (trimVal >> 8); 
    #endif
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_PwrDwnOverrideEnable
********************************************************************************
*
* Summary:
*  This is the power down over-ride feature. This function ignores sleep parameter.  
*  and allows the component to stay active during sleep mode.
*
* Parameters:  
*  None
*
* Return:  
*  None
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void CapSense_CompCH0_PwrDwnOverrideEnable(void) 
{
    /* Set the pd_override bit in CMP_CR register */
    CapSense_CompCH0_CR |= CapSense_CompCH0_PWRDWN_OVRD;
}


/*******************************************************************************
* Function Name: CapSense_CompCH0_PwrDwnOverrideDisable
********************************************************************************
*
* Summary:
*  This is the power down over-ride feature. This allows the component to stay
*  inactive during sleep.
*
* Parameters:  
*  None
*
* Return:  
*  None
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void CapSense_CompCH0_PwrDwnOverrideDisable(void) 
{
    /* Reset the pd_override bit in CMP_CR register */
    CapSense_CompCH0_CR &= ~CapSense_CompCH0_PWRDWN_OVRD;
}


/* [] END OF FILE */
