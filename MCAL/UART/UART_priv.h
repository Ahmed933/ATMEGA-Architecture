/*****************************************/
/* Author      : Ahmed Alaa El-Aref      */
/* Description : UART private file       */
/* Date        : 4 JAN 20    		     */
/* Version     : 1.0V        		     */
/*****************************************/

#ifndef UART_PRIV_H
#define UART_PRIV_H


#define UDR 	*((volatile u8*)(0x2C)) 
#define UDDRH 	*((volatile u8*)(0x40))
#define UDDRL	*((volatile u8*)(0x29))
#define UCSRA	*((volatile u8*)(0x2B))		//USART control and status register 
#define UCSRB	*((volatile u8*)(0x2A))
#define UCSRC	*((volatile u8*)(0x40))

/* UCSRA Bits */
#define MPCM	0		//Multi-processor Communication Mode
#define U2X		1		//Double the USART Transmission Speed
#define PE		2		//Parity Error
#define DOR		3		//Data OverRun
#define FE		4       //Frame Error
#define UDRE	5       //USART Data Register Empty
#define TXC		6       //USART Transmit Complete
#define RXC		7       //USART Receive Complete

/* UCSRB Bits */
#define TXB8	 0		//Transmit Data Bit 8
#define RXB8     1		//Receive Data Bit 8
#define UCSZ2    2		//Character Size 2
#define TXEN     3		//Transmitter Enable
#define RXEN     4		//Receiver Enable
#define UDRIE	 5 		//USART Data Register Empty Interrupt Enable
#define TXCIE    6		//TX Complete Interrupt Enable
#define RXCIE    7		//RX Complete Interrupt Enable

/* UCSRC Bits */
#define UCPOL	 0		//Clock Polarity
#define UCSZ0    1		//Character Size 0
#define UCSZ1    2		//Character Size 1
#define USBS     3		//Stop Bit Select
#define UPM0     4		//Parity Mode 0
#define UPM1	 5 		//Parity Mode 1
#define UMSEL    6		//USART Mode Select
#define URSEL    7		//Register Select


#endif	