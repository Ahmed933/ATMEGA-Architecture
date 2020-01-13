/*******************************************************/
/* Author      : Ahmed Alaa         		           */
/* Description : EXTI2's  functions implementations    */
/* Date        : 6 DEC 19    				           */
/* Version     : 1.0V  							       */
/*******************************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "EXTI2_int.h"
#include "EXTI2_cfg.h"
#include "EXTI2_priv.h"

PF EXTI2_pfAddress;

void EXTI2_voidInit(void)
{
		
	#elif EXTI2_MODE == FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);
	
	#elif EXTI2_MODE == RAISING_EDGE
	SET_BIT(MCUCSR,ISC2);

	#else 
	#endif

	CLR_BIT(GICR,INT2);   	    // Disable interrupt 2 by clearing INT2 bit (bit5) in GICR
	SET_BIT(GIFR,INTF2);   		// Clear flag 2 by setting INTF2 bit (bit5) in GIFR
	
}

void EXTI2_voidEnable(void)
{
	SET_BIT(GICR,INT2);   		// Enable interrupt 2 by setting INT2 bit (bit5) in GICR
}

void EXTI2_voidDisable(void)
{
	CLR_BIT(GICR,INT2);   		// Disable interrupt 2 by clearing INT2 bit (bit5) in GICR	
}

void EXTI2_voidSetCallBack(PF pfAddressCpy)
{
	EXTI2_pfAddress = pfAddressCpy;
}

void EXTI2_voidChangeMode(u8 u8ModeCpy)
{

    if(u8ModeCpy == FALLING_EDGE)
	{
		CLR_BIT(MCUCSR,ISC2);
	}
	
	else if(u8ModeCpy == RAISING_EDGE)
	{
		SET_BIT(MCUCSR,ISC2);
	}
	else 
	{
	}
}


/**      !comment: INT2 interrupt service routine        */
void __vector_3 (void) __attribute__((signal,used));

void __vector_3 (void)
{
	EXTI2_pfAddress();
}