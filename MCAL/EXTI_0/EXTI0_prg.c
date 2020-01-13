/*******************************************************/
/* Author      : Ahmed Alaa          		           */
/* Description : EXTI0's  functions implementations    */
/* Date        : 6 DEC 19    				           */
/* Version     : 1.0V        				           */
/*******************************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "EXTI0_int.h"
#include "EXTI0_cfg.h"
#include "EXTI0_priv.h"

PF EXTI0_pfAddress;

void EXTI0_voidInit(void)
{
	#if EXTI0_MODE == ON_CHANGE
	CLR_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
	
	#elif EXTI0_MODE == LOW_LEVEL
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	
	#elif EXTI0_MODE == FALLING_EDGE
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	
	#elif EXTI0_MODE == RAISING_EDGE
	SET_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
	
	#else 
	#endif

	CLR_BIT(GICR,INT0);    			// Disable interrupt 0 by clearing INT0 bit (bit6) in GICR
	SET_BIT(GIFR,INTF0);  		 	// Clear flag 0 by setting INTF0 bit (bit6) in GIFR
	
}

void EXTI0_voidEnable(void)
{
	SET_BIT(GICR,INT0);   			// Enable interrupt 0 by setting INT0 bit (bit6) in GICR
}

void EXTI0_voidDisable(void)
{
	CLR_BIT(GICR,INT0);   			// Disable interrupt 0 by clearing INT0 bit (bit6) in GICR	
}

void EXTI0_voidSetCallBack(PF pfAddressCpy)
{
	EXTI0_pfAddress = pfAddressCpy;
}

void EXTI0_voidChangeMode(u8 u8ModeCpy)
{
	if(u8ModeCpy == ON_CHANGE)
	{
		CLR_BIT(MCUCR,ISC01);
		SET_BIT(MCUCR,ISC00);
	}
	
	else if(u8ModeCpy == LOW_LEVEL)
	{
		CLR_BIT(MCUCR,ISC00);
	    CLR_BIT(MCUCR,ISC01);
	}
	
	
	else if(u8ModeCpy == FALLING_EDGE)
	{
		CLR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
	}
	
	else if(u8ModeCpy == RAISING_EDGE)
	{
		SET_BIT(MCUCR,ISC01);
		SET_BIT(MCUCR,ISC00);
	}
	else 
	{
	}
}


/**    !comment : INT0 interrupt service routine        */
void __vector_1 (void) __attribute__((signal,used));

void __vector_1 (void)
{
	EXTI0_pfAddress();
}