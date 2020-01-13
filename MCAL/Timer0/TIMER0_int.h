/*****************************************/
/* Author      : Ahmed Alaa              */
/* Description : TIMER0 interface file   */
/* Date        : 14 DEC 19    		     */
/* Version     : 1.0V   				 */
/*****************************************/

#ifndef TIMER0_INT_H
#define TIMER0_INT_H


/**    Clock select options    **/
#define TIM0_u8DISABLE 			0
#define TIM0_u8EN_PRES1 		1
#define TIM0_u8EN_PRES8 		2
#define TIM0_u8EN_PRES64		3
#define TIM0_u8EN_PRES256 		4
#define TIM0_u8EN_PRES1024 		5
#define TIM0_u8EXTCLK_FALLING   6
#define TIM0_u8EXTCLK_RISING    7

/** Timer 0 interrupt request enable ro disable options **/
#define TIM0IRQ_u8DISABLE 		10
#define TIM0IRQ_u8ENABLE 		20




/**************************************************************************************/
/******************************** FUNCTIONS PROTOTYPES ********************************/
/**************************************************************************************/

/** initialize timer 0 : mode , prescaler, clock source **/
void TIM0_voidInit(void);


/** enable or dissable timer 0 depends on prescaler mode passed to this function*/
void TIM0_voidEnableDisable(u8 u8clockModeCpy);


/** A function take the address of timer overflow ISR function 
	that defined in APP layer to be served 
**/
void TIM0_voidSetCallBackOVF(PF pfCpy);

/** A function take the address of compare match ISR function
	that defined in APP layer to be served
**/
void TIM0_voidSetCallBackCMP(PF pfCpy);



/** Enable or disable timer 0 overflow interrupt request
	you should pass one of these options to the function: 
			- TIM0IRQ_u8DISABLE
		    - TIM0IRQ_u8ENABLE 
*/
void TIM0_voidEnDisOVF_IRQ(u8 u8IRQModeCpy);

/** Enable or disable timer 0 compare match interrupt request
	you should pass one of these options to the function: 
			- TIM0IRQ_u8DISABLE
		    - TIM0IRQ_u8ENABLE 
*/
void TIM0_voidEnDisCMP_IRQ(u8 u8IRQModeCpy);




/** A function to set (write) timer/counter register TCNT0 (uRegValueCpy 0 --> 255)   **/
void TIM0_voidSetTimerReg(u8 u8RegValueCpy);

/** A function to set (write) output compare match register OCR0 (uRegValueCpy 0 --> 255) **/
void TIM0_voidSetCompareReg(u8 u8RegValueCpy);



/** A function to get (read) timer/counter register TCNT0 **/
u8 TIM0_u8GetTimerReg(void);

/** A function to get (read) output compare match register OCR0 **/
u8 TIM0_u8GetCompareReg(void);

/** A function to adjust duty cycle of OC0 **/
void TIM0_voidSetFastPWM(u8 u8DutyValueCpy);



#endif
