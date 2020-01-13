/*****************************************/
/* Author      : Ahmed Alaa El-Aref      */
/* Description : SPI private file        */
/* Date        : 4 JAN 20    		     */
/* Version     : 1.0V        		     */
/*****************************************/

#ifndef SPI_PRIV_H
#define SPI_PRIV_H


#define SPCR 	*((volatile u8*)(0x2D))   // SPI control register
#define SPSR	*((volatile u8*)(0x2E))   // SPI status register
#define SPDR 	*((volatile u8*)(0x2F))   // SPI data register 


/* SPCR Bits */
#define SPIE	7		// SPI Interrupt Enable
#define SPE		6		// SPI Enable
#define DORD	5		// Data Order
#define MSTR	4		// Master/Slave Select
#define CPOL	3       // Clock Polarity
#define CPHA	2       // Clock Phase
#define SPR1	1       // SPI Clock Rate Select 1
#define SPR0	0       // SPI Clock Rate Select 0

/* SPSR Bits */
#define SPI2X	 0		// SPI double speed 
#define WCOL     6		// Write Collision flag
#define SPIF     7		// SPI interrupt flag

/** SPI data order **/
#define SPI_LSB  0
#define SPI_MSB	 8

/** SPI Master/Slave Mode **/
#define SPI_MASTER   16
#define SPI_SLAVE    24

#define PRESCALER_2		0
#define PRESCALER_4		0
#define PRESCALER_8		1
#define PRESCALER_16	1
#define PRESCALER_32	2
#define PRESCALER_64	2		
#define PRESCALER_128	3


#endif	