/**************************************/
/* Author      : Ahmed Alaa           */
/* Description : EXTI2 privat file    */
/* Date        : 6 DEC 19    		  */
/* Version     : 1.0V        		  */
/**************************************/

#ifndef EXTI2_PRIV_H
#define EXTI2_PRIV_H

#define GICR    *((volatile u8 *)(0x5B))	//address of General Interrupt Control Register
#define MCUCSR	*((volatile u8 *)(0x54))	//address of MCU Control and Status Register 
#define GIFR	*((volatile u8 *)(0x5A))	//address of General Interrupt Flag Register

#define ISC2	6							// bit6 in MCUCR register (interrupt 2 sense control)

#define INT2	5							//bit5 in GICR register (external interrupt request 2 enable)

#define INTF2	5							//bit5 in GIFR register (external interrupt flag 2)

#endif