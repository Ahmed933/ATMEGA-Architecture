/**********************************************/
/* Author      : Ahmed Alaa                   */
/* Description : TIMER0 configuration file     */
/* Date        : 14 DEC 19    		          */
/* Version     : 1.0V                         */
/**********************************************/
#ifndef TIMER0_CFG_H
#define TIMER0_CFG_H


/**
you should choose one of these config. : 
	TIM0_u8DISABLE 		0
	TIM0_u8EN_PRES1 	1
	TIM0_u8EN_PRES8 	2
	TIM0_u8EN_PRES64	3
	TIM0_u8EN_PRES256 	4
	TIM0_u8EN_PRES1024 	5
	TIM0_u8EXTCLK_FALLING   6
	TIM0_u8EXTCLK_RISING    7	
*/
#define TIM0_u8CLK_SRC	TIM0_u8EN_PRES64



/**
you should choose one of these config. : 
	NORMAL 	
	CTC		
	FAST_PWM
	PHASE_PWM
*/
#define TIM0_u8OP_MODE	CTC



#if TIM0_u8OP_MODE == CTC
/**
you should choose one of these config. : 
	CTC_NOSIGNAL
	CTC_TOGGGLE	
	CTC_SET		
	CTC_CLEAR	
*/
#define TIM0_u8CTC_SIGNAL  CTC_NOSIGNAL

#endif


/** in Fast PWM : PWM frequency = F_CPU / (256 * N) , where N is the prescaler **/
#if TIM0_u8OP_MODE == FAST_PWM
/**
you should choose one of these config. : 
	PWM_NOSIGNAL
	PWM_NON_INVERTING
	PWM_INVERTING	
*/
#define TIM0_u8FAST_PWM_SIGNAL  PWM_NON_INVERTING

#endif           