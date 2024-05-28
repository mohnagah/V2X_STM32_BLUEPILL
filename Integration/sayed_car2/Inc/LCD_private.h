#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define ARM_DELAY(d)   do{unsigned long int i=(d * 5000); while(i--){asm("nop");}}while(0)

/** Comands of LCD */
#define CMD_CLEAR                      0x01     /* replace all characters with ASCII 'space'     */
#define CMD_RETURN_HOME                0x02     /* return cursor to first position on first line */
#define CMD_ENTRY_MODE                 0x06     /* shift cursor from left to right on read/write */
#define CMD_CURSOR_OFF_DISPLAY_OFF     0x08     /* turn display off and cursor off               */
#define CMD_CURSOR_OFF_DISPLAY_ON      0x0C     /* turn display on and cursor off                */
#define CMD_CURSOR_On_DISPLAY_OFF      0x0A     /* turn display off and cursor on                */
#define CMD_CURSOR_On_DISPLAY_ON       0x0E     /* turn display on and cursor on                 */
#define EIGHT_BIT_CONNECTION           0x38     /* 8-bit data, 2-line display, 5 x 7 font        */
#define FOUR_BIT_CONNECTION            0x28     /* 4-bit data, 2-line display, 5 x 7 font        */
#define CMD_CURSOR_OFFSET              0x80     /* set cursor position                           */
#define SHIFT_CURSOR_RIGHT             0x14     /* shift cursor  to right                        */
#define SHIFT_CURSOR_LEFT              0x10     /* shift cursor  to left                         */
#define SHIFT_DISPLAY_TO_RIGHT         0x1C     /* shift display to right                        */
#define SHIFT_DISPLAY_TO_LEFT          0x18     /* shift display to left                         */

/**maximum value of integer number that be displayed*/
#define MAX_INT_NUM                    999999999
/**minimum value of integer number that be displayed*/
#define MIN_INT_NUM                   -999999999

/**address of first position of row1 at DDRRA*/
#define FIRST_ROW_ADDRESS              0x80
/**address of first position of row2 at DDRRA*/
#define SECOND_ROW_ADDRESS             0xc0

/**first address of DDRAM*/
#define SET_DDRAM_ADDRESS              0x80

/**first address of CGRAM*/
#define SET_CGRAM_ADDRESS              0x40

/**number of blocks of CGRAM (64 bytes / 8) */
#define NUMBER_OF_BLOCKS_OF_CGRAM      8
#define FIRST_INDEX_OF_EACH_BLOCK      0
#define END_INDEX_OF_EACH_BLOCK        7

/**
	Function Name        : HLCD_voidSendCmd
	Function Returns     : void
	Function Arguments   : u8 A_u8CmdID
	Function Description : send command to lcd 
*/
void HLCD_voidSendCmd(u8 A_u8CmdID) ;

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
