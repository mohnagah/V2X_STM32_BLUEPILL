#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "LCD_conf.h"
#include "LCD_private.h"

void HLCD_voidSendCmd(u8 A_u8CmdID)
{
	/*iterator for for loop*/
	u8 L_u8Iterator = 0 ;
	#if MODE == EIGHT_BIT_CONNECTION
	    /**set read/write to low */
	    MGPIO_VidSetPinValue  (LCD_RW_PORT , LCD_RW_PIN , LOW) ;
	    
	    /**send cmd to control register */
	    for (L_u8Iterator = 0 ; L_u8Iterator < 8 ; L_u8Iterator ++)
	    {
	    	MGPIO_VidSetPinValue (LCD_DATA_PORT ,
	    			               LCD_START_PIN + L_u8Iterator ,
								   GET_BIT(A_u8CmdID , L_u8Iterator)) ;
	    }
	    
	    /**set register select to low */
	    MGPIO_VidSetPinValue (LCD_RS_PORT , LCD_RS_PIN , LOW) ;
	    
	    /**set enable to high */
	    MGPIO_VidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , HIGH) ;
	    
	    /* Wait for E to settle */
	    ARM_DELAY (2) ;
	    
	    /**set enable to low */
	    MGPIO_VidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , LOW) ;
	    
	    /* Wait for E to settle */
	    ARM_DELAY (2) ;
	
	#elif MODE == FOUR_BIT_CONNECTION
	
	    /**set read/write to low */
	    MGPIO_voidSetPinValue  (LCD_RW_PORT , LCD_RW_PIN , GPIO_LOW) ;
	    
	    /**send last four bits of data to last four bit at control register */
	    for (L_u8Iterator = 0 ; L_u8Iterator < 4 ; L_u8Iterator ++)
	    {
	    	MGPIO_voidSetPinValue (LCD_DATA_PORT                    ,
	    			               LCD_START_PIN + L_u8Iterator     ,
	    					       GET_BIT(A_u8CmdID , (L_u8Iterator + 4)));
	    }
	    
	    /**set register select to low */
	    MGPIO_voidSetPinValue (LCD_RS_PORT , LCD_RS_PIN , GPIO_LOW) ;
	    
	    /**set enable to high */
	    MGPIO_voidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , GPIO_HIGH) ;

	    /* Wait for E to settle */
	    ARM_DELAY (2) ;
	    
	    /**set enable to low */
	    MGPIO_voidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , GPIO_LOW) ;
	    
	    /* Wait for E to settle */
	    ARM_DELAY (2) ;
	    
	    
	    /**set read/write to low */
	    MGPIO_voidSetPinValue  (LCD_RW_PORT , LCD_RW_PIN , GPIO_LOW) ;
	    
	    /**send last four bits of data to last four bit at control register */
	    for (L_u8Iterator = 0 ; L_u8Iterator < 8 ; L_u8Iterator ++)
	    {
	    	MGPIO_voidSetPinValue (LCD_DATA_PORT                       ,
	    			               LCD_START_PIN + L_u8Iterator        ,
	    					       GET_BIT((A_u8CmdID) , L_u8Iterator)) ;
	    }
	    
	    /**set register select to low */
	    MGPIO_voidSetPinValue (LCD_RS_PORT , LCD_RS_PIN , GPIO_LOW) ;
	    
	    /**set enable to high */
	    MGPIO_voidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , GPIO_HIGH) ;
	    
	    /* Wait for E to settle */
	    ARM_DELAY (2) ;
	    
	    /**set enable to low */
	    MGPIO_voidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , GPIO_LOW) ;
	    
	    /* Wait for E to settle */
	    ARM_DELAY (2) ;
	    #else
	         #error "select write mode"
	    #endif
	    ARM_DELAY(1) ;
}
