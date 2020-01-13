/*****************************************/
/* Author      : Ahmed Alaa              */
/* Description : EXTI0 interface file    */
/* Date        : 6 DEC 19    		     */
/* Version     : 1.0V   				 */
/*****************************************/

#ifndef EXTI0_INT_H
#define EXTI0_INT_H

#define ON_CHANGE 			0
#define LOW_LEVEL 			8
#define FALLING_EDGE 		16
#define RAISING_EDGE 		24

void EXTI0_voidInit(void);

void EXTI0_voidEnable(void);

void EXTI0_voidDisable(void);

void EXTI0_voidSetCallBack(PF pfAddressCpy);

void EXTI0_voidChangeMode(u8 u8ModeCpy);

#endif
