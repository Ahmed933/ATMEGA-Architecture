/******************************************/
/* Author      : Ahmed Alaa El-Aref       */
/* Description : UART interface file      */
/* Date        : 4 JAN 20      		      */
/* Version     : 1.0V   				  */
/******************************************/

#ifndef UART_INT_H
#define UART_INT_H

/* UART Mode */
#define ASYNCH 0
#define SYNCH  8

/* UART Speed Mode */
#define NORMAL_SPEED 16
#define DOUBLE_SPEED 24



/** initialization function and it take CPU frequency to calculate UBBRL:H values according to baud rate **/
void UART_voidInit(u32 u32FcpuCpy);


/** function to transmit one char of data **/
void UART_voidTransmitChar(u8 u8CharCpy);


/** function to recieve one char of data
 * 	it will return OK when receive operation correctly completed
 * 	and retuen NOK when receive operation didn't correctly complete
 */
tenuErrorStatus UART_enuReceiveChar(u8 * pu8CharCpy);


/* function to check if there is data to receive or not
 *  it will return 1 (RXC flag) when there are unread data in the receive buffer
 *  and return 0 when the receive buffer is empty
 */
u8 UART_u8IsAvailable(void);


#endif
