/**********************************/
/** Author      : Ahmed Alaa      */
/** Description : 7 seg interface */
/** Date        : 22 NOV 19       */
/** Version     : 1.0V            */
/**********************************/

#ifndef SEV_INT_H
#define SEV_INT_H

#define SEV_LEFT    0
#define SEV_ RIGHT  1

/********************************************************/
/** function to display numbers on 7 segment        	*/
/** if  u8Number > 9 --> it will power off the chip		*/
/********************************************************/
void SEV_voidDisplayNb(u8 u8ChipNbCpy, u8 u8Number);


#endif
