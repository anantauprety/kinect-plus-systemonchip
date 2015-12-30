/*******************************************************************************
* File Name: CapSense_1_CSHL.c
* Version 2.10
*
* Description:
*  This file provides the source code to the High Level APIs for the CapSesne
*  CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_1_CSHL.h"

/* SmartSense functions */
#if (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING)
    extern void CapSense_1_CalculateThresholds(uint8 SensorNumber);
#endif /* End (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING) */

/* Median filter function prototype */
#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_MEDIAN_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_MEDIAN_FILTER) )
    uint16 CapSense_1_MedianFilter(uint16 x1, uint16 x2, uint16 x3) \
    ;
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */

/* Averaging filter function prototype */
#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_AVERAGING_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_AVERAGING_FILTER) )
    uint16 CapSense_1_AveragingFilter(uint16 x1, uint16 x2, uint16 x3) \
    ;
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */

/* IIR2Filter(1/2prev + 1/2cur) filter function prototype */
#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR2_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_IIR2_FILTER) )
uint16 CapSense_1_IIR2Filter(uint16 x1, uint16 x2) ;
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */

/* IIR4Filter(3/4prev + 1/4cur) filter function prototype */
#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR4_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_IIR4_FILTER) )
    uint16 CapSense_1_IIR4Filter(uint16 x1, uint16 x2) ;
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */

/* IIR8Filter(7/8prev + 1/8cur) filter function prototype - RawCounts only */
#if (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR8_FILTER)
    uint16 CapSense_1_IIR8Filter(uint16 x1, uint16 x2) ;
#endif /* End CapSense_1_RAW_FILTER_MASK */

/* IIR16Filter(15/16prev + 1/16cur) filter function prototype - RawCounts only */
#if (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR16_FILTER)
    uint16 CapSense_1_IIR16Filter(uint16 x1, uint16 x2) ;
#endif /* End CapSense_1_RAW_FILTER_MASK */

/* JitterFilter filter function prototype */
#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_JITTER_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_JITTER_FILTER) )
    uint16 CapSense_1_JitterFilter(uint16 x1, uint16 x2) ;
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */

/* Storage of filters data */
#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_MEDIAN_FILTER) || \
      (CapSense_1_RAW_FILTER_MASK & CapSense_1_AVERAGING_FILTER) )

    uint16 CapSense_1_rawFilterData1[CapSense_1_TOTAL_SENSOR_COUNT];
    uint16 CapSense_1_rawFilterData2[CapSense_1_TOTAL_SENSOR_COUNT];

#elif ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR2_FILTER)   || \
        (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR4_FILTER)   || \
        (CapSense_1_RAW_FILTER_MASK & CapSense_1_JITTER_FILTER) || \
        (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR8_FILTER)   || \
        (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR16_FILTER) )
        
    uint16 CapSense_1_rawFilterData1[CapSense_1_TOTAL_SENSOR_COUNT];

#else
    /* No Raw filters */
#endif  /* End CapSense_1_RAW_FILTER_MASK */

extern uint16 CapSense_1_SensorRaw[CapSense_1_TOTAL_SENSOR_COUNT];
extern uint8 CapSense_1_SensorEnableMask[(((CapSense_1_TOTAL_SENSOR_COUNT - 1u) / 8u) + 1u)];
extern const uint8 CYCODE CapSense_1_widgetNumber[];

uint16 CapSense_1_SensorBaseline[CapSense_1_TOTAL_SENSOR_COUNT] = {0u};
uint8 CapSense_1_SensorBaselineLow[CapSense_1_TOTAL_SENSOR_COUNT] = {0u};
uint8 CapSense_1_SensorSignal[CapSense_1_TOTAL_SENSOR_COUNT] = {0u};
uint8 CapSense_1_SensorOnMask[(((CapSense_1_TOTAL_SENSOR_COUNT - 1u) / 8u) + 1u)] = {0u};

/* Helps while centroid calulation */
#if (CapSense_1_TOTAL_CENTROIDS_COUNT)
    static uint8 CapSense_1_centroid[3];
#endif  /* End (CapSense_1_TOTAL_CENTROIDS_COUNT) */


const uint8 CYCODE CapSense_1_fingerThreshold[] = {
    100u, 
};

const uint8 CYCODE CapSense_1_noiseThreshold[] = {
    20u, 
};

const uint8 CYCODE CapSense_1_hysteresis[] = {
    10u, 
};

const uint8 CYCODE CapSense_1_debounce[] = {
    5u, 
};

uint8 CapSense_1_debounceCounter[] = {
    0u, 0u, 
};

const uint8 CYCODE CapSense_1_rawDataIndex[] = {
    0u, /* DummyWidget__BTN */

};

const uint8 CYCODE CapSense_1_numberOfSensors[] = {
    1u, /* DummyWidget__BTN */

};



#if (CapSense_1_TOTAL_TOUCH_PADS_COUNT)
    uint8 CapSense_1_position[CapSense_1_TOTAL_CENTROIDS_COUNT] = {0xFFu};
#endif  /* End (CapSense_1_TOTAL_TOUCH_PADS_COUNT) */


/*******************************************************************************
* Function Name: CapSense_1_BaseInit
********************************************************************************
*
* Summary:
*  Loads the CapSense_1_SensorBaseline[sensor] array element with an 
*  initial value which qual raw count value. 
*  Resets to zero CapSense_1_SensorBaselineLow[senesor] and 
*  CapSense_1_SensorSignal[sensor] array element.
*  Loads CapSense_1_debounceCounter[sensor] array element with initial 
*  value equal CapSense_1_debounce[].
*  Loads the CapSense_1_rawFilterData2[sensor] and 
*  CapSense_1_rawFilterData2[sensor] array element with an 
*  initial value which qual raw count value if raw data filter is enabled.
*
* Parameters:
*  sensor:  Sensor number.
*
* Return:
*  None
*
* Global Variables:
*  CapSense_1_SensorBaseline[]    - used to store baseline value.
*  CapSense_1_SensorBaselineLow[] - used to store fraction byte of 
*  baseline value.
*  CapSense_1_SensorSignal[]      - used to store diffence between 
*  current value of raw data and previous value of baseline.
*  CapSense_1_debounceCounter[]   - used to store current debounce 
*  counter of sensor. Widget which has this parameter are buttons, matrix 
*  buttons, proximity, guard. All other widgets haven't debounce parameter
*  and use the last element of this array with value 0 (it means no debounce).
*  CapSense_1_rawFilterData1[]    - used to store previous sample of 
*  any enabled raw data filter.
*  CapSense_1_rawFilterData2[]    - used to store before previous sample
*  of enabled raw data filter. Only required for median or average filters.
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_BaseInit(uint8 sensor)
{
    #if ((CapSense_1_TOTAL_BUTTONS_COUNT) || (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT) || \
         (CapSense_1_TOTAL_GENERICS_COUNT))
        uint8 widget = CapSense_1_widgetNumber[sensor];
    #endif /* ((CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT) || (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT)) */
    
    #if (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT)
        uint8 debounceIndex;
    #endif  /* End (CapSense_1_TOTAL_MATRIX_BUTTONS_COUNT != 0u) */
    
    #if (CapSense_1_TOTAL_GENERICS_COUNT)
        /* Exclude generic widget */
        if(widget < CapSense_1_END_OF_WIDGETS_INDEX)
        {
    #endif  /* End CapSense_1_TOTAL_GENERICS_COUNT */
    
    /* Initialize Baseline */
    CapSense_1_SensorBaseline[sensor] = CapSense_1_SensorRaw[sensor];
    CapSense_1_SensorBaselineLow[sensor] = 0u;
    CapSense_1_SensorSignal[sensor] = 0u;
        
    CapSense_1_debounceCounter[widget] =  CapSense_1_debounce[widget];

    
    #if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_MEDIAN_FILTER) || \
          (CapSense_1_RAW_FILTER_MASK & CapSense_1_AVERAGING_FILTER) )
    
        CapSense_1_rawFilterData1[sensor] = CapSense_1_SensorRaw[sensor];
        CapSense_1_rawFilterData2[sensor] = CapSense_1_SensorRaw[sensor];
    
    #elif ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR2_FILTER)   || \
            (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR4_FILTER)   || \
            (CapSense_1_RAW_FILTER_MASK & CapSense_1_JITTER_FILTER) || \
            (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR8_FILTER)   || \
            (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR16_FILTER) )
            
        CapSense_1_rawFilterData1[sensor] = CapSense_1_SensorRaw[sensor];
    
    #else
        /* No Raw filters */
    #endif  /* End CapSense_1_RAW_FILTER_MASK */
    
    #if (CapSense_1_TOTAL_GENERICS_COUNT)
        /* Exclude generic widget */
        }
    #endif  /* End CapSense_1_TOTAL_GENERICS_COUNT */
}


/*******************************************************************************
* Function Name: CapSense_1_InitializeSensorBaseline
********************************************************************************
*
* Summary:
*  Loads the CapSense_1_SensorBaseline[sensor] array element with an 
*  initial value by scanning the selected sensor (one channel design) or pair 
*  of sensors (two channels designs). The raw count value is copied into the 
*  baseline array for each sensor. The raw data filters are initialized if 
*  enabled.
*
* Parameters:
*  sensor:  Sensor number.
*
* Return:
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_InitializeSensorBaseline(uint8 sensor)
{
    /* Scan sensor */
    CapSense_1_ScanSensor(sensor);
        while(CapSense_1_IsBusy() != 0u) {;}
    
    #if (CapSense_1_DESIGN_TYPE == CapSense_1_ONE_CHANNEL_DESIGN)
        /* Initialize Baseline, Signal and debounce counters */       
        CapSense_1_BaseInit(sensor);
        
    #else
    
        if(sensor < CapSense_1_TOTAL_SENSOR_COUNT__CH0)
        {
            /* Initialize Baseline, Signal and debounce counters */ 
            CapSense_1_BaseInit(sensor);
        }
        
        if(sensor < CapSense_1_TOTAL_SENSOR_COUNT__CH1)
        {
            /* Initialize Baseline, Signal and debounce counters */
            CapSense_1_BaseInit(sensor + CapSense_1_TOTAL_SENSOR_COUNT__CH0);
        }
    
    #endif  /* End (CapSense_1_DESIGN_TYPE == CapSense_1_ONE_CHANNEL_DESIGN) */
}


/*******************************************************************************
* Function Name: CapSense_1_InitializeAllBaselines
********************************************************************************
*
* Summary:
*  Uses the CapSense_1_InitializeSensorBaseline function to loads the 
*  CapSense_1_SensorBaseline[] array with an initial values by scanning 
*  all sensors. The raw count values are copied into the baseline array for 
*  all sensors. The raw data filters are initialized if enabled.
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
void CapSense_1_InitializeAllBaselines(void)
{
    uint8 i;
    
    /* The baseline initialize by sensor of sensor pair */
    for(i = 0u; i < CapSense_1_TOTAL_SCANSLOT_COUNT; i++)
    {
        CapSense_1_InitializeSensorBaseline(i);
    }
}


#if (CapSense_1_DESIGN_TYPE == CapSense_1_TWO_CHANNELS_DESIGN)
    /*******************************************************************************
    * Function Name: CapSense_1_InitializeEnabledBaselines
    ********************************************************************************
    *
    * Summary:
    *  Scans all enabled widgets and the raw count values are copied into the 
    *  baseline array for all sensors enabled in scanning process. Baselines 
    *  initialize with zero values for sensors disabled from scanning process. 
    *  The raw data filters are initialized if enabled.
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
    void CapSense_1_InitializeEnabledBaselines(void)
    {
        uint8 i;
        uint8 pos;
        uint8 enMask;
        
        CapSense_1_ScanEnabledWidgets();
        while(CapSense_1_IsBusy() != 0u){;}
        
        for(i = 0u; i < CapSense_1_TOTAL_SENSOR_COUNT; i++)
        {
            pos = (i >> 3u);
            enMask = 0x01u << (i & 0x07u);
            
            /* Clear raw data if sensor is disabled from scanning process */
            if((CapSense_1_SensorEnableMask[pos] & enMask) == 0u)
            {
                CapSense_1_SensorRaw[i] = 0u;
            }
            
            /* Initialize baselines */
            CapSense_1_BaseInit(i);
        }
    }  
#endif  /* End (CapSense_1_DESIGN_TYPE == CapSense_1_TWO_CHANNELS_DESIGN) */


/*******************************************************************************
* Function Name: CapSense_1_UpdateSensorBaseline
********************************************************************************
*
* Summary:
*  Updates the CapSense_1_SensorBaseline[sensor] array element using the 
*  LP filter with k = 256. The signal calculates the difference of count by 
*  subtracting the previous baseline from the current raw count value and stores
*  it in CapSense_1_SensorSignal[sensor]. 
*  If auto reset option is enabled the baseline updated regards noise threshold. 
*  If auto reset option is disabled the baseline stops updating if signal is 
*  greater that zero and baseline loads with raw count value if signal is less 
*  that noise threshold.
*  Raw data filters are applied to the values if enabled before baseline 
*  calculation.
*
* Parameters:
*  sensor:  Sensor number.
*
* Return:
*  None
*
* Global Variables:
*  CapSense_1_SensorBaseline[]    - used to store baseline value.
*  CapSense_1_SensorBaselineLow[] - used to store fraction byte of 
*  baseline value.
*  CapSense_1_SensorSignal[]      - used to store diffence between 
*  current value of raw data and previous value of baseline.
*  CapSense_1_rawFilterData1[]    - used to store previous sample of 
*  any enabled raw data filter.
*  CapSense_1_rawFilterData2[]    - used to store before previous sample
*  of enabled raw data filter. Only required for median or average filters.
*
* Reentrant:
*  No
*
*******************************************************************************/
 void CapSense_1_UpdateSensorBaseline(uint8 sensor)
{
    uint32 calc;
    uint16 tempRaw;
    uint16 filteredRawData;
    uint8 widget = CapSense_1_widgetNumber[sensor];
    uint8 noiseThreshold = CapSense_1_noiseThreshold[widget];
    
    #if (CapSense_1_TOTAL_GENERICS_COUNT)
        /* Exclude generic widget */
        if(widget < CapSense_1_END_OF_WIDGETS_INDEX)
        {
    #endif  /* End CapSense_1_TOTAL_GENERICS_COUNT */
    
    filteredRawData = CapSense_1_SensorRaw[sensor];
    
    #if (CapSense_1_RAW_FILTER_MASK & CapSense_1_MEDIAN_FILTER)
        tempRaw = filteredRawData;
        filteredRawData = CapSense_1_MedianFilter(filteredRawData, CapSense_1_rawFilterData1[sensor], 
                                                        CapSense_1_rawFilterData2[sensor]);
        CapSense_1_rawFilterData2[sensor] = CapSense_1_rawFilterData1[sensor];
        CapSense_1_rawFilterData1[sensor] = tempRaw;
        
    #elif (CapSense_1_RAW_FILTER_MASK & CapSense_1_AVERAGING_FILTER)
        tempRaw = filteredRawData;
        filteredRawData = CapSense_1_AveragingFilter(filteredRawData, CapSense_1_rawFilterData1[sensor],
                                                           CapSense_1_rawFilterData2[sensor]);
        CapSense_1_rawFilterData2[sensor] = CapSense_1_rawFilterData1[sensor];
        CapSense_1_rawFilterData1[sensor] = tempRaw;
        
    #elif (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR2_FILTER)
        filteredRawData = CapSense_1_IIR2Filter(filteredRawData, CapSense_1_rawFilterData1[sensor]);
        CapSense_1_rawFilterData1[sensor] = filteredRawData;
        
    #elif (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR4_FILTER)
        filteredRawData = CapSense_1_IIR4Filter(filteredRawData, CapSense_1_rawFilterData1[sensor]);
        CapSense_1_rawFilterData1[sensor] = filteredRawData;
            
    #elif (CapSense_1_RAW_FILTER_MASK & CapSense_1_JITTER_FILTER)
        filteredRawData = CapSense_1_JitterFilter(filteredRawData, CapSense_1_rawFilterData1[sensor]);
        CapSense_1_rawFilterData1[sensor] = filteredRawData;
        
    #elif (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR8_FILTER)
        filteredRawData = CapSense_1_IIR8Filter(filteredRawData, CapSense_1_rawFilterData1[sensor]);
        CapSense_1_rawFilterData1[sensor] = filteredRawData;
        
    #elif (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR16_FILTER)
        filteredRawData = CapSense_1_IIR16Filter(filteredRawData, CapSense_1_rawFilterData1[sensor]);
        CapSense_1_rawFilterData1[sensor] = filteredRawData;
        
    #else
        /* No Raw filters */
    #endif  /* End CapSense_1_RAW_FILTER_MASK */
    
    #if (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING)
        CapSense_1_CalculateThresholds(sensor);
    #endif /* End (CapSense_1_TUNING_METHOD == CapSense_1_AUTO_TUNING) */
    
    /* Baseline calculation */
    #if (CapSense_1_AUTO_RESET == CapSense_1_AUTO_RESET_DISABLE)
        
        /* Calculate difference RawData[cur] - Baseline[prev] */
        if(filteredRawData >= CapSense_1_SensorBaseline[sensor])
        {
            tempRaw = filteredRawData - CapSense_1_SensorBaseline[sensor];
            widget = 1u;        /* Positive difference */
        }
        else
        {
            tempRaw = CapSense_1_SensorBaseline[sensor] - filteredRawData;
            widget = 0u;        /* Negative difference */
        }
        
        /* Update Baseline if lower that noiseThreshold */
        if (tempRaw <= (uint16) noiseThreshold)
        {
            /* Make full Baseline 23 bits */
            calc = (uint32) CapSense_1_SensorBaseline[sensor] << 8u;
            calc |= (uint32) CapSense_1_SensorBaselineLow[sensor];
            
            /* Add Raw Data to Baseline */
            calc += filteredRawData;
            
            /* Sub the high Baseline */
            calc -= CapSense_1_SensorBaseline[sensor];
            
            /* Put Baseline and BaselineLow */
            CapSense_1_SensorBaseline[sensor] = ((uint16) (calc >> 8u));
            CapSense_1_SensorBaselineLow[sensor] = ((uint8) calc);
            
            /* Signal is zero */
            CapSense_1_SensorSignal[sensor] = 0u;
        }
        /* Calculate Signal if possitive difference > noiseThreshold */
        else if (widget != 0u)
        {
            #if (CapSense_1_SIGNAL_SIZE == CapSense_1_SIGNAL_SIZE_UINT8)
                /* Over flow defence for uint8 */
                if (tempRaw > 0xFFu)
                {
                    CapSense_1_SensorSignal[sensor] = 0xFFu;
                }    
                else 
                {
                    CapSense_1_SensorSignal[sensor] = ((uint8) tempRaw);
                }
            #else
                CapSense_1_SensorSignal[sensor] = ((uint16) tempRaw);
                
            #endif  /* End CapSense_1_SIGNAL_SIZE */
        }
        /* Reinitialize if negative difference > noiseThreshold */
        else
        {
            /* Baseline and BaselineLow re-init */
            CapSense_1_SensorBaseline[sensor] = filteredRawData;
            CapSense_1_SensorBaselineLow[sensor] = 0u;
            
            /* Signal is zero */
            CapSense_1_SensorSignal[sensor] = 0u;
        }
    
    #else
        /* Calculate difference RawData[cur] - Baseline[prev] */
        if(filteredRawData >= CapSense_1_SensorBaseline[sensor])
        {
            tempRaw = filteredRawData - CapSense_1_SensorBaseline[sensor];
            widget = 1u;    /* Calculate the Signal */
        }
        else
        {
            tempRaw = CapSense_1_SensorBaseline[sensor] - filteredRawData;
            widget = 0u;    /* Do NOT calculate the Signal */
        }
        
        if((tempRaw > (uint16) noiseThreshold) && (widget != 0u))
        {
            #if (CapSense_1_SIGNAL_SIZE == CapSense_1_SIGNAL_SIZE_UINT8)
                /* Over flow defence for uint8 */
                if (tempRaw > 0xFFu)
                {
                    CapSense_1_SensorSignal[sensor] = 0xFFu;
                }    
                else 
                {
                    CapSense_1_SensorSignal[sensor] = ((uint8) tempRaw);
                }
            #else
                CapSense_1_SensorSignal[sensor] = ((uint16) tempRaw);
                
            #endif  /* End CapSense_1_SIGNAL_SIZE */
        }
        else
        {
            /* Signal is zero */
            CapSense_1_SensorSignal[sensor] = 0u;
        }
        
        /* Update Baseline */
        /* Make full Baseline 23 bits */
        calc = (uint32) CapSense_1_SensorBaseline[sensor] << 8u;
        calc |= (uint32) CapSense_1_SensorBaselineLow[sensor];
        
        /* Add Raw Data to Baseline */
        calc += filteredRawData;
        
        /* Sub the high Baseline */
        calc -= CapSense_1_SensorBaseline[sensor];
        
        /* Put Baseline and BaselineLow */
        CapSense_1_SensorBaseline[sensor] = ((uint16) (calc >> 8u));
        CapSense_1_SensorBaselineLow[sensor] = ((uint8) calc);
     
    #endif  /* End (CapSense_1_AUTO_RESET == CapSense_1_AUTO_RESET_DISABLE) */
    
    #if (CapSense_1_TOTAL_GENERICS_COUNT)
        /* Exclude generic widget */
        }
    #endif  /* End CapSense_1_TOTAL_GENERICS_COUNT */
}


/*******************************************************************************
* Function Name: CapSense_1_UpdateEnabledBaselines
********************************************************************************
*
* Summary:
*  Checks CapSense_1_SensorEnableMask[] array and calls the 
*  CapSense_1_UpdateSensorBaseline function to update the baselines 
*  for enabled sensors.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  CapSense_1_SensorEnableMask[] - used to store the sensor scanning 
*  state.
*  CapSense_1_SensorEnableMask[0] contains the masked bits for sensors 
*   0 through 7 (sensor 0 is bit 0, sensor 1 is bit 1).
*  CapSense_1_SensorEnableMask[1] contains the masked bits for 
*  sensors 8 through 15 (if needed), and so on.
*  0 - sensor doesn't scan by CapSense_1_ScanEnabledWidgets().
*  1 - sensor scans by CapSense_1_ScanEnabledWidgets().
*
* Reentrant:
*  No
*
*******************************************************************************/
 void CapSense_1_UpdateEnabledBaselines(void)
{
    uint8 i;
    uint8 pos;
    uint8 enMask;
    
    for(i = 0; i < CapSense_1_TOTAL_SENSOR_COUNT; i++)
    {
        pos = (i >> 3u);
        enMask = 0x01u << (i & 0x07u);
        if((CapSense_1_SensorEnableMask[pos] & enMask) != 0u)
        {
            CapSense_1_UpdateSensorBaseline(i);
        }
    }
}


/*******************************************************************************
* Function Name: CapSense_1_CheckIsSensorActive
********************************************************************************
*
* Summary:
*  Compares the CapSense_1_SensorSignal[sensor] array element to finger
*  threshold of widget it belongs to. The hysteresis and debounce are taken into 
*  account. The hysteresis is added or subtracted from the finger threshold 
*  based on whether the sensor is currently active. 
*  If the sensor is active, the threshold is lowered by the hysteresis amount.
*  If the sensor is inactive, the threshold is raised by the hysteresis amount.
*  The debounce counter added to the sensor active transition.
*  This function updates CapSense_1_SensorOnMask[] array element.
*
* Parameters:
*  sensor:  Sensor number.
*
* Return:
*  Returns sensor state 1 if active, 0 if not active.
*
* Global Variables:
*  CapSense_1_SensorSignal[]      - used to store diffence between 
*  current value of raw data and previous value of baseline.
*  CapSense_1_debounceCounter[]   - used to store current debounce 
*  counter of sensor. Widget which has this parameter are buttons, matrix 
*  buttons, proximity, guard. All other widgets haven't debounce parameter
*  and use the last element of this array with value 0 (it means no debounce).
*  CapSense_1_SensorOnMask[] - used to store sensors on/off state.
*  CapSense_1_SensorOnMask[0] contains the masked bits for sensors 
*   0 through 7 (sensor 0 is bit 0, sensor 1 is bit 1).
*  CapSense_1_SensorEnableMask[1] contains the masked bits for 
*  sensors 8 through 15 (if needed), and so on.
*  0 - sensor is inactive.
*  1 - sensor is active.
*
* Reentrant:
*  No
*
*******************************************************************************/
uint8 CapSense_1_CheckIsSensorActive(uint8 sensor)
{
    uint8 debounceIndex;
    /* Get On/Off mask */
    uint8 pos = (sensor >> 3u);
    uint8 onMask = 0x01u << (sensor & 0x07u);
    /* Prepare to find debounce counter index */
    uint8 widget = CapSense_1_widgetNumber[sensor];
    uint8 fingerThreshold = CapSense_1_fingerThreshold[widget];
    uint8 hysteresis = CapSense_1_hysteresis[widget];
    uint8 debounce = CapSense_1_debounce[widget];
    
    debounceIndex = widget;

    
    /* Was on */
    if (CapSense_1_SensorOnMask[pos] & onMask)
    {
        /* Hysteresis minus */
        if (CapSense_1_SensorSignal[sensor] < (fingerThreshold - hysteresis))
        {
            CapSense_1_SensorOnMask[pos] &= ~onMask;
            CapSense_1_debounceCounter[debounceIndex] = debounce; 
        }
    }
    else    /* Was off */
    {
        /* Hysteresis plus */
        if (CapSense_1_SensorSignal[sensor] > (fingerThreshold + hysteresis))
        {
            /* Sensor active, decrement debounce counter */
            if (CapSense_1_debounceCounter[debounceIndex]-- == 0)
            {
                CapSense_1_SensorOnMask[pos] |= onMask; 
            }
        }
        else
        {
            /* Sensor inactive - reset Debounce counter */
            CapSense_1_debounceCounter[debounceIndex] = debounce;
        }
    }
    
    return (CapSense_1_SensorOnMask[pos] & onMask) ? 1u : 0u;
}


/*******************************************************************************
* Function Name: CapSense_1_CheckIsWidgetActive
********************************************************************************
*
* Summary:
*  Use function CapSense_1_CheckIsSensorActive() to update 
*  CapSense_1_SensorOnMask[] for all sensors within the widget.
*  If one of sensors within widget is active the function return that widget is 
*  active.
*  The touch pad and matrix buttons widgets need to have active sensor within 
*  col and row to return widget active status.
*
* Parameters:
*  widget:  widget number.
*
* Return:
*  Returns widget sensor state 1 if one or more sensors within widget is/are 
*  active, 0 if all sensors within widget are inactive.
*
* Reentrant:
*  No
*
*******************************************************************************/
uint8 CapSense_1_CheckIsWidgetActive(uint8 widget)
{
    uint8 rawIndex = CapSense_1_rawDataIndex[widget];
    uint8 numberOfSensors = CapSense_1_numberOfSensors[widget] + rawIndex;
    uint8 state = 0u;

    /* Check all sensors of the widget */
    do
    {
        if(CapSense_1_CheckIsSensorActive(rawIndex) != 0u)
        {
            state = CapSense_1_SENSOR_1_IS_ACTIVE;
        }
        rawIndex++;
    }
    while(rawIndex < numberOfSensors);
    

    
    return state;
}


/*******************************************************************************
* Function Name: CapSense_1_CheckIsAnyWidgetActive
********************************************************************************
*
* Summary:
*  Compares all sensors of the CapSense_1_Signal[] array to their finger 
*  threshold. Calls CapSense_1_CheckIsWidgetActive() for each widget so 
*  the CapSense_1_SensorOnMask[] array is up to date after calling this 
*  function.
*
* Parameters:
*  widget:  widget number.
*
* Return:
*  Returns 1 if any widget is active, 0 none of widgets are active.
*
* Reentrant:
*  No
*
*******************************************************************************/
uint8 CapSense_1_CheckIsAnyWidgetActive(void)
{
    uint8 i;
    uint8 state = 0u;
    
    for(i = 0u; i < CapSense_1_TOTAL_WIDGET_COUNT; i++)
    {
        if (CapSense_1_CheckIsWidgetActive(i) != 0u)
        {
            state = CapSense_1_WIDGET_IS_ACTIVE;
        }
    }
    

    return state;
}


/*******************************************************************************
* Function Name: CapSense_1_EnableWidget
********************************************************************************
*
* Summary:
*  Enable all widget elements (sensors) to scanning process.
*
* Parameters:
*  widget:  widget number.
*
* Return:
*  None
*
* Global Variables:
*  CapSense_1_SensorEnableMask[] - used to store the sensor scanning 
*  state.
*  CapSense_1_SensorEnableMask[0] contains the masked bits for sensors 
*  0 through 7 (sensor 0 is bit 0, sensor 1 is bit 1).
*  CapSense_1_SensorEnableMask[1] contains the masked bits for 
*  sensors 8 through 15 (if needed), and so on.
*  0 - sensor doesn't scan by CapSense_1_ScanEnabledWidgets().
*  1 - sensor scans by CapSense_1_ScanEnabledWidgets().
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_EnableWidget(uint8 widget)
{
    uint8 pos;
    uint8 enMask;
    uint8 rawIndex = CapSense_1_rawDataIndex[widget];
    uint8 numberOfSensors = CapSense_1_numberOfSensors[widget] + rawIndex;
    
    /* Enable all sensors of the widget */
    do
    {
        pos = (rawIndex >> 3u);
        enMask = 0x01u << (rawIndex & 0x07u);
        
        CapSense_1_SensorEnableMask[pos] |= enMask;
        rawIndex++;
    }
    while(rawIndex < numberOfSensors);
    

}


/*******************************************************************************
* Function Name: CapSense_1_DisableWidget
********************************************************************************
*
* Summary:
*  Disable all widget elements (sensors) from scanning process.
*
* Parameters:
*  widget:  widget number.
*
* Return:
*  None
*
* Global Variables:
*  CapSense_1_SensorEnableMask[] - used to store the sensor scanning 
*  state.
*  CapSense_1_SensorEnableMask[0] contains the masked bits for sensors 
*  0 through 7 (sensor 0 is bit 0, sensor 1 is bit 1).
*  CapSense_1_SensorEnableMask[1] contains the masked bits for 
*  sensors 8 through 15 (if needed), and so on.
*  0 - sensor doesn't scan by CapSense_1_ScanEnabledWidgets().
*  1 - sensor scans by CapSense_1_ScanEnabledWidgets().
*
* Reentrant:
*  No
*
*******************************************************************************/
void CapSense_1_DisableWidget(uint8 widget)
{
    uint8 pos;
    uint8 enMask;
    uint8 rawIndex = CapSense_1_rawDataIndex[widget];
    uint8 numberOfSensors = CapSense_1_numberOfSensors[widget] + rawIndex;
   
    /* Disable all sensors of the widget */
    do
    {
        pos = (rawIndex >> 3u);
        enMask = 0x01u << (rawIndex & 0x07u);
        
        CapSense_1_SensorEnableMask[pos] &= ~enMask;
        rawIndex++;
    }
    while(rawIndex < numberOfSensors);
    

}




#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_MEDIAN_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_MEDIAN_FILTER) )
    /*******************************************************************************
    * Function Name: CapSense_1_MedianFilter
    ********************************************************************************
    *
    * Summary:
    *  Median filter function. 
    *  The median filter looks at the three most recent samples and reports the 
    *  median value.
    *
    * Parameters:
    *  x1:  Current value.
    *  x2:  Previous value.
    *  x3:  Before previous value.
    *
    * Return:
    *  Returns filtered value.
    *
    *******************************************************************************/
    uint16 CapSense_1_MedianFilter(uint16 x1, uint16 x2, uint16 x3) \
                                         
    {
        uint16 tmp;
        
        if (x1 > x2)
        {
            tmp = x2;
            x2 = x1;
            x1 = tmp;
        }
        
        if (x2 > x3)
        {
            x2 = x3;
        }
        
        return ((x1 > x2) ? x1 : x2);
    }
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */


#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_AVERAGING_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_AVERAGING_FILTER) )
    /*******************************************************************************
    * Function Name: CapSense_1_AveragingFilter
    ********************************************************************************
    *
    * Summary:
    *  Averaging filter function.
    *  The averaging filter looks at the three most recent samples of position and
    *  reports the averaging value.
    *
    * Parameters:
    *  x1:  Current value.
    *  x2:  Previous value.
    *  x3:  Before previous value.
    *
    * Return:
    *  Returns filtered value.
    *
    *******************************************************************************/
    uint16 CapSense_1_AveragingFilter(uint16 x1, uint16 x2, uint16 x3) \
                                            
    {
        uint32 tmp = ((uint32)x1 + (uint32)x2 + (uint32)x3) / 3u;
        
        return ((uint16) tmp);
    }
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */


#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR2_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_IIR2_FILTER) )
    /*******************************************************************************
    * Function Name: CapSense_1_IIR2Filter
    ********************************************************************************
    *
    * Summary:
    *  IIR1/2 filter function. IIR1/2 = 1/2current + 1/2previous.
    *
    * Parameters:
    *  x1:  Current value.
    *  x2:  Previous value.
    *
    * Return:
    *  Returns filtered value.
    *
    *******************************************************************************/
    uint16 CapSense_1_IIR2Filter(uint16 x1, uint16 x2) \
                                       
    {
        uint32 tmp;
        
        /* IIR = 1/2 Current Value+ 1/2 Previous Value */
        tmp = (uint32)x1 + (uint32)x2;
        tmp >>= 1u;
    
        return ((uint16) tmp);
    }
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */


#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR4_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_IIR4_FILTER) )
    /*******************************************************************************
    * Function Name: CapSense_1_IIR4Filter
    ********************************************************************************
    *
    * Summary:
    *  IIR1/4 filter function. IIR1/4 = 1/4current + 3/4previous.
    *
    * Parameters:
    *  x1:  Current value.
    *  x2:  Previous value.
    *
    * Return:
    *  Returns filtered value.
    *
    *******************************************************************************/
    uint16 CapSense_1_IIR4Filter(uint16 x1, uint16 x2) \
                                       
    {
        uint32 tmp;
        
        /* IIR = 1/4 Current Value + 3/4 Previous Value */
        tmp = (uint32)x1 + (uint32)x2;
        tmp += ((uint32)x2 << 1u);
        tmp >>= 2u;
        
        return ((uint16) tmp);
    }
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */


#if ( (CapSense_1_RAW_FILTER_MASK & CapSense_1_JITTER_FILTER) || \
      (CapSense_1_POS_FILTERS_MASK & CapSense_1_JITTER_FILTER) )
    /*******************************************************************************
    * Function Name: uint16 CapSense_1_JitterFilter
    ********************************************************************************
    *
    * Summary:
    *  Jitter filter function.
    *
    * Parameters:
    *  x1:  Current value.
    *  x2:  Previous value.
    *
    * Return:
    *  Returns filtered value.
    *
    *******************************************************************************/
    uint16 CapSense_1_JitterFilter(uint16 x1, uint16 x2) \
                                         
    {
        if (x1 > x2)
        {
            x1--;
        }
        else
        {
            if (x1 < x2)
            {
                x1++;
            }
        }
    
        return x1;
    }
#endif /* End CapSense_1_RAW_FILTER_MASK && CapSense_1_POS_FILTERS_MASK */


#if (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR8_FILTER)
    /*******************************************************************************
    * Function Name: CapSense_1_IIR8Filter
    ********************************************************************************
    *
    * Summary:
    *  IIR1/8 filter function. IIR1/8 = 1/8current + 7/8previous.
    *  Only applies for raw data.
    *
    * Parameters:
    *  x1:  Current value.
    *  x2:  Previous value.
    *
    * Return:
    *  Returns filtered value.
    *
    *******************************************************************************/
    uint16 CapSense_1_IIR8Filter(uint16 x1, uint16 x2) \
                                       
    {
        uint32 tmp;
        
        /* IIR = 1/8 Current Value + 7/8 Previous Value */
        tmp = (uint32)x1;
        tmp += (((uint32)x2 << 3u) - ((uint32)x2));
        tmp >>= 3u;
    
        return ((uint16) tmp);
    }
#endif /* End (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR8_FILTER) */


#if (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR16_FILTER)
    /*******************************************************************************
    * Function Name: CapSense_1_IIR16Filter
    ********************************************************************************
    *
    * Summary:
    *  IIR1/16 filter function. IIR1/16 = 1/16current + 15/16previous.
    *  Only applies for raw data.
    *
    * Parameters:
    *  x1:  Current value.
    *  x2:  Previous value.
    *
    * Return:
    *  Returns filtered value.
    *
    *******************************************************************************/
    uint16 CapSense_1_IIR16Filter(uint16 x1, uint16 x2) \
                                        
    {
        uint32 tmp;
        
        /* IIR = 1/16 Current Value + 15/16 Previous Value */
        tmp = (uint32)x1;
        tmp += (((uint32)x2 << 4u) - ((uint32)x2));
        tmp >>= 4u;
        
        return ((uint16) tmp);
    }
#endif /* End (CapSense_1_RAW_FILTER_MASK & CapSense_1_IIR16_FILTER) */


/* [] END OF FILE */
