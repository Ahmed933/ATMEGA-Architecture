/**
 ** Author      : Ahmed El-Aref    
 ** Description : DIO Interface File
 ** Date        : 22 NOV 19     
 ** Version     : 1.0V          
 **/

#ifndef DIO_INT_H
#define DIO_INT_H

#define DIO_u8HIGH  1
#define DIO_u8LOW	0

#define OUTPUT	1
#define INPUT 	0

#define PULLUP_AVTIVE 	 1
#define PULLUP_NOTAVTIVE 0

/* 	    PORTA pins 	    */
#define PORTA_B0    0     
#define PORTA_B1    1
#define PORTA_B2    2
#define PORTA_B3    3
#define PORTA_B4    4
#define PORTA_B5    5
#define PORTA_B6    6
#define PORTA_B7    7

/* 	    PORTB pins 	    */
#define PORTB_B0   8
#define PORTB_B1   9
#define PORTB_B2   10
#define PORTB_B3   11
#define PORTB_B4   12
#define PORTB_B5   13
#define PORTB_B6   14
#define PORTB_B7   15

/* 	    PORTC pins 	    */
#define PORTC_B0   16
#define PORTC_B1   17
#define PORTC_B2   18
#define PORTC_B3   19
#define PORTC_B4   20
#define PORTC_B5   21
#define PORTC_B6   22
#define PORTC_B7   23

/* 	    PORTD pins 	    */
#define PORTD_B0   24
#define PORTD_B1   25
#define PORTD_B2   26
#define PORTD_B3   27
#define PORTD_B4   28
#define PORTD_B5   29
#define PORTD_B6   30
#define PORTD_B7   31

 

/************************************************/
/** !comment : initialization function which    */
/**            define pins direction for DIO    */
/************************************************/
void DIO_voidInit(void);

/************************************************/
/** !comment : function to set pin as high (5V) */
/**            or low (0V) 					    */
/************************************************/
tenuErrorStatus DIO_enuSetPinValue(u8 u8PinNbCpy, u8 u8PinValueCpy);

/************************************************/
/** !comment : function to get pin valuue       */
/**            as high (5V)or low (0V) 		    */
/************************************************/
tenuErrorStatus DIO_enuGetPinValue(u8 u8PinNbCpy, u8* pu8PinValueCpy);

/************************************************/
/** !comment : function to set internal pull up */
/**            resistor for input pins 		    */
/************************************************/
tenuErrorStatus DIO_enuSetPullUp(u8 u8PinNbCpy, u8 u8pullUpStatusCpy);


#endif
