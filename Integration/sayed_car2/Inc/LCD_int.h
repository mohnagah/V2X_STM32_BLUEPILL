#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

/**for 16x2 LCD ===> the number of rows = 2*/
#define MAX_NUM_OF_ROW    2
#define MIN_NUM_OF_ROW    1

/**for 16x2 LCD ===> the number of columns = 16*/
#define MAX_NUM_OF_COL    16
#define MIN_NUM_OF_COL    1

/**Define IDs of rows*/
#define  LCD_ROW1         1
#define  LCD_ROW2         2

/**Define IDs of columns*/					     
#define  LCD_COL1         1
#define  LCD_COL2         2
#define  LCD_COL3         3
#define  LCD_COL4         4
#define  LCD_COL5         5
#define  LCD_COL6         6
#define  LCD_COL7         7
#define  LCD_COL8         8
#define  LCD_COL9         9
#define  LCD_COL10        10
#define  LCD_COL11        11
#define  LCD_COL13        13
#define  LCD_COL14        14
#define  LCD_COL15        15
#define  LCD_COL16        16

/*
	Function Name        : HLCD_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : intialize LCD
*/
void HLCD_voidInit(void);

/*
	Function Name        : HLCD_voidSendData
	Function Returns     : void
	Function Arguments   : A_u8Char
	Function Description : display character
*/
void HLCD_voidSendData(u8 A_u8Char);

/*
	Function Name        : HLCD_voidDispStr
	Function Returns     : void
	Function Arguments   : u8 A_Pu8String
	Function Description : display string
*/
void HLCD_voidDispStr(u8* A_Pu8String);

/*
	Function Name        : HLCD_voidDispIntNum
	Function Returns     : void
	Function Arguments   : u8 A_u32Number
	Function Description : display integer number
*/
void HLCD_voidDispIntNum(u32 A_u32Number);

/*
	Function Name        : HLCD_voidDispFloatNum
	Function Returns     : void
	Function Arguments   : f32 A_f32Number , u8 A_u8AfterDigit
	Function Description : display floating number
*/
void HLCD_voidDispFloatNum(f32 A_f32Number , u8 A_u8AfterDigit);

/*
	Function Name        : HLCD_voidClrScreen
	Function Returns     : void
	Function Arguments   : void
	Function Description : clear screan and move cursor to row = 1 , col = 1
*/
void HLCD_voidClrScreen(void);

/*
	Function Name        : HLCD_voidShiftDisplayRight
	Function Returns     : void
	Function Arguments   : void
	Function Description : shift display to right
*/
void HLCD_voidShiftDisplayRight(void);

/*
	Function Name        : HLCD_voidShiftDisplayLeft
	Function Returns     : void
	Function Arguments   : void
	Function Description : shift display to left
*/
void HLCD_voidShiftDisplayLeft(void);

/*
	Function Name        : HLCD_voidoidMovCursor
	Function Returns     : void
	Function Arguments   : u8 A_u8RowId, u8 A_u8ColId
	Function Description : move the cursor to posetion (row , col)
*/
void HLCD_voidMovCursor(u8 A_u8RowId, u8 A_u8ColId);

/*
	Function Name        : HLCD_voidDispSpecialChar
	Function Returns     : void
	Function Arguments   : u8 * A_u8Array, u8 A_u8Block, u8 A_u8RowId, u8 A_u8ColId
	Function Description : display special character like Arabic letter
*/
void HLCD_voidDispSpecialChar(u8 * A_u8Array, u8 A_u8Block, u8 A_u8RowId, u8 A_u8ColId);

#endif /* HAL_LCD_LCD_INT_H_ */
