/*******************************************************************************
* File Name: CapSense_1_TunerHelper.c
* Version 2.10
*
* Description:
*  This file provides the source code of Tuner helper APIs for the CapSense CSD 
*  component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_1_TunerHelper.h"

#if ((CapSense_1_TUNER_API_GENERATE) && (CapSense_1_TUNING_METHOD != CapSense_1_NO_TUNING))
    void CapSense_1_ProcessAllWidgets(volatile CapSense_1_OUTBOX *outbox);
    
    volatile CapSense_1_MAILBOXES CapSense_1_mailboxesComm;
    
    #if (CapSense_1_TOTAL_TOUCH_PADS_COUNT)
        extern uint8 CapSense_1_position[CapSense_1_TOTAL_CENTROIDS_COUNT];
    #endif  /* End (CapSense_1_TOTAL_TOUCH_PADS_COUNT) */
    
    extern uint8 CapSense_1_SensorOnMask[(((CapSense_1_TOTAL_SENSOR_COUNT - 1u) / 8u) + 1u)];
 #endif  /* End (CapSense_1_TUNER_API_GENERATE) */


/*******************************************************************************
* Function Name: CapSense_1_TunerStart
********************************************************************************
*
* Summary:
*  Initializes CapSense CSD component and EzI2C communication componenet to use
*  mailbox data structure for communication with Tuner GUI.
*  Start the scanning, after initialization complete.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_TunerStart(void)
{
    #if ((CapSense_1_TUNER_API_GENERATE) && (CapSense_1_TUNING_METHOD != CapSense_1_NO_TUNING))
        
        /* Init mbx and quick check */
        CapSense_1_InitMailbox(&CapSense_1_mailboxesComm.csdMailbox);
        CapSense_1_mailboxesComm.numMailBoxes = CapSense_1_DEFAULT_MAILBOXES_NUMBER;
        
        /* Start CapSense and baselines */
        CapSense_1_Start();
        
        /* Initialize baselines */ 
        CapSense_1_InitializeAllBaselines();
        CapSense_1_InitializeAllBaselines();
        
        /* Start EzI2C, clears buf pointers */
        EZI2C_Start();
        
        /* Setup EzI2C buffers */
        EZI2C_SetBuffer1(sizeof(CapSense_1_mailboxesComm), sizeof(CapSense_1_mailboxesComm),
                                        (void *) &CapSense_1_mailboxesComm);
        
        /* Starts scan all enabled sensors */
        CapSense_1_ScanEnabledWidgets();
    
    #endif  /* End (CapSense_1_TUNER_API_GENERATE) */
}


/*******************************************************************************
* Function Name: CapSense_1_TunerComm
********************************************************************************
*
* Summary:
*  This function is blocking. It waits till scaning loop is completed and apply
*  new parameters from Tuner GUI if available (manual tuning mode only). Updates
*  enabled baselines and state of widgets. Waits while Tuner GUI reports that 
*  content of mailbox could be modified. Then loads the report data into outbox 
*  and sets the busy flag. Starts new scanning loop.
*  
* Parameters:
*  None
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_TunerComm(void)
{
    #if ((CapSense_1_TUNER_API_GENERATE) && (CapSense_1_TUNING_METHOD != CapSense_1_NO_TUNING))
        if (0u == CapSense_1_IsBusy())
        {   
            /* Apply new settings */
            #if (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING)
                CapSense_1_ReadMessage(&CapSense_1_mailboxesComm.csdMailbox);
            #endif  /* End (CapSense_1_TUNING_METHOD == CapSense_1_MANUAL_TUNING) */
            
            /* Enable EZI2C interrupts, after scan complete */
            EZI2C_EnableInt();
            
            /* Update all baselines and process all widgets */
            CapSense_1_UpdateEnabledBaselines();
            CapSense_1_ProcessAllWidgets(&CapSense_1_mailboxesComm.csdMailbox.outbox);
            
            CapSense_1_PostMessage(&CapSense_1_mailboxesComm.csdMailbox);
            
            /* Disable EZI2C interrupts, while scanning */
            EZI2C_DisableInt();
            
            /* Start scan all sensors */
            CapSense_1_ScanEnabledWidgets();
        }
    #endif  /* End (CapSense_1_TUNER_API_GENERATE) */
}


#if ((CapSense_1_TUNER_API_GENERATE) && (CapSense_1_TUNING_METHOD != CapSense_1_NO_TUNING))
    /*******************************************************************************
    * Function Name: CapSense_1_ProcessAllWidgets
    ********************************************************************************
    *
    * Summary:
    *  Call required functions to update all widgets state:
    *   - CapSense_1_GetCentroidPos() - calls only if linear sliders 
    *     available.
    *   - CapSense_1_GetRadialCentroidPos() - calls only if radial slider 
    *     available.
    *   - CapSense_1_GetTouchCentroidPos() - calls only if touch pad slider 
    *     available.
    *   - CapSense_1_CheckIsAnyWidgetActive();
    *  The results of opeartions are copied to OUTBOX.
    *   
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Global Variables:
    *  CapSense_1_OUTBOX outbox - structure which is used as ouput 
    *  buffer for report data to Tuner GUI.
    *  Update fields:
    *    - position[];
    *    - OnMask[];
    *
    * Reentrant:
    *  No
    *
    *******************************************************************************/
    void CapSense_1_ProcessAllWidgets(volatile CapSense_1_OUTBOX *outbox)
    {
        uint8 i = 0u;
        
        #if ((CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT) || \
             (CapSense_1_TOTAL_TOUCH_PADS_COUNT))
            uint8 widgetCnt = 0u;
        #endif  /* End ((CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT) || (CapSense_1_TOTAL_TOUCH_PADS_COUNT)) */
        
        /* Copy centroids positions if exist */
        #if (CapSense_1_TOTAL_CENTROIDS_COUNT && (CapSense_1_TUNING_METHOD != CapSense_1_NO_TUNING))
        #endif  /* End (CapSense_1_TOTAL_CENTROIDS_COUNT) */
        
        /* Calculate widget with centroids */
        #if (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT)
            for(; i < CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT; i++)
            {
                outbox->position[i] = CapSense_1_SWAP_ENDIAN16(CapSense_1_GetCentroidPos(i));
            }
        #endif   /* End (CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT) */
        
        #if (CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT)
            widgetCnt = i;
            for(; i < widgetCnt + CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT; i++)
            {
                outbox->position[i] = CapSense_1_SWAP_ENDIAN16(CapSense_1_GetRadialCentroidPos(i));
            }
        #endif  /* End (CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT) */
        
        #if (CapSense_1_TOTAL_TOUCH_PADS_COUNT)
            widgetCnt = i;
            for(; i < widgetCnt + (CapSense_1_TOTAL_TOUCH_PADS_COUNT * 2); i=i+2)
            {
                if(CapSense_1_GetTouchCentroidPos(i) == 0u)
                {
                    outbox->position[i] = 0xFFFFu;
                    outbox->position[i+1] = 0xFFFFu;
                }
                else
                {
                    outbox->position[i] = CapSense_1_SWAP_ENDIAN16( (uint16) CapSense_1_position[i]);
                    outbox->position[i+1] = CapSense_1_SWAP_ENDIAN16( (uint16) CapSense_1_position[i+1]);
                }
            }
        #endif  /* End (CapSense_1_TOTAL_TOUCH_PADS_COUNT) */
        
        /* Update On/Off State */
        CapSense_1_CheckIsAnyWidgetActive();
        
        /* Copy OnMask */
        for(i=0; i < CapSense_1_TOTAL_SENSOR_MASK_COUNT; i++)
        {
            outbox->onMask[i]  = CapSense_1_SensorOnMask[i];
        }
    }
#endif /* End (CapSense_1_TUNER_API_GENERATE) */


/* [] END OF FILE */
