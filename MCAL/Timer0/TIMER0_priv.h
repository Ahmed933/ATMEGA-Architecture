/***************************************/
/** Author      : Ahmed Alaa           */
/** Description : TIMER0 private file  */
/** Date        : 14 DEC 19    		   */
/** Version     : 1.0V        		   */
/***************************************/

#ifndef TIMER0_PRIV_H
#define TIMER0_PRIV_H


#define NORMAL 		0
#define PHASE_PWM	1	
#define CTC			2
#define FAST_PWM	3

#define CTC_NOSIGNAL 		0
#define CTC_TOGGGLE			1	
#define CTC_CLEAR			2
#define CTC_SET				3

#define PWM_NOSIGNAL		0
#define PWM_NON_INVERTING	2
#define PWM_INVERTING		3

#define OCR0    *((volatile u8 *)(0x5C))	//address of Output Compare Register for Timer0
#define TCNT0	*((volatile u8 *)(0x52))	//address of Timer/Counter Register for Timer0 
#define TCCR0	*((volatile u8 *)(0x53))	//address of Timer/Counter Control Register for Timer0
#define TIMSK	*((volatile u8 *)(0x59))	//address of Timer/Counter Interrupt Mask Register for Timer0
#define TIFR	*((volatile u8 *)(0x58))    //address of Timer/Counter Interrupt Flag Register for Timer0



#define TCCR0_FOC0 		7			// Force Output Compare 
#define TCCR0_WGM00 	6			// Waveform Generation Mode00
#define TCCR0_COM01 	5           // Compare Match Output Mode00
#define TCCR0_COM00 	4           // Compare Match Output Mode01
#define TCCR0_WGM01		3	        // Waveform Generation Mode01 
#define TCCR0_CS02		2           // Clock Select00 
#define TCCR0_CS01		1           // Clock Select01 
#define TCCR0_CS00		0           // Clock Select02 

#define TIMSK_OCIE0		1			// Timer/Counter0 Output Compare Match Interrupt Enable 
#define TIMSK_TOIE0		0			// Timer/Counter0 Overflow Interrupt Enable

#define TIFR_OCF0		1			// Output Compare Flag 0
#define TIFR_TOV0		0			// Timer/Counter Overflow Flag 0


#endif