/**************************************/
/* Author      : Ahmed Alaa           */
/* Description : EXTI0 private file   */
/* Date        : 6 DEC 19    		  */
/* Version     : 1.0V        		  */
/**************************************/

#ifndef EXTI0_PRIV_H
#define EXTI0_PRIV_H


#define GICR    *((volatile u8 *)(0x5B))	//address of General Interrupt Control Register
#define MCUCR	*((volatile u8 *)(0x55))	//address of MCU Control Register 
#define GIFR	*((volatile u8 *)(0x5A))	//address of General Interrupt Flag Register

#define ISC00	0							// bit0 in MCUCR register (interrupt 0 sense control bin0)
#define ISC01	1							// bit1 in MCUCR register (interrupt 0 sense control bin1)

#define INT0	6							//bit6 in GICR register (external interrupt request 0 enable)

#define INTF0	6							//bit6 in GIFR register (external interrupt flag 0)


#endif