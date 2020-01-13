/**************************************/
/* Author      : Ahmed Alaa           */
/* Description : EXTI1 privat file    */
/* Date        : 6 DEC 19    		  */
/* Version     : 1.0V        		  */
/**************************************/

#ifndef EXTI1_PRIV_H
#define EXTI1_PRIV_H

#define GICR    *((volatile u8 *)(0x5B))	//address of General Interrupt Control Register
#define MCUCR	*((volatile u8 *)(0x55))	//address of MCU Control Register 
#define GIFR	*((volatile u8 *)(0x5A))	//address of General Interrupt Flag Register

#define ISC10	2							// bit2 in MCUCR register (interrupt 1 sense control bin0)
#define ISC11	3							// bit3 in MCUCR register (interrupt 1 sense control bin1)

#define INT1	7							//bit7 in GICR register (external interrupt request 1 enable)

#define INTF1	7							//bit7 in GIFR register (external interrupt flag 1)

#endif