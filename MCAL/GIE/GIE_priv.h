/**************************************/
/* Author      : Ahmed Alaa           */
/* Description : GIE privat fiele     */
/* Date        : 6 DEC 19    		  */
/* Version     : 1.0V        		  */
/**************************************/

#ifndef DIO_PRIV_H
#define DIO_PRIV_H

#define SREG	*((volatile u8*)(0x5F))			// address of AVR Status Register

#define SREG_I 	7								//bit7 (I) in SREG (Global Interrupt Enable)

#endif	