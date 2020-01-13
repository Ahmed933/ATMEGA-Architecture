/********************************/
/** Author      : Ahmed Alaa    */
/** Description : 7 seg program */
/** Date        : 22 NOV 19     */
/** Version     : 1.0V          */
/********************************/

#include "STD_Types.h"
#include "Bit_math.h"
#include "DIO_int.h"

#include "SEV_int.h"
#include "SEV_cfg.h"
#include "SEV_priv.h"



void SEV_voidDisplayNb(u8 u8ChipNbCpy, u8 u8Number)
{
	#if SEV_MODE == CM_ANODE
		u8 SEV_u8D[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
	#elif SEV_MODE == CM_CATHODE
		u8 SEV_u8D[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	#endif
	
	if (u8ChipNbCpy == SEV_LEFT)
	{
		DIO_enuSetPinValue(SEV_u8LPIN_A  , GET_BIT(SEV_u8D[u8NumberCpy] ,0));
		DIO_enuSetPinValue(SEV_u8LPIN_B  , GET_BIT(SEV_u8D[u8NumberCpy] ,1));
		DIO_enuSetPinValue(SEV_u8LPIN_C  , GET_BIT(SEV_u8D[u8NumberCpy] ,2));
		DIO_enuSetPinValue(SEV_u8LPIN_D  , GET_BIT(SEV_u8D[u8NumberCpy] ,3));
		DIO_enuSetPinValue(SEV_u8LPIN_E  , GET_BIT(SEV_u8D[u8NumberCpy] ,4));
		DIO_enuSetPinValue(SEV_u8LPIN_F  , GET_BIT(SEV_u8D[u8NumberCpy] ,5));
		DIO_enuSetPinValue(SEV_u8LPIN_G  , GET_BIT(SEV_u8D[u8NumberCpy] ,6));
		DIO_enuSetPinValue(SEV_u8LPIN_CM , GET_BIT(SEV_u8D[u8NumberCpy] ,7));
	}
	else if (u8ChipNbCpy == SEV_RIGHT)
	{
		DIO_enuSetPinValue(SEV_u8RPIN_A  , GET_BIT(SEV_u8D[u8NumberCpy] ,0));
		DIO_enuSetPinValue(SEV_u8RPIN_B  , GET_BIT(SEV_u8D[u8NumberCpy] ,1));
		DIO_enuSetPinValue(SEV_u8RPIN_C  , GET_BIT(SEV_u8D[u8NumberCpy] ,2));
		DIO_enuSetPinValue(SEV_u8RPIN_D  , GET_BIT(SEV_u8D[u8NumberCpy] ,3));
		DIO_enuSetPinValue(SEV_u8RPIN_E  , GET_BIT(SEV_u8D[u8NumberCpy] ,4));
		DIO_enuSetPinValue(SEV_u8RPIN_F  , GET_BIT(SEV_u8D[u8NumberCpy] ,5));
		DIO_enuSetPinValue(SEV_u8RPIN_G  , GET_BIT(SEV_u8D[u8NumberCpy] ,6));
		DIO_enuSetPinValue(SEV_u8RPIN_CM , GET_BIT(SEV_u8D[u8NumberCpy] ,7));		
	}
}


