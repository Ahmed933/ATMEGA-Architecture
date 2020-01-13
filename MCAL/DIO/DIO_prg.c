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
	DDRA = conc(PORTA_B7_DIR, PORTA_B6_DIR, PORTA_B5_DIR, PORTA_B4_DIR, PORTA_B3_DIR, PORTA_B2_DIR, PORTA_B1_DIR, PORTA_B0_DIR);
	DDRB = conc(PORTB_B7_DIR, PORTB_B6_DIR, PORTB_B5_DIR, PORTB_B4_DIR, PORTB_B3_DIR, PORTB_B2_DIR, PORTB_B1_DIR, PORTB_B0_DIR);
	DDRC = conc(PORTC_B7_DIR, PORTC_B6_DIR, PORTC_B5_DIR, PORTC_B4_DIR, PORTC_B3_DIR, PORTC_B2_DIR, PORTC_B1_DIR, PORTC_B0_DIR);
	DDRD = conc(PORTD_B7_DIR, PORTD_B6_DIR, PORTD_B5_DIR, PORTD_B4_DIR, PORTD_B3_DIR, PORTD_B2_DIR, PORTD_B1_DIR, PORTD_B0_DIR);
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
