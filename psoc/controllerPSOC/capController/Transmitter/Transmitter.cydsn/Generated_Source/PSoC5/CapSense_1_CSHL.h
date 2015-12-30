/*******************************************************************************
* File Name: CapSense_1_CSHL.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the High Level APIs
*  for CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAPSENSE_CSD_CSHL_CapSense_1_H)
#define CY_CAPSENSE_CSD_CSHL_CapSense_1_H

#include "CapSense_1.h"


/***************************************
*   Condition compilation parameters
***************************************/

#define CapSense_1_SIGNAL_SIZE                (8u)
#define CapSense_1_AUTO_RESET                 (0u)
#define CapSense_1_RAW_FILTER_MASK            (8u)

/* Signal size definition */
#define CapSense_1_SIGNAL_SIZE_UINT8          (8u)
#define CapSense_1_SIGNAL_SIZE_UINT16         (16u)

/* Auto reset definition */
#define CapSense_1_AUTO_RESET_DISABLE         (0u)
#define CapSense_1_AUTO_RESET_ENABLE          (1u)

/* Mask for RAW and POS filters */
#define CapSense_1_MEDIAN_FILTER              (0x01u)
#define CapSense_1_AVERAGING_FILTER           (0x02u)
#define CapSense_1_IIR2_FILTER                (0x04u)
#define CapSense_1_IIR4_FILTER                (0x08u)
#define CapSense_1_JITTER_FILTER              (0x10u)
#define CapSense_1_IIR8_FILTER                (0x20u)
#define CapSense_1_IIR16_FILTER               (0x40u)


/***************************************
*        Function Prototypes
***************************************/

void CapSense_1_InitializeSensorBaseline(uint8 sensor);
void CapSense_1_InitializeAllBaselines(void);
#if (CapSense_1_DESIGN_TYPE == CapSense_1_TWO_CHANNELS_DESIGN)
    void CapSense_1_InitializeEnabledBaselines(void);
#endif  /* End (CapSense_1_DESIGN_TYPE == CapSense_1_TWO_CHANNELS_DESIGN) */
void CapSense_1_UpdateSensorBaseline(uint8 sensor);
void CapSense_1_UpdateEnabledBaselines(void);
uint8 CapSense_1_CheckIsWidgetActive(uint8 widget);
uint8 CapSense_1_CheckIsAnyWidgetActive(void);
void CapSense_1_EnableWidget(uint8 widget);
void CapSense_1_DisableWidget(uint8 widget);





/***************************************
*           API Constants
***************************************/

/* Widgets constants definition */

#define CapSense_1_DUMMYWIDGET__BTN        (0u)

#define CapSense_1_TOTAL_DIPLEXED_SLIDERS_COUNT        (0u)
#define CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT          (0u)
#define CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT          (0u)
#define CapSense_1_TOTAL_TOUCH_PADS_COUNT              (0u)
#define CapSense_1_TOTAL_BUTTONS_COUNT                 (1u)
#define CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT          (0u)
#define CapSense_1_TOTAL_GENERICS_COUNT                (0u)

#define CapSense_1_POS_FILTERS_MASK        (0u)

#define CapSense_1_UNUSED_DEBOUNCE_COUNTER_INDEX   (1u)


#define CapSense_1_END_OF_SLIDERS_INDEX   (0u)
#define CapSense_1_END_OF_TOUCH_PAD_INDEX   (0u)
#define CapSense_1_END_OF_BUTTONS_INDEX   (0u)
#define CapSense_1_END_OF_MATRIX_BUTTONS_INDEX   (0u)
#define CapSense_1_END_OF_WIDGETS_INDEX   (1u)


#define CapSense_1_TOTAL_SLIDERS_COUNT            ( CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT + \
                                                          CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT )
                                                          
#define CapSense_1_TOTAL_CENTROIDS_COUNT          ( CapSense_1_TOTAL_SLIDERS_COUNT + \
                                                          (CapSense_1_TOTAL_TOUCH_PADS_COUNT*2u) )

#define CapSense_1_TOTAL_WIDGET_COUNT             ( CapSense_1_TOTAL_LINEAR_SLIDERS_COUNT + \
                                                          CapSense_1_TOTAL_RADIAL_SLIDERS_COUNT + \
                                                          CapSense_1_TOTAL_TOUCH_PADS_COUNT + \
                                                          CapSense_1_TOTAL_BUTTONS_COUNT + \
                                                          CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT )
                                                           
#define CapSense_1_ANY_POS_FILTER                 (CapSense_1_MEDIAN_FILTER | \
                                                         CapSense_1_AVERAGING_FILTER | \
                                                         CapSense_1_IIR2_FILTER | \
                                                         CapSense_1_IIR4_FILTER | \
                                                         CapSense_1_JITTER_FILTER )

/*Types of centroids */
#define CapSense_1_TYPE_RADIAL_SLIDER         (0x01u)
#define CapSense_1_TYPE_LINEAR_SLIDER         (0x02u)
#define CapSense_1_TYPE_GENERIC               (0xFFu)

/* Defines is slot active */
#define CapSense_1_SENSOR_1_IS_ACTIVE     (0x01u)
#define CapSense_1_SENSOR_2_IS_ACTIVE     (0x02u)
#define CapSense_1_WIDGET_IS_ACTIVE       (0x01u)

/* Defines diplex type of Slider */
#define CapSense_1_IS_DIPLEX             (0x80u)

/* Defines max fingers on TouchPad  */
#define  CapSense_1_POS_PREV             (0u)
#define  CapSense_1_POS                  (1u)
#define  CapSense_1_POS_NEXT             (2u)

#endif /* End CY_CAPSENSE_CSD_CSHL_CapSense_1_H */


/* [] END OF FILE */
