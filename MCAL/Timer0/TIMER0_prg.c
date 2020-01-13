/********************************************************/
/** Author      : Ahmed Alaa          		          	*/
/** Description : TIMER0's  functions implementations  	*/
/** Date        : 14 DEC 19    				           	*/
/** Version     : 1.0V        				           	*/
/********************************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "TIMER0_int.h"
#include "TIMER0_cfg.h"
#include "TIMER0_priv.h"


PF OVF_pfAddress;  // address of timer overflow ISR function
PF CMP_pfAddress;  // address of compare match ISR function


/**************************************************************************************/
/****************************** FUNCTIONS IMPLEMENTATION ******************************/
/**************************************************************************************/

/** initialize timer 0 : mode , prescaler, clock source **/
void TIM0_voidInit(void)
{
	/** Disable compare match interrupt (OCIE0) and timer overflow interrupt (TOIE0) **/
	CLR_BIT(TIMSK, TIMSK_OCIE0);
	CLR_BIT(TIMSK, TIMSK_TOIE0);
	
	
	/** Clear Force Output Compare Bit **/
	CLR_BIT(TCCR0, TCCR0_FOC0);
	
	/** set timer0 operation mode : NORMAL, CTC, PHASE_PWM, FAST_PWM **/
	#if TIM0_u8OP_MODE == NORMAL
		CLR_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
	#elif TIM0_u8OP_MODE == CTC
		CLR_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
	#elif TIM0_u8OP_MODE == PHASE_PWM
		SET_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
	#else 
		SET_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
	#endif
	
	
	/** Set the Output Compare pin (OC0) behavior: CTC_NOSIGNAL, CTC_TOGGGLE, CTC_CLEAR, CTC_SET **/
	#if TIM0_u8OP_MODE == FAST_PWM 
	
		#if TIM0_u8CTC_SIGNAL == CTC_NOSIGNAL
			CLR_BIT(TCCR0, TCCR0_COM00);
			CLR_BIT(TCCR0, TCCR0_COM01);
		#elif TIM0_u8CTC_SIGNAL == CTC_TOGGGLE
			SET_BIT(TCCR0, TCCR0_COM00);
			CLR_BIT(TCCR0, TCCR0_COM01);
		#elif TIM0_u8CTC_SIGNAL == CTC_CLEAR
			CLR_BIT(TCCR0, TCCR0_COM00);
			SET_BIT(TCCR0, TCCR0_COM01);
		#else
			SET_BIT(TCCR0, TCCR0_COM00);
			SET_BIT(TCCR0, TCCR0_COM01);	
		#endif
	#endif
	
	
	/** Set the Output Compare pin (OC0) behavior: PWM_NOSIGNAL, PWM_NON_INVERTING, PWM_INVERTING **/
	#if TIM0_u8OP_MODE == CTC 
	
		#if TIM0_u8FAST_PWM_SIGNAL == PWM_NOSIGNAL
			CLR_BIT(TCCR0, TCCR0_COM00);
			CLR_BIT(TCCR0, TCCR0_COM01);
		#elif TIM0_u8FAST_PWM_SIGNAL == PWM_NON_INVERTING
			CLR_BIT(TCCR0, TCCR0_COM00);
			SET_BIT(TCCR0, TCCR0_COM01);
		#else
			SET_BIT(TCCR0, TCCR0_COM00);
			SET_BIT(TCCR0, TCCR0_COM01);	
		#endif
	#endif
	
	
	/** Clear compare match flag (OCF0) and timer overflow flag (TOV0) by writing logical one to them **/
	SET_BIT(TIFR, TIFR_OCF0);
	SET_BIT(TIFR, TIFR_TOV0);
	
	
	/** Set clock source and prescaler **/
	TCCR0 = TCCR0 & 0b11111000;   			// first clear first 3 bit (masking)
	TCCR0 = TCCR0 | TIM0_u8CLK_SRC;			// then add u8clockModeCpy to TCCR0

}






/** enable or dissable timer 0 depends on prescaler mode passed to this function
	you should pass one of these config. : 
		TIM0_u8DISABLE 			0
		TIM0_u8EN_PRES1 		1
		TIM0_u8EN_PRES8 		2
		TIM0_u8EN_PRES64		3
		TIM0_u8EN_PRES256 		4
		TIM0_u8EN_PRES1024 		5
		TIM0_u8EXTCLK_FALLING   6
		TIM0_u8EXTCLK_RISING    7	
*/
void TIM0_voidEnableDisable(u8 u8clockModeCpy)
{
	/** clock source and prescaler config **/
	TCCR0 = TCCR0 & 0b11111000;   			// first clear first 3 bit (masking)
	TCCR0 = TCCR0 | u8clockModeCpy;			// then add u8clockModeCpy to TCCR0
}




/** Enable or disable timer 0 overflow interrupt request
	you should pass one of these options to the function: 
			- TIM0IRQ_u8DISABLE
		    - TIM0IRQ_u8ENABLE 
*/
void TIM0_voidEnDisOVF_IRQ(u8 u8IRQModeCpy)
{
	if(u8IRQModeCpy == TIM0IRQ_u8ENABLE)
	{
		SET_BIT(TIMSK, TIMSK_TOIE0);
	}
	else 
	{
		CLR_BIT(TIMSK, TIMSK_TOIE0);
	}
	
}

/** Enable or disable timer 0 compare match interrupt request
	you should pass one of these options to the function: 
			- TIM0IRQ_u8DISABLE
		    - TIM0IRQ_u8ENABLE 
*/
void TIM0_voidEnDisCMP_IRQ(u8 u8IRQModeCpy)
{
	if(u8IRQModeCpy == TIM0IRQ_u8ENABLE)
	{
		SET_BIT(TIMSK, TIMSK_OCIE0);
	}
	else 
	{
		CLR_BIT(TIMSK, TIMSK_OCIE0);
	}
	
}




/** A function to set (write) timer/counter register TCNT0 (uRegValueCpy 0 --> 255)   **/
void TIM0_voidSetTimerReg(u8 u8RegValueCpy)
{
	TCNT0 = u8RegValueCpy;
}

/** A function to set (write) output compare match register OCR0 (uRegValueCpy 0 --> 255) **/
void TIM0_voidSetCompareReg(u8 u8RegValueCpy)
{
	OCR0 = u8RegValueCpy;
}



/** A function to get (read) timer/counter register TCNT0 **/
u8 TIM0_u8GetTimerReg(void)
{
	return TCNT0;
}

/** A function to get (read) output compare match register OCR0 **/
u8 TIM0_u8GetCompareReg(void)
{
	return OCR0;
}



/** A function take the address of timer overflow ISR function 
	that defined in APP layer to be served  **/
void TIM0_voidSetCallBackOVF(PF pfCpy)
{
	OVF_pfAddress = pfCpy;
}

/** A function take the address of compare match ISR function
	that defined in APP layer to be served **/
void TIM0_voidSetCallBackCMP(PF pfCpy)
{
	CMP_pfAddress = pfCpy;
}

/** A function to adjust duty cycle of OC0 **/
void TIM0_voidSetFastPWM(u8 u8DutyValueCpy)
{
	u8 u8OCR0_valueLoc;
	#if TIM0_u8FAST_PWM_SIGNAL == PWM_NON_INVERTING
		
	#elif TIM0_u8FAST_PWM_SIGNAL == PWM_INVERTING
	#else
	#endif
	
}


/**      !comment: timer/counter0 overflow interrupt service routine        */
void __vector_11 (void) __attribute__((signal,used));

void __vector_11 (void)
{
	OVF_pfAddress();
}


/**      !comment: timer/counter0 compare match interrupt service routine        */
void __vector_10 (void) __attribute__((signal,used));

void __vector_10 (void)
{
	CMP_pfAddress();
}