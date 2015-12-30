/*******************************************************************************
* File Name: CapSense_MBX.h
* Version 2.10
*
* Description:
*  This file provides constants and structure declarations for the tuner 
*  communication the for CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAPSENSE_CSD_MBX_CapSense_H)
#define CY_CAPSENSE_CSD_MBX_CapSense_H

#include "CapSense.h"
#include "CapSense_CSHL.h"


/***************************************
*   Condition compilation parameters
***************************************/

/* Check Sum to identify data */
#define CapSense_CHECK_SUM      (49u)

#define CapSense_TOTAL_SENSOR_MASK_COUNT     (((CapSense_TOTAL_SENSOR_COUNT - 1u) / 8u) + 1u)

/* Do nothing from big endian compilers (__C51__), for ARM compilers need to swap bytes */
#if defined(__C51__) || defined(__CX51__)
    #define CapSense_SWAP_ENDIAN16(x) (x)
    #define CYPACKED
#else
    #define CapSense_SWAP_ENDIAN16(x) ((uint16)(((x) << 8) | ((x) >> 8)))
    #define CYPACKED __attribute__ ((packed))
#endif  /* End (defined(__C51__)) */

#define CapSense_WIDGET_CSHL_PARAMETERS_COUNT           (CapSense_TOTAL_WIDGET_COUNT + \
                                                                 CapSense_TOTAL_TOUCH_PADS_COUNT + \
                                                                 CapSense_TOTAL_MATRIX_BUTTONS_COUNT)

#define CapSense_WIDGET_RESOLUTION_PARAMETERS_COUNT     (CapSense_WIDGET_CSHL_PARAMETERS_COUNT + \
                                                                 CapSense_TOTAL_GENERICS_COUNT)


/***************************************
*      Type defines for mailboxes
***************************************/

/* Outbox structure definition */
typedef struct _CapSense_outbox
{       
    #if (CapSense_TOTAL_CENTROIDS_COUNT)
        uint16   position[CapSense_TOTAL_CENTROIDS_COUNT];
    #endif  /* End (CapSense_TOTAL_CENTROIDS_COUNT) */
    
    uint16   rawData[CapSense_TOTAL_SENSOR_COUNT];
    uint16   baseLine[CapSense_TOTAL_SENSOR_COUNT];
    uint8    signal[CapSense_TOTAL_SENSOR_COUNT];
    uint8    onMask[CapSense_TOTAL_SENSOR_MASK_COUNT];
    
    #if (CapSense_TUNING_METHOD == CapSense_AUTO_TUNING)
        uint8   fingerThreshold[CapSense_WIDGET_CSHL_PARAMETERS_COUNT];
        uint8   noiseThreshold[CapSense_WIDGET_CSHL_PARAMETERS_COUNT];
        uint8   scanResolution[CapSense_WIDGET_RESOLUTION_PARAMETERS_COUNT];
        uint8   idacValue[CapSense_TOTAL_SENSOR_COUNT];
        uint8   prescaler;
    #endif  /* End (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING) */
    
    #if(CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING)
        uint8   noReadMsg;
    #endif  /* End (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING) */
    uint16  checkSum;
    
} CYPACKED CapSense_OUTBOX;

/* Inbox structure definition */
#if (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING)
    typedef struct _CapSense_inbox
    {
        uint8   sensorIndex;
        #if (CapSense_CURRENT_SOURCE)
            uint8   idacSettings;
        #endif /* End CapSense_CURRENT_SOURCE */
        uint8   resolution;
        uint8   fingerThreshold;
        uint8   noiseThreshold;
        uint8   hysteresis;
        uint8   debounce;
        
    } CYPACKED CapSense_INBOX;
    
#endif  /* End (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING) */

/* Mailbox structure definition */
typedef struct _CapSense_mailBox
{
    uint8   type;               /* Must be the first byte with values ranging from 0-119 */
    uint16  size;               /* Must be the size of this data structure. Range between 0-127 */
    CapSense_OUTBOX  outbox;
    #if (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING)
        CapSense_INBOX inbox;
    #endif  /* End (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING) */
    
} CYPACKED CapSense_MAILBOX;


/* Mailboxes structure definition */
typedef struct _CapSense_mailboxes
{
    uint8   numMailBoxes;       /* This must always be the first. Represents # of mailboxes */
    CapSense_MAILBOX    csdMailbox;
    
} CYPACKED CapSense_MAILBOXES;


/***************************************
*        Function Prototypes
***************************************/

void CapSense_InitMailbox(volatile CapSense_MAILBOX *mbx);
void CapSense_PostMessage(volatile CapSense_MAILBOX *mbx);
#if (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING)
    void CapSense_ReadMessage(volatile CapSense_MAILBOX *mbx);
#endif  /* End (CapSense_TUNING_METHOD == CapSense_MANUAL_TUNING) */


/***************************************
*           API Constants        
***************************************/

/* The selected ID for this version of Tuner */
#define CapSense_TYPE_ID        (0x04u)

#define CapSense_BUSY_FLAG      (CapSense_TYPE_ID | 0x80u)
#define CapSense_HAVE_MSG       (sizeof(CapSense_MAILBOX) | 0x8000u)


#endif  /* End (CY_CAPSENSE_CSD_MBX_CapSense_H) */


/* [] END OF FILE */
