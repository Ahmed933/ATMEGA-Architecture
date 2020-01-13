/*******************************************/
/** Author      : ahmed mahmoud            */
/** Description : interface file for LCD   */
/** Date        : 22 Nov 2019		       */
/** Version     : 1.0V                     */
/*******************************************/

#ifndef AREF_LCD_INT_H
#define AREF_LCD_INT_H


void LCD_voidInit(void);

void LCD_voidSendCmd(u8 u8CmdCpy);

void LCD_voidWriteChar(u8 u8CharCpy);

void LCD_voidWriteString(u8 * pu8StringCpy);

void LCD_voidSetCursor(u8 u8CharCpy, u8 u8LineCpy);

void LCD_voidClear(void);



#endif 
