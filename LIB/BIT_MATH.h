/********************************************/
/** Author      : Ahmed El-Aref 			      */
/** Description : Bit Math Library   	      */
/**				        for bit field operations	*/
/** Date        : 1 nov 19  		    	      */
/** Version     : 1.0V                      */
/********************************************/

#ifndef   BIT_MATH_H 
#define   BIT_MATH_H

#define SET_BIT(reg, bitNo)     reg = reg | (1<<bitNo)
#define CLR_BIT(reg, bitNo)     reg = reg & (~(1<<bitNo))
#define TOGGLE_BIT(reg, bitNo)  reg = reg & (1<<bitNo)
#define GET_BIT(reg, bitNo)     ((reg>>bitNo) & 0x01)

/** Concatenat Macro **/
#define conc(b7,b6,b5,b4,b3,b2,b1,b0)         conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define conc_help(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif
