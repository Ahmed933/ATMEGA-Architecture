/*******************************************************/
/* Author      : Ahmed Alaa          		           */
/* Description : EXTI1's  functions implementations    */
/* Date        : 6 DEC 19    				           */
/* Version     : 1.0V  							       */
/*******************************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "EXTI1_int.h"
#include "EXTI1_cfg.h"
#include "EXTI1_priv.h"

PF EXTI1_pfAddress;

void EXTI1_voidInit(void)
{
	#if EXTI1_MODE == ON_CHANGE
	CLR_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);
	
	#elif EXTI1_MODE == LOW_LEVEL
	CLR_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);
	
	#elif EXTI1_MODE == FALLING_EDGE
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	
	#elif EXTI1_MODE == RAISING_EDGE
	SET_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);
	
	#else 
	#endif

	CLR_BIT(GICR,INT1);   	    // Disable interrupt 1 by clearing INT1 bit (bit7) in GICR
	SET_BIT(GIFR,INTF1);   		// Clear flag 1 by setting INTF1 bit (bit7) in GIFR
	
}

void EXTI1_voidEnable(void)
{
	SET_BIT(GICR,INT1);   		// Enable interrupt 1 by setting INT1 bit (bit7) in GICR
}

void EXTI1_voidDisable(void)
{
	CLR_BIT(GICR,INT1);   		// Disable interrupt 1 by clearing INT1 bit (bit7) in GICR	
}

void EXTI1_voidSetCallBack(PF pfAddressCpy)
{
	EXTI1_pfAddress = pfAddressCpy;
}

void EXTI1_voidChangeMode(u8 u8ModeCpy)
{
	if(u8ModeCpy == ON_CHANGE)
	{
		CLR_BIT(MCUCR,ISC11);
		SET_BIT(MCUCR,ISC10);
	}
	
	else if(u8ModeCpy == LOW_LEVEL)
	{
		CLR_BIT(MCUCR,ISC10);
	    CLR_BIT(MCUCR,ISC11);
	}
	
	
	else if(u8ModeCpy == FALLING_EDGE)
	{
		CLR_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
	}
	
	else if(u8ModeCpy == RAISING_EDGE)
	{
		SET_BIT(MCUCR,ISC11);
		SET_BIT(MCUCR,ISC10);
	}
	else 
	{
	}
}


/**      !comment: INT1 interrupt service routine        */
void __vector_2 (void) __attribute__((signal,used));

void __vector_2 (void)
{
	EXTI1_pfAddress();
}