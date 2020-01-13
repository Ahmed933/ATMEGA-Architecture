/****************************************************/
/* Author      : Ahmed Alaa El-Aref      	        */
/* Description : UART functions implementations     */
/* Date        : 4 JAN 20    				        */
/* Version     : 1.0V        				        */
/****************************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "UART_int.h"
#include "UART_cfg.h"
#include "UART_priv.h"


/** initialization function and it take CPU frequency to calculate UBBRL:H values according to baud rate **/
void UART_voidInit(u32 u32FcpuCpy)
{
	u16 UBBR_registerValue;

#if UART_MODE == SYNCH
	UBBR_registerValue = (u32FcpuCpy / (2 * UART_BAUD_RATE))-1;

#else

#if UART_SPEED_MODE == DOUBLE_SPEED
	UBBR_registerValue = (u32FcpuCpy / (8 * UART_BAUD_RATE))-1;

#else
	UBBR_registerValue = (u32FcpuCpy / (16 * UART_BAUD_RATE))-1;
#endif

#endif

	UBBRL = UBBR_registerValue;
	UBBRH = (UBBR_registerValue >> 8)


}


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
