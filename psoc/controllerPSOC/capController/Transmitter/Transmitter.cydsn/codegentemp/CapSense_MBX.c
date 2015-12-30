/*******************************************************************************
* File Name: CapSense_MBX.c
* Version 2.10
*
* Description:
*  This file provides the source code of Tuner communication APIs for the 
*  CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_MBX.h"

#if (CapSense_CURRENT_SOURCE)
    extern uint8 CapSense_idacSettings[];
#endif /* End CapSense_CURRENT_SOURCE */

extern uint8 CapSense_widgetResolution[];
extern uint16 CapSense_SensorRaw[CapSense_TOTAL_SENSOR_COUNT];
extern const uint8 CYCODE CapSense_widgetNumber[];

extern uint16 CapSense_SensorBaseline[CapSense_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_SensorSignal[CapSense_TOTAL_SENSOR_COUNT];

#if (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING)
    extern uint8 CapSense_fingerThreshold[];
    extern uint8 CapSense_noiseThreshold[];
    extern uint8 CapSense_hysteresis[];
    extern uint8 CapSense_debounce[];
    
#elif (CapSense_TUNING_METHOD == CapSense_AUTO_TUNING)
    extern uint8 CapSense_lowLevelTuningDone;
    extern uint8 CapSense_fingerThreshold[];
    extern uint8 CapSense_noiseThreshold[];

    extern uint8 CapSense_GetPrescaler(void);
#else
    /* No tunning */
#endif  /* End CapSense_TUNING_METHOD */


#if (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING)
    /*******************************************************************************
    * Function Name: CapSense_InitParams
    ********************************************************************************
    *
    * Summary:
    *  Configures component parameters to match the parameters in the inbox.
    *  Used only in manual tuning mode to apply new scanning parameters from Tuner 
    *  GUI.
    *
    * Parameters:
    *  inbox:  Pointer to Inbox structure in RAM.
    *
    * Return:
    *  None. Contents of the structure are not modified.
    * 
    * Side Effects: 
    *  Resets baseline values.
    *
    * Global Variables:
    *  CapSense_idacSettings[] - used to store idac value for all sensors.
    *  CapSense_fingerThreshold[] - used to store finger threshold for all 
    *  widgets.
    *  CapSense_noiseThreshold[] - used to sotre noise threshold for all 
    *  widgets.
    *  CapSense_hysteresis[] - used to store finger threshold for all 
    *  widgets.
    *  CapSense_debounce[] - used to store finger threshold for all 
    *  widgets.
    *  CapSense_INBOX inbox - structure which is used as input buffer
    *  for parameters from Tuner GUI. Only used in manual tuning mode.
    *
    * Reentrant:
    *  No
    *
    *******************************************************************************/
    static void CapSense_InitParams(volatile CapSense_INBOX *inbox)
    {
        /* Define widget sensor belongs to */
        uint8 sensor = inbox->sensorIndex;
        uint8 widget = CapSense_widgetNumber[sensor];
        
        /* Scanning parameters */
        #if (CapSense_CURRENT_SOURCE)
            CapSense_idacSettings[sensor] = inbox->idacSettings;
        #endif /* End CapSense_CURRENT_SOURCE */   
        CapSense_widgetResolution[widget] = inbox->resolution;
    
        #if (CapSense_TOTAL_GENERICS_COUNT)
            /* Exclude generic wiget */
            if(widget < CapSense_END_OF_WIDGETS_INDEX)
            {
        #endif  /* End CapSense_TOTAL_GENERICS_COUNT */
        
            /* High level parameters */
            CapSense_fingerThreshold[widget] = inbox->fingerThreshold;
            CapSense_noiseThreshold[widget]  = inbox->noiseThreshold;
            
            CapSense_hysteresis[widget] = inbox->hysteresis;
            CapSense_debounce[widget]   = inbox->debounce;
        
        #if (CapSense_TOTAL_GENERICS_COUNT)
            /* Exclude generic wiget */
            }
        #endif  /* End CapSense_TOTAL_GENERICS_COUNT */
        
        /* Re-Init baselines */
        CapSense_InitializeAllBaselines();
    }
#endif  /* End (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING) */


/*******************************************************************************
* Function Name: CapSense_InitMailbox
********************************************************************************
*
* Summary:
*  Initialize parameters  of mailbox structure.
*  Sets type and size of mailbox structure. 
*  Sets check sum to check by Tuner GUI and noReadMsg flag to indicate that this 
*  is the first communication packet.
*
* Parameters:
*  mbx:  Pointer to Mailbox structure in RAM.
*
* Return:
*  None. Modifies the contents of mbx and mbx->outbox.
*
* Global Variables:
*  CapSense_MAILBOXES - structure which incorporates two fields: 
*    - numMailBoxes (number of mailboxes);
*    - CapSense_MAILBOX csdMailbox;
*  CapSense_MAILBOX - structure which incorporates status output and
*  input buffer fields and CapSense_OUTBOX and CapSense_INBOX.
*    - type (used as outbox read status of Tuner GUI);
*    - size (used as inbox apply status of component);
*    - CapSense_OUTBOX outbox - structure which is used as ouput 
*      buffer for report data to Tuner GUI.
*    - CapSense_INBOX inbox - structure which is used as input buffer
*      for paramters from Tuner GUI. Only used in manual tuning mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_InitMailbox(volatile CapSense_MAILBOX *mbx)
{
    /* Restore TYPE_ID (clear busy flag) to indicate "action complete" */
    mbx->type = CapSense_TYPE_ID;
    /* Restore default value - clear "have_msg" */
    mbx->size = CapSense_SWAP_ENDIAN16(sizeof(CapSense_MAILBOX)); 
    
    /* Addtional fields for async and reset handling */
    #if(CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING)
        mbx->outbox.noReadMsg = 1u;
    #endif  /* End (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING) */
    
    mbx->outbox.checkSum = CapSense_SWAP_ENDIAN16(CapSense_CHECK_SUM);
}


/*******************************************************************************
* Function Name:  CapSense_PostMessage
********************************************************************************
*
* Summary:
*  This blocking function waits while Tuner GUI reports that content of mailbox 
*  could be modified (clears CapSense_BUSY_FLAG). Then loads the report 
*  data to outbox and sets the busy flag.
*  In manual tuning mode the report data:
*    - raw data, baseline, signal;
*  In auto tuning mode to report added data:
*    - fingerThreshold;
*    - noiseThreshold;
*    - scanResolution;
*    - idacValue;
*    - prescaler.
*
* Parameters:
*  mbx:  Pointer to Mailbox structure in RAM.
*
* Return:
*  None. Modifies the contents of mbx->outbox.
*
* Global Variables:
*  CapSense_MAILBOXES - structure which incorporates two fields: 
*    - numMailBoxes (number of mailboxes);
*    - CapSense_MAILBOX csdMailbox;
*  CapSense_MAILBOX - structure which incorporates status output and
*  input buffer fields and CapSense_OUTBOX and CapSense_INBOX.
*    - type (used as outbox read status of Tuner GUI);
*    - size (used as inbox apply status of component);
*    - CapSense_OUTBOX outbox - structure which is used as ouput 
*      buffer for report data to Tuner GUI.
*    - CapSense_INBOX inbox - structure which is used as input buffer
*      for parameters from Tuner GUI. Only used in manual tuning mode.
*  CapSense_lowLevelTuningDone - used to notify the Tuner GUI that 
*  tuning of scanning parameters are done. The scanning parameters in mailbox
*  will not be updated after clear it.
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_PostMessage(volatile CapSense_MAILBOX *mbx)
{
    uint8 i;

    /* Check busy flag */
    while (mbx->type != CapSense_TYPE_ID);
    
    /* Copy all data - Raw, Base, Signal, OnMask */
    for(i=0; i < CapSense_TOTAL_SENSOR_COUNT; i++)
    {
        mbx->outbox.rawData[i]  = CapSense_SWAP_ENDIAN16(CapSense_SensorRaw[i]);
        mbx->outbox.baseLine[i] = CapSense_SWAP_ENDIAN16(CapSense_SensorBaseline[i]);
        #if (CapSense_SIGNAL_SIZE == CapSense_SIGNAL_SIZE_UINT8)
            mbx->outbox.signal[i]   = CapSense_SensorSignal[i];
        #else
            mbx->outbox.signal[i]   = CapSense_SWAP_ENDIAN16(CapSense_SensorSignal[i]);
        #endif  /* End (CapSense_SIGNAL_SIZE == CapSense_SIGNAL_SIZE_UINT8) */
    }
        
    /* AutoTuning - need to copy all High Level parameters */
    #if (CapSense_TUNING_METHOD == CapSense_AUTO_TUNING)
        
        /* Parameters are changed in run time */
        for(i=0; i < CapSense_WIDGET_CSHL_PARAMETERS_COUNT; i++)
        {
            mbx->outbox.fingerThreshold[i] = CapSense_fingerThreshold[i];
            mbx->outbox.noiseThreshold[i]  = CapSense_noiseThreshold[i];
        }
        
        /* Need to be copied only once */
        if (CapSense_lowLevelTuningDone != 0u) 
        {   
            /* Widget resolution, take to account TP and MB */
            for(i=0; i < CapSense_WIDGET_RESOLUTION_PARAMETERS_COUNT; i++)
            {
                mbx->outbox.scanResolution[i]  = CapSense_widgetResolution[i];
            }

            /* Copy tuned idac values */
            for(i=0; i < CapSense_TOTAL_SENSOR_COUNT; i++)
            {
                mbx->outbox.idacValue[i] = CapSense_idacSettings[i];
            }
            
            /* Copy scan parameters */
            mbx->outbox.prescaler = CapSense_GetPrescaler();
            
            /* Pass parameters only once */
            CapSense_lowLevelTuningDone = 0u;
        }
    #endif  /* End (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING) */

    /* Set busy flag */
    mbx->type = CapSense_BUSY_FLAG;
}


#if (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING)
    /*******************************************************************************
    * Function Name: CapSense_ReadMessage
    ********************************************************************************
    *
    * Summary:
    *  If CapSense_HAVE_MSG is found in the mailbox, initialize component 
    *  with parameters found in the inbox. Signal DONE by overwriting the
    *  value in size field in mailbox.
    *  Only available when manual tuning mode.
    *
    * Parameters:
    *  mbx:  Pointer to Mailbox structure in RAM.
    *
    * Return:
    *  None. Modifies the contents of mbx.
    *
    * Side Effects: 
    *  Initializes component parameters if CapSense_HAVE_MSG is received.
    *
    * Global Variables:
    *  CapSense_MAILBOXES - structure which incorporates two fields: 
    *    - numMailBoxes (number of mailboxes);
    *    - CapSense_MAILBOX csdMailbox;
    *  CapSense_MAILBOX - structure which incorporates status output and
    *  input buffer fields and CapSense_OUTBOX and CapSense_INBOX.
    *    - type (used as outbox read status of Tuner GUI);
    *    - size (used as inbox apply status of component);
    *    - CapSense_OUTBOX outbox - structure which is used as ouput 
    *      buffer for report data to Tuner GUI.
    *    - CapSense_INBOX inbox - structure which is used as input buffer
    *      for parameters from Tuner GUI. Only used in manual tuning mode.
    *
    * Reentrant:
    *  No
    *
    *******************************************************************************/
    void CapSense_ReadMessage(volatile CapSense_MAILBOX *mbx)
    {
        volatile CapSense_INBOX *tmpInbox;
       
        /* Do we have a message waiting? */
        if (CapSense_SWAP_ENDIAN16(mbx->size) == CapSense_HAVE_MSG)
        {
            tmpInbox = &(mbx->inbox);
            
            CapSense_InitParams(tmpInbox);
    
            /* Notify host/tuner that we have consumed the message */
            mbx->size = CapSense_SWAP_ENDIAN16(sizeof(CapSense_MAILBOX));
            
            /* Defualt settings where changed */
            mbx->outbox.noReadMsg = 0u;
        }       
    }
#endif  /* End (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING) */


/* [] END OF FILE */
