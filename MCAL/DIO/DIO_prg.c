/**
 ** Author      : Ahmed El-Aref   
 ** Description : DIO Program For Functions' Implementation
 ** Date        : 22 NOV 19     
 ** Version     : 1.0V          
 **/

#include "STD_Types.h"
#include "Bit_math.h"

#include "DIO_int.h"
#include "DIO_cfg.h"
#include "DIO_priv.h"


/************************************************/
/** !comment : initialization function which    */
/**            define pins direction for DIO    */
/************************************************/
void DIO_voidInit(void)
{
	DDRA = conc(PORTA_B7, PORTA_B6, PORTA_B5, PORTA_B4, PORTA_B3, PORTA_B2, PORTA_B1, PORTA_B0);
	DDRB = conc(PORTB_B7, PORTB_B6, PORTB_B5, PORTB_B4, PORTB_B3, PORTB_B2, PORTB_B1, PORTB_B0);
	DDRC = conc(PORTC_B7, PORTC_B6, PORTC_B5, PORTC_B4, PORTC_B3, PORTC_B2, PORTC_B1, PORTC_B0);
	DDRD = conc(PORTD_B7, PORTD_B6, PORTD_B5, PORTD_B4, PORTD_B3, PORTD_B2, PORTD_B1, PORTD_B0);
}

/************************************************/
/** !comment : function to set pin as high (5V) */
/**            or low (0V) 					    */
/************************************************/
tenuErrorStatus DIO_enuSetPinValue(u8 u8PinNbCpy, u8 u8PinValueCpy)
{
	tenuErrorStatus rnuReturnLoc = OK;
	if(u8PinNbCpy <= PORTA_B7)
	{
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTA,u8PinNbCpy);
		}else
		{
			CLR_BIT(PORTA,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTB_B0 && u8PinNbCpy <= PORTB_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTB,u8PinNbCpy);
		}else
		{
			CLR_BIT(PORTB,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTC_B0 && u8PinNbCpy <= PORTC_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTC,u8PinNbCpy);
		}else
		{
			CLR_BIT(PORTC,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTD_B0 && u8PinNbCpy <= PORTD_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTD,u8PinNbCpy);
		}else
		{
			CLR_BIT(PORTD,u8PinNbCpy);
		}
	}else
	{
		rnuReturnLoc = INDEX_OUT_OF_RANGE;
	}
	return rnuReturnLoc;

}

/************************************************/
/** !comment : function to get pin valuue       */
/**            as high (5V)or low (0V) 		    */
/************************************************/

tenuErrorStatus DIO_enuGetPinValue(u8 u8PinNbCpy, u8* pu8PinValueCpy)
{
	tenuErrorStatus rnuReturnLoc = OK;
	if(u8PinNbCpy <= PORTA_B7)
	{
		*pu8PinValueCpy = GET_BIT(PINA, u8PinNbCpy);
		
	}else if(u8PinNbCpy>= PORTB_B0 && u8PinNbCpy <= PORTB_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		*pu8PinValueCpy = GET_BIT(PINB, u8PinNbCpy);
		
	}else if(u8PinNbCpy>= PORTC_B0 && u8PinNbCpy <= PORTC_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		*pu8PinValueCpy = GET_BIT(PINC, u8PinNbCpy);
		
	}else if(u8PinNbCpy>= PORTD_B0 && u8PinNbCpy <= PORTD_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		*pu8PinValueCpy = GET_BIT(PIND, u8PinNbCpy);
		
	}else
	{
		rnuReturnLoc = INDEX_OUT_OF_RANGE;
	}
	return rnuReturnLoc;
	
}


/************************************************/
/** !comment : function to set internal pull up */
/**            resistor for input pins 		    */
/************************************************/
tenuErrorStatus DIO_enuSetPullUp(u8 u8PinNbCpy, u8 u8pullUpStatusCpy)
{
	tenuErrorStatus rnuReturnLoc = OK;
	u8 u8PinDir;
	
	if(u8PinNbCpy <= PORTA_B7)
	{
		u8PinDir = GET_BIT(DDRA, u8PinNbCpy);
		if(u8PinDir == INPUT)
		{
			SET_BIT(PORTA,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTB_B0 && u8PinNbCpy <= PORTB_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		u8PinDir = GET_BIT(DDRB, u8PinNbCpy);
		if(u8PinDir == INPUT)
		{
			SET_BIT(PORTB,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTC_B0 && u8PinNbCpy <= PORTC_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		u8PinDir = GET_BIT(DDRC, u8PinNbCpy);
		if(u8PinDir == INPUT)
		{
			SET_BIT(PORTC,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTD_B0 && u8PinNbCpy <= PORTD_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		u8PinDir = GET_BIT(DDRD, u8PinNbCpy);
		if(u8PinDir == INPUT)
		{
			SET_BIT(PORTD,u8PinNbCpy);
		}
	}else
	{
		rnuReturnLoc = INDEX_OUT_OF_RANGE;
	}
	return rnuReturnLoc;
}