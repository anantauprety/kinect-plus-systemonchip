/*******************************************************************************
* File Name: nSS.c  
* Version 1.50
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "nSS.h"


/*******************************************************************************
* Function Name: nSS_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void nSS_Write(uint8 value) 
{
    uint8 staticBits = nSS_DR & ~nSS_MASK;
    nSS_DR = staticBits | ((value << nSS_SHIFT) & nSS_MASK);
}


/*******************************************************************************
* Function Name: nSS_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void nSS_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(nSS_0, mode);
}


/*******************************************************************************
* Function Name: nSS_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro nSS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 nSS_Read(void) 
{
    return (nSS_PS & nSS_MASK) >> nSS_SHIFT;
}


/*******************************************************************************
* Function Name: nSS_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 nSS_ReadDataReg(void) 
{
    return (nSS_DR & nSS_MASK) >> nSS_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(nSS_INTSTAT) 

    /*******************************************************************************
    * Function Name: nSS_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 nSS_ClearInterrupt(void) 
    {
        return (nSS_INTSTAT & nSS_MASK) >> nSS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
