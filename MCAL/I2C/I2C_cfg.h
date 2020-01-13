/*****************************************/
/* Author      : Ahmed Alaa El-Aref      */
/* Description : I2C configuration file  */
/* Date        : 10 JAN 20   		     */
/* Version     : 1.0V        		     */
/*****************************************/

#ifndef I2C_CFG_H
#define I2C_CFG_H

/** I2C_ACK_MODE OPTIONS : ENABLE , DISABLE **/
#define I2C_ACK_MODE	ENABLE


/** I2C SCL Freq. = F_CPU / [16 + 2(TWBR) . PRESCALER] 
*	where,
*			PRESCALER (I2C_SCL_PRES) options : PRES_1, PRES_4, PRES_16, PRES_64
*	
*	and 	0X00 <= TWBR (I2C_TWBR_VALUE) <= 0xFF		
**/
#define I2C_SCL_PRES 	PRES_1
#define I2C_TWBR_VALUE 	0x00


/** put down your unit address **/
#define I2C_SLAVE_ADD  0x05

/** I2C_GENERAL_CALL OPTIONS : ENABLE , DISABLE **/
#define I2C_GENERAL_CALL	DISABLE

#endif           
