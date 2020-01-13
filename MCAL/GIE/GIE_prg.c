/****************************************************/
/* Author      : Ahmed Alaa            		        */
/* Description : GIE's  functions implementations   */
/* Date        : 6 DEC 19    				        */
/* Version     : 1.0V        				        */
/****************************************************/

#include "STD_Types.h"
#include "Bit_math.h"

#include "GIE_int.h"
#include "GIE_cfg.h"
#include "GIE_priv.h"


/** !comment: enable globale interrupt by setting bit7 (I) in SREG */
void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

/** !comment: disable globale interrupt by clearing bit7 (I) in SREG */
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
