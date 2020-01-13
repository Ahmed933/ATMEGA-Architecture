/***********************************************/
/* Author      : Ahmed Alaan         		   */
/* Description : GIE  functions implementations*/
/* Date        : 6 DEC 19    				   */
/* Version     : 1.0V        				   */
/***********************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "EXTI0_int.h"
#include "EXTI0_cfg.h"
#include "EXTI0_priv.h"

PF EXTI0_pfAddress;

void EXTI0_voidInit(void)
{
	#if EXTI0_MODE == INTERRUPT_ON_CHANGE
	CLR_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);
	
	#elif EXTI0_MODE == LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	
	#elif EXTI0_MODE == FALLING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	
	#elif EXTI0_MODE == RAISING_EDGE
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);
	
	#else 
	#endif

	CLR_BIT(GICR,6);   // Disable INT0 by clearing bit6 in GICR
	SET_BIT(GIFR,6);   // clear flag by setting bit6 in GIFR
	
}

void EXTI0_voidEnable(void)
{
	SET_BIT(GICR,6);   // Disable INT0 by clearing bit6 in GICR
}

void EXTI0_voidDisable(void)
{
	CLR_BIT(GICR,6);   // Disable INT0 by clearing bit6 in GICR	
}

void EXTI0_voidSetCallBack(PF pfAddressCpy)
{
	EXTI0_pfAddress = pfAddressCpy;
}

void EXTI0_voidChangeMode(u8 u8ModeCpy)
{
	if(u8ModeCpy == INTERRUPT_ON_CHANGE)
	{
		CLR_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);
	}
	
	else if(u8ModeCpy == LOW_LEVEL)
	{
		CLR_BIT(MCUCR,0);
	    CLR_BIT(MCUCR,1);
	}
	
	
	else if(u8ModeCpy == FALLING_EDGE)
	{
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	}
	
	else if(u8ModeCpy == RAISING_EDGE)
	{
		SET_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);
	}
	else 
	{
	}
}


/* INT0 interrupt implementation function*/
void __vector_1 (void) __attribute__((signal,used));

void __vector_1 (void)
{
	EXTI0_pfAddress();
}