/******************************************/
/* Author      : Ahmed Alaa El-Aref       */
/* Description : I2C interface file       */
/* Date        : 10 JAN 20      		  */
/* Version     : 1.0V   				  */
/******************************************/

#ifndef I2C_INT_H
#define I2C_INT_H


#define I2C_START_ACK	        	0X08
#define I2C_REPEATED_START_ACK	    0X10

/** Master Transmitter ACK Codes **/
#define I2C_MT_SLA_W_ACK			0X18
#define I2C_MT_SLA_W_NACK			0X20

#define I2C_MT_DATA_ACK				0X28
#define I2C_MT_DATA_NACK			0X30

#define I2C_MT_ARBITRATION_LOST		0X38

/** Master Receive ACK Codes **/
#define I2C_MR_SLA_R_ACK			0X40
#define I2C_MR_SLA_R_NACK			0X48
			 
#define I2C_MR_DATA_ACK				0X50
#define I2C_MR_DATA_NACK			0X58


/** initialization function **/
void I2C_voidInit(void);

/** A function to send start (or repeated start) condition on SDA bus **/
void I2C_voidStart(void);


/** A function to send stop condition on SDA bus **/
void I2C_voidStop(void);


/** A function to wait until TWINT flag in TWCR register set to one **/
void I2C_voidWait(void);



/** function to check passed ACK , you should pass ACK type in u8AckCpy
 * 	it will return OK when master or slave return ACK  
 *  and retuen INDEX_OUT_OF_RANGE if master arbitration lost  
 * 	else it will retuen NOK (NACK)
 */
tenuErrorStatus I2C_enuCheckACK(u8 u8AckCpy);


/** function to write one Byte of data on SDA bus**/
void I2C_voidWriteByte(u8 u8ByteCpy);


/** function to return byte of data in pu8RetByteCpy
 * 	it will return OK when receiving operation correctly completed
 * 	and retuen NOK when receiving operation didn't correctly complete
 */
tenuErrorStatus I2C_enuReadByte(u8 * pu8RetByteCpy);


#endif
