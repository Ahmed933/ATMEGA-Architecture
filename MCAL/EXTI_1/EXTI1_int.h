/*******************************************/
/* Author      : Ahmed Alaa                */
/* Description : EXTI1 interface functions */
/* Date        : 7 DEC 19    		       */
/* Version     : 1.0V   				   */
/*******************************************/

#ifndef EXTI1_INT_H
#define EXTI1_INT_H

#define ON_CHANGE 			0
#define LOW_LEVEL 			8
#define FALLING_EDGE 		16
#define RAISING_EDGE 		24

void EXTI1_voidInit(void);
         
void EXTI1_voidEnable(void);
         
void EXTI1_voidDisable(void);
         
void EXTI1_voidSetCallBack(PF pfAddressCpy);
         
void EXTI1_voidChangeMode(u8 u8ModeCpy);

#endif
