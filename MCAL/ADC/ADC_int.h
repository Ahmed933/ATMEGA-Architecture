/*****************************************/
/* Author      : Ahmed Alaa              */
/* Description : ADC interface file      */
/* Date        : 13 DEC 19    		     */
/* Version     : 1.0V   				 */
/*****************************************/

#ifndef ADC_INT_H
#define ADC_INT_H

#include "ADC_cfg.h"

#define ADC_8BIT 		24
#define ADC_10BIT		32


/** function to initiate ADC peripheral **/
void ADC_voidInit(void);


/** function to get digital value in 8-bit mode or 10-bit mode (depends on user configuration) and pass channel no. to it**/
#if ADC_u8MODE == ADC_8BIT
u8 ADC_u8GetDigitalValueSync (u8 u8ChannelNbCpy);

#else 
u16 ADC_u16GetDigitalValueSync (u8 u8ChannelNbCpy);

#endif

/**function to enable ADC peripheral **/
void ADC_voidEnable(void);

/**function to disable ADC peripheral **/
void ADC_voidDisable(void);


/**function to enable ADC interrupt (Interrupt Request) **/
void ADC_voidEnableIRQ(void);

/**function to disable ADC interrupt (Interrupt Request) **/
void ADC_voidDisableIRQ(void);

/** function take the address of ADC ISR that defined in APP layer to be served **/
void ADC_voidSetCallBack(PF pfCpy);

/** function to start ADC conversion on and take channel no.**/
void ADC_voidStartConversion(u8 u8ChannelNbCpy);


/** function get last converted digital value**/
#if ADC_u8MODE == ADC_8BIT
u8 ADC_u8GetLastValue(void);

#else 
u16 ADC_u16GetLastValue (void);

#endif



#endif
