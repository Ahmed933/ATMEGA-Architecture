/*******************************************/
/* Author      : Ahmed Alaa                */
/* Description : EXTI2 interface file      */
/* Date        : 7 DEC 19    		       */
/* Version     : 1.0V   				   */
/*******************************************/

#ifndef EXTI2_INT_H
#define EXTI2_INT_H

#define FALLING_EDGE 		0
#define RAISING_EDGE 		8

void EXTI2_voidInit(void);
         
void EXTI2_voidEnable(void);
         
void EXTI2_voidDisable(void);
         
void EXTI2_voidSetCallBack(PF pfAddressCpy);
         
void EXTI2_voidChangeMode(u8 u8ModeCpy);

#endif
