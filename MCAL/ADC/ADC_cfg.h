/****************************************/
/* Author      : Ahmed Alaa             */
/* Description : ADC configuration file */
/* Date        : 13 DEC 19    		    */
/* Version     : 1.0V        		    */
/****************************************/
#ifndef ADC_CFG_H
#define ADC_CFG_H

/** INT_VREF (2.56 V), AVCC or AREF **/
#define ADC_u8VREF 	INT_VREF


/** ADC_8BIT or ADC_10BIT **/
#define ADC_u8MODE  ADC_8BIT


/** prescaler options : PRE_2, PRE_4, PRE_8, PRE_16, PRE_32, PRE_64, PRE_128 **/
#define ADC_u8PRESCALER PRE_32

#endif           