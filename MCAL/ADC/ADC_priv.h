/**************************************/
/* Author      : Ahmed Alaa           */
/* Description : ADC privat fiele     */
/* Date        : 13 DEC 19    		  */
/* Version     : 1.0V        		  */
/**************************************/

#ifndef ADC_PRIV_H
#define ADC_PRIV_H

#define AREF			0
#define AVCC 			8
#define INT_VREF 		16


#define PRE_2		1
#define PRE_4		2
#define PRE_8		3
#define PRE_16		4
#define PRE_32		5
#define PRE_64		6
#define PRE_128		7

#define ADMUX 	*((volatile u8*)(0x27)) 
#define ADCSRA 	*((volatile u8*)(0x26))
#define ADCH	*((volatile u8*)(0x25))
#define ADCL	*((volatile u8*)(0x24))


#define MUX0	0
#define MUX1	1
#define MUX2	2
#define MUX3	3
#define MUX4	4
#define ADLAR	5
#define REFS0	6
#define REFS1	7

#define ADPS0	0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7



#endif	