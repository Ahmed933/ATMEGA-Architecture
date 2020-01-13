/*****************************************/
/* Author      : Ahmed Alaa El-Aref      */
/* Description : I2C private file        */
/* Date        : 10 JAN 20    		     */
/* Version     : 1.0V        		     */
/*****************************************/

#ifndef I2C_PRIV_H
#define I2C_PRIV_H


#define TWAR 	*((volatile u8*)(0x22))   // TWI Address Register
#define TWBR 	*((volatile u8*)(0x20))   // TWI Bit Rate Register
#define TWCR	*((volatile u8*)(0x56))   // TWI Control Register
#define TWDR	*((volatile u8*)(0x23))   // TWI Data Register
#define TWSR 	*((volatile u8*)(0x21))   // TWI Status Register 


/** TWCR Bits **/
#define TWINT	7		// TWI Interrupt flag
#define TWEA	6		// TWI Enable ACK Bit
#define TWSTA	5		// TWI Start condition
#define TWSTO	4		// TWI Stop condition
#define TWWC	3       // TWI Write Collision flag
#define TWEN	2       // TWI Enable bit
#define TWIE	0       // TWI Interrupt Enable 

/** TWSR Prescaler Bits **/
#define TWPS0	 0	
#define TWPS1    1	


/** TWAR General Call Enable Bit**/
#define TWGCE  0


#define ENABLE  0
#define DISABLE 1


#define PRES_1		0
#define PRES_4		1	
#define PRES_16		2
#define PRES_64		3

#endif	