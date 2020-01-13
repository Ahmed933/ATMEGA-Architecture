/************************************/
/** Author      : Ahmed EL-Aref  	*/
/** Description : Standard Library  */
/** Date        : 7 DEC 19    	    */
/** Version     : 1.0V        	    */
/************************************/

#ifndef   STD_TYPES_H 
#define   STD_TYPES_H

typedef unsigned char      u8;
typedef unsigned short int u16;
typedef unsigned long int  u32;

typedef signed char 	   s8;
typedef signed short int   s16;
typedef signed long int    s32;

typedef float 		       f32;
typedef double 			   f64;
typedef long double 	   f96;

typedef enum{
	OK,
	NOK,
	INDEX_OUT_OF_RANGE

}tenuErrorStatus;

/** !comment : typedef pointer to function called PF */
typedef void (*PF)(void);

#endif


