/**************************************/
/* Author      : Ahmed Alaan          */
/* Description : EXTI0 privat file */
/* Date        : 6 DEC 19    		  */
/* Version     : 1.0V        		  */
/**************************************/

#ifndef EXTI0_PRIV_H
#define EXTI0_PRIV_H

#define GICR    *((volatile u8 *)(0x5B))
#define MCUCR	*((volatile u8 *)(0x55))
#define GIFR	*((volatile u8 *)(0x5A))


#endif