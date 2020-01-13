/****************************************************/
/* Author      : Ahmed Alaa El-Aref      	        */
/* Description : I2C functions implementations      */
/* Date        : 10 JAN 20    				        */
/* Version     : 1.0V        				        */
/****************************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "I2C_int.h"
#include "I2C_priv.h"
#include "I2C_cfg.h"


/** initialization function **/
void I2C_voidInit(void)
{
	/** SCL frequency handling **/
	TWBR = I2C_TWBR_VALUE;
	TWSR = TWSR & 0xFC;
	TWSR = TWSR | I2C_SCL_PRES;
	
	/** Slave Address handling **/
	TWAR = TWAR & 0x01;
	TWAR = TWAR | I2C_SLAVE_ADD;
	
	/** Acknowlege mode handling **/
	#if I2C_ACK_MODE == DISABLE
		CLR_BIT(TWCR, TWEA);
	#else 
		SET_BIT(TWCR, TWEA);
	#endif
	
	/** General call handling **/
	#if I2C_GENERAL_CALL == DISABLE
		CLR_BIT(TWAR, TWGCE);
	#else 
		SET_BIT(TWAR, TWGCE);
	#endif
}

/** A function to send start (or repeated start) condition on SDA bus **/
void I2C_voidStart(void)
{
	TWCR |= (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	//SET_BIT(TWCR, TWINT);
	//SET_BIT(TWCR, TWSTA);
	//SET_BIT(TWCR, TWEN);
}


/** A function to send stop condition on SDA bus **/
void I2C_voidStop(void)
{
	TWCR |= (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
	//SET_BIT(TWCR, TWINT);
	//SET_BIT(TWCR, TWSTO);
	//SET_BIT(TWCR, TWEN);
}

/** A function to wait until TWINT flag in TWCR register set to one **/
void I2C_voidWait(void)
{
	while(GET_BIT(TWCR, TWINT) == 0);
}


/** function to check passed ACK , you should pass ACK type in u8AckCpy
 * 	it will return OK when master or slave return ACK  
 *  and retuen INDEX_OUT_OF_RANGE if master arbitration lost 
 * 	else it will retuen NOK (NACK)
 *
 *  ACK TYPES : 
		- I2C_START_ACK	        
		- I2C_REPEATED_START_ACK
		- I2C_MT_SLA_W_ACK		
		- I2C_MT_SLA_W_NACK		
		- I2C_MT_DATA_ACK		
		- I2C_MT_DATA_NACK		
 */
tenuErrorStatus I2C_enuCheckACK(u8 u8AckCpy)
{
	tenuErrorStatus enuStateLoc = NOK;
	
	if((TWSR & 0xF8) == u8AckCpy)
	{
		enuStateLoc = OK;
	}
	else if((TWSR & 0xF8) == I2C_MT_ARBITRATION_LOST)
	{
		enuStateLoc = INDEX_OUT_OF_RANGE;
	}
		
	return enuStateLoc;
}


/** function to write one Byte of data on SDA bus**/
void I2C_voidWriteByte(u8 u8ByteCpy)
{
	TWDR = u8ByteCpy;
	
	TWCR |= (1<<TWINT) | (1<<TWEN);
	//SET_BIT(TWCR, TWINT);
	//SET_BIT(TWCR, TWEN);
}


/** function to return byte of data in pu8RetByteCpy
 * 	it will return OK when receiving operation correctly completed
 * 	and retuen NOK when receiving operation didn't correctly complete
 */
tenuErrorStatus I2C_enuReadByte(u8 * pu8RetByteCpy)
{
	tenuErrorStatus enuStateLoc = NOK;
	TWCR |= (1<<TWINT) | (1<<TWEN);
	
	I2C_voidWait();
	if(I2C_enuCheckACK(I2C_MR_DATA_NACK) == OK)
	{
		* pu8RetByteCpy = TWDR;
		enuStateLoc = OK;
	}
		
	return enuStateLoc;
}