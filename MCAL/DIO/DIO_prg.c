/********************************/
/** Author      : Ahmed Alaa    */
/** Description : DIO interface */
/** Date        : 22 NOV 19     */
/** Version     : 1.0V          */
/********************************/

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
	DDRA = conc(u8PINDIR_7, u8PINDIR_6, u8PINDIR_5, u8PINDIR_4, u8PINDIR_3, u8PINDIR_2, u8PINDIR_1, u8PINDIR_0);
	DDRB = conc(u8PINDIR_15, u8PINDIR_14, u8PINDIR_13, u8PINDIR_12, u8PINDIR_11, u8PINDIR_10, u8PINDIR_9, u8PINDIR_8);
	DDRC = conc(u8PINDIR_23, u8PINDIR_22, u8PINDIR_21, u8PINDIR_20, u8PINDIR_19, u8PINDIR_18, u8PINDIR_17, u8PINDIR_16);
	DDRD = conc(u8PINDIR_31, u8PINDIR_30, u8PINDIR_29, u8PINDIR_28, u8PINDIR_27, u8PINDIR_26, u8PINDIR_25, u8PINDIR_24);
}

/************************************************/
/** !comment : function to set pin as high (5V) */
/**            or low (0V) 					    */
/************************************************/
tenuErrorStatus DIO_enuSetPinValue(u8 u8PinNbCpy, u8 u8PinValueCpy)
{
	tenuErrorStatus rnuReturnLoc = OK;
	if(uPinNbCpy <= PORTA_B7)
	{
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTA,u8PinNbCpy);
		}else
		{
			CLR_BIT(PORTA,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTB_B0 && uPinNbCpy <= PORTB_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTB,u8PinNbCpy);
		}else
		{
			CLR_BIT(PORTB,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTC_B0 && uPinNbCpy <= PORTC_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		if(u8PinValueCpy == DIO_u8HIGH)
		{
			SET_BIT(PORTC,u8PinNbCpy);
		}else
		{
			CLR_BIT(PORTC,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTD_B0 && uPinNbCpy <= PORTD_B7)
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
	if(uPinNbCpy <= PORTA_B7)
	{
		*pu8PinValueCpy = GET_BIT(PINA, u8PinNbCpy);
		
	}else if(u8PinNbCpy>= PORTB_B0 && uPinNbCpy <= PORTB_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		*pu8PinValueCpy = GET_BIT(PINB, u8PinNbCpy);
		
	}else if(u8PinNbCpy>= PORTC_B0 && uPinNbCpy <= PORTC_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		*pu8PinValueCpy = GET_BIT(PINC, u8PinNbCpy);
		
	}else if(u8PinNbCpy>= PORTD_B0 && uPinNbCpy <= PORTD_B7)
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
	
	if(uPinNbCpy <= PORTA_B7)
	{
		u8PinDir = GET_BIT(DDRA, u8PinNbCpy);
		if(u8PinDir == INPUT)
		{
			SET_BIT(PORTA,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTB_B0 && uPinNbCpy <= PORTB_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		u8PinDir = GET_BIT(DDRB, u8PinNbCpy);
		if(u8PinDir == INPUT)
		{
			SET_BIT(PORTB,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTC_B0 && uPinNbCpy <= PORTC_B7)
	{
		u8PinNbCpy = u8PinNbCpy % PORTB_B0;
		u8PinDir = GET_BIT(DDRC, u8PinNbCpy);
		if(u8PinDir == INPUT)
		{
			SET_BIT(PORTC,u8PinNbCpy);
		}
	}else if(u8PinNbCpy>= PORTD_B0 && uPinNbCpy <= PORTD_B7)
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