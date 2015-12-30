/*******************************************************************************
* File Name: nSS.h  
* Version 1.50
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_nSS_H) /* Pins nSS_H */
#define CY_PINS_nSS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nSS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    nSS_Write(uint8 value) ;
void    nSS_SetDriveMode(uint8 mode) ;
uint8   nSS_ReadDataReg(void) ;
uint8   nSS_Read(void) ;
uint8   nSS_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define nSS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define nSS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define nSS_DM_RES_UP          PIN_DM_RES_UP
#define nSS_DM_RES_DWN         PIN_DM_RES_DWN
#define nSS_DM_OD_LO           PIN_DM_OD_LO
#define nSS_DM_OD_HI           PIN_DM_OD_HI
#define nSS_DM_STRONG          PIN_DM_STRONG
#define nSS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define nSS_MASK               nSS__MASK
#define nSS_SHIFT              nSS__SHIFT
#define nSS_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nSS_PS                     (* (reg8 *) nSS__PS)
/* Data Register */
#define nSS_DR                     (* (reg8 *) nSS__DR)
/* Port Number */
#define nSS_PRT_NUM                (* (reg8 *) nSS__PRT) 
/* Connect to Analog Globals */                                                  
#define nSS_AG                     (* (reg8 *) nSS__AG)                       
/* Analog MUX bux enable */
#define nSS_AMUX                   (* (reg8 *) nSS__AMUX) 
/* Bidirectional Enable */                                                        
#define nSS_BIE                    (* (reg8 *) nSS__BIE)
/* Bit-mask for Aliased Register Access */
#define nSS_BIT_MASK               (* (reg8 *) nSS__BIT_MASK)
/* Bypass Enable */
#define nSS_BYP                    (* (reg8 *) nSS__BYP)
/* Port wide control signals */                                                   
#define nSS_CTL                    (* (reg8 *) nSS__CTL)
/* Drive Modes */
#define nSS_DM0                    (* (reg8 *) nSS__DM0) 
#define nSS_DM1                    (* (reg8 *) nSS__DM1)
#define nSS_DM2                    (* (reg8 *) nSS__DM2) 
/* Input Buffer Disable Override */
#define nSS_INP_DIS                (* (reg8 *) nSS__INP_DIS)
/* LCD Common or Segment Drive */
#define nSS_LCD_COM_SEG            (* (reg8 *) nSS__LCD_COM_SEG)
/* Enable Segment LCD */
#define nSS_LCD_EN                 (* (reg8 *) nSS__LCD_EN)
/* Slew Rate Control */
#define nSS_SLW                    (* (reg8 *) nSS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nSS_PRTDSI__CAPS_SEL       (* (reg8 *) nSS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nSS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nSS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nSS_PRTDSI__OE_SEL0        (* (reg8 *) nSS__PRTDSI__OE_SEL0) 
#define nSS_PRTDSI__OE_SEL1        (* (reg8 *) nSS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nSS_PRTDSI__OUT_SEL0       (* (reg8 *) nSS__PRTDSI__OUT_SEL0) 
#define nSS_PRTDSI__OUT_SEL1       (* (reg8 *) nSS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nSS_PRTDSI__SYNC_OUT       (* (reg8 *) nSS__PRTDSI__SYNC_OUT) 


#if defined(nSS__INTSTAT)  /* Interrupt Registers */

    #define nSS_INTSTAT                (* (reg8 *) nSS__INTSTAT)
    #define nSS_SNAP                   (* (reg8 *) nSS__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins nSS_H */


/* [] END OF FILE */
