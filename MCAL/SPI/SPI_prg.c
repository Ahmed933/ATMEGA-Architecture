/****************************************************/
/* Author      : Ahmed Alaa El-Aref      	        */
/* Description : SPI functions implementations     */
/* Date        : 4 JAN 20    				        */
/* Version     : 1.0V        				        */
/****************************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "SPI_int.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"


/** initialization function **/
void SPI_voidInit(void)
{
	SET_BIT(SPCR, SPE);
	
	/** Master Mode	**/
	#if SPI_MODE == SPI_MASTER 
		SET_BIT(SPCR, MSTR);
		#if SPI_DATA_ORDER == SPI_LSB
			SET_BIT(SPCR, DORD);
		#else
			CLR_BIT(SPCR, DORD);
		#endif
		
		#if SPI_PRESCALER == PRESCALER_2 || SPI_PRESCALER == PRESCALER_8 || SPI_PRESCALER == PRESCALER_32 
			SET_BIT(SPSR, SPI2X);
		#else
			CLR_BIT(SPSR, SPI2X);
		#endif
	
		SPCR = SPCR & 0b11111100
		SPCR = SPCR | SPI_PRESCALER;
		
	/** Slave Mode **/	
	#else
		CLR_BIT(SPCR, MSTR);
	
	#endif
	
	CLR_BIT(SPCR, CPOL);
	CLR_BIT(SPCR, CPHA);
	
}


/** function to transmit one char of data **/
void SPI_voidTransmit(u8 u8CharCpy)
{
	SPDR = u8CharCpy;
	/** Polling on transmit flag SPIF**/
	while(GET_BIT(SPSR,SPIF) == 0);
}


/** function to recieve one char of data
 * 	it will return OK when receive operation correctly completed
 * 	and retuen NOK when receive operation didn't correctly complete
 */
tenuErrorStatus SPI_enuSlaveReceive(u8 * pu8CharCpy)
{
	tenuErrorStatus returnState = NOK;
	if(GET_BIT(SPSR,SPIF) == 1)
	{
		* pu8CharCpy = SPDR;
		returnState = OK;
	}
	return returnState;
}

u8 SPI_u8MasterReceive(void)
{
	SPDR = 0;
	/** Polling on transmit flag SPIF**/
	while(GET_BIT(SPSR,SPIF) == 0);
	
	return SPDR;
}