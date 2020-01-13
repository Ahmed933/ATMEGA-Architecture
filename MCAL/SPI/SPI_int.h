/******************************************/
/* Author      : Ahmed Alaa El-Aref       */
/* Description : SPI interface file       */
/* Date        : 4 JAN 20      		      */
/* Version     : 1.0V   				  */
/******************************************/

#ifndef SPI_INT_H
#define SPI_INT_H




/** initialization function **/
void SPI_voidInit(void);


/** function to transmit one char of data **/
void SPI_voidTransmit(u8 u8CharCpy);


/** function to recieve one char of data
 * 	it will return OK when receive operation correctly completed
 * 	and retuen NOK when receive operation didn't correctly complete
 */
tenuErrorStatus SPI_enuSlaveReceive(u8 * pu8CharCpy);


u8 SPI_u8MasterReceive(void);

#endif
