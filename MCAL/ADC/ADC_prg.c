/****************************************************/
/* Author      : Ahmed Alaa            		        */
/* Description : ADC's  functions implementations   */
/* Date        : 13 DEC 19    				        */
/* Version     : 1.0V        				        */
/****************************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"

PF ADC_pfAddress;

/** function to initiate ADC peripheral **/
void ADC_voidInit(void)
{
	/** Enable ADC */
	SET_BIT(ADCSRA,ADEN);
	
	/** VREf config */
	#if ADC_u8VREF == INT_VREF
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	#elif ADC_u8VREF == AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	#else 
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	#endif
	
	/**ADC MODE ADLAR config */
	#if ADC_u8MODE == ADC_8BIT
	SET_BIT(ADMUX,ADLAR);
	#else // ADC_10BIT
	CLR_BIT(ADMUX,ADLAR);
	#endif
	
	/** prescaler config */
	ADCSRA = ADCSRA & 0b11111000;   			// first clear first 3 bit (masking)
	ADCSRA = ADCSRA | ADC_u8PRESCALER;			// then add ADC_u8PRESCALER to ADCSRA
	
	/** disable IRQ , clear ADC flag and disable start conversion */
	CLR_BIT(ADCSRA,ADIE);
	SET_BIT(ADCSRA,ADIF);    	// SET ADIF to clear ADC flag bit as mentioned in datasheet 
	CLR_BIT(ADCSRA,ADSC);
	
	/** one shot (not auto trigger)*/
	CLR_BIT(ADCSRA,ADATE);
}


/** function to get digital value in 8-bit mode or 10-bit mode (depends on user configuration) and pass channel no. to it**/
#if ADC_u8MODE == ADC_8BIT
u8 ADC_u8GetDigitalValueSync (u8 u8ChannelNbCpy)
{
	ADMUX = ADMUX & 0b11100000;
	ADMUX = ADMUX | u8ChannelNbCpy;
	
	SET_BIT(ADCSRA,ADSC);
	
	while(GET_BIT(ADCSRA,ADIF) == 0);
	
	SET_BIT(ADCSRA,ADIF);
	
	return ADCH;
}


#else 
u16 ADC_u16GetDigitalValueSync (u8 u8ChannelNbCpy)
{
	u8 u8LowValueLoc;
	u16 u16ReturnValueLoc;
	
	ADMUX = ADMUX & 0b11100000;
	ADMUX = ADMUX | u8ChannelNbCpy;
	
	SET_BIT(ADCSRA,ADSC);
	
	while(GET_BIT(ADCSRA,ADIF) == 0);
	
	u8LowValueLoc = ADCL;
	u16ReturnValueLoc = ((ADCH<<8) | u8LowValueLoc) & 0x03FF; // 0x03FF = 0b0000 0011 1111 1111 
	
	SET_BIT(ADCSRA,ADIF);
	
	return u16ReturnValueLoc;
}

#endif

/**function to enable ADC peripheral **/
void ADC_voidEnable(void)
{
	SET_BIT(ADCSRA,ADEN);
}

/**function to disable ADC peripheral **/
void ADC_voidDisable(void
{
	CLR_BIT(ADCSRA,ADEN);
}


/**function to enable ADC interrupt (Interrupt Request) **/
void ADC_voidEnableIRQ(void)
{
	SET_BIT(ADCSRA,ADIE);
}

/**function to disable ADC interrupt (Interrupt Request) **/
void ADC_voidDisableIRQ(void)
{
	CLR_BIT(ADCSRA,ADIE);
}

/** function take the address of ADC ISR that defined in APP layer to be served **/
void ADC_voidSetCallBack(PF pfCpy)
{
	ADC_pfAddress = pfCpy;
}

/** function to start ADC conversion on and take channel no.**/
void ADC_voidStartConversion(u8 u8ChannelNbCpy)
{
	ADMUX = ADMUX & 0b11100000;
	ADMUX = ADMUX | u8ChannelNbCpy;
	SET_BIT(ADCSRA,ADSC);
}


/** function get last converted digital value**/
#if ADC_u8MODE == ADC_8BIT
u8 ADC_u8GetLastValue(void)
{
	return ADCH;
}

#else 
u16 ADC_u16GetLastValue (void)
{
	u8 u8LowValueLoc = ADCL;
	u16 u16ReturnValueLoc = ((ADCH<<8) | u8LowValueLoc) & 0x03FF; // 0x03FF = 0b0000 0011 1111 1111 
	return u16ReturnValueLoc;
}

#endif


/**      !comment: ADC interrupt service routine        */
void __vector_16 (void) __attribute__((signal,used));

void __vector_16 (void)
{
	ADC_pfAddress();
}