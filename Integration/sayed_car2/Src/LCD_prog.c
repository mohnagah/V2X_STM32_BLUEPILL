#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"

//#include "stdio.h"
#include "LCD_private.h"
#include "LCD_conf.h"
#include "LCD_int.h"

#if   MODE == FOUR_BIT_MODE
      #if LCD_DATA_PORT == GPIO_PORTC
          #error "you must connect LCD_DATA_PORT to GPIO_PORTA or GPIO_PORTB\
                  becouse there is not enough sequintial 4 pins at port C"

      #elif LCD_DATA_PORT == GPIO_PORTA && LCD_START_BIT > GPIO_PIN9
            #error "for GPIO_PORTA PINS 13 , 14 , 15 are forbidden"

      #elif LCD_DATA_PORT == GPIO_PORTB && \
            LCD_START_BIT > GPIO_PIN7   && \
			LCD_START_BIT < GPIO_PIN12
            #error "for GPIO_PORTB can not connect to pin 11"

      #elif LCD_DATA_PORT == GPIO_PORTB && LCD_START_BIT < GPIO_PIN5
            #error "for GPIO_PORTB PINS 2 , 3 , 4 are forbidden"

      #endif
#elif MODE == EIGHT_BIT_MODE
      #if LCD_DATA_PORT != GPIO_PORTA
          #error "you must connect LCD_DATA_PORT to GPIO_PORTA \
                  becouse there is not enough sequintial 8 pins at port C or port B"
      #endif

      #if LCD_START_BIT > GPIO_PORT5
          #error "for GPIO_PORTA PINS 13 , 14 , 15 are forbidden"
      #endif
#endif

void HLCD_voidInit(void)
{
	/*iterator for for loop*/
	u8 L_u8Iterator = 0 ;

	/** Wait for more than 30ms after VDD rise to 4.5v */
	 //   ARM_DELAY (250) ;
		
	#if MODE == EIGHT_BIT_CONNECTION
	
	    /** set direction of PORT data to be output */
	    for (L_u8Iterator = 0 ; L_u8Iterator < 8 ; L_u8Iterator ++)
	    {
	    	MGPIO_voidInit(&config_output_pin_push_pull ,
	    		    		LCD_DATA_PORT               ,
	    					LCD_START_PIN + L_u8Iterator) ;
	    }
		
		/** set direction of register select to be output */
	    MGPIO_voidInit(&config_output_pin_push_pull ,
	    		        LCD_RS_PORT                 ,
						LCD_RS_PIN                  ) ;
		
		/** set direction of Enable pin to be output */
	    MGPIO_voidInit(&config_output_pin_push_pull ,
	    		        LCD_EN_PORT                 ,
						LCD_EN_PIN                  ) ;

		/** set direction of read/write pin to be output */
	    MGPIO_voidInit(&config_output_pin_push_pull ,
	    		        LCD_RW_PORT                 ,
				        LCD_RW_PIN                  ) ;
	    
	    /** function set */
	    HLCD_voidSendCmd (EIGHT_BIT_CONNECTION) ;
		
		/* Wait for command to settle */
	   // ARM_DELAY (2) ;
	    
	    /** Display ON/OFF Control */
	    HLCD_voidSendCmd (CMD_CURSOR_On_DISPLAY_ON) ;
		
		/* Wait for command to settle */
	    //ARM_DELAY (2) ;
	    
	    /** Display Clear */
	    HLCD_voidSendCmd (CMD_CLEAR) ;
		
		/* Wait for command to settle */
	    //ARM_DELAY (15) ;
	    
	    /** Entry mode set */
	    HLCD_voidSendCmd (CMD_ENTRY_MODE) ;
		
		/* Wait for command to settle */
	   // ARM_DELAY (2) ;
		
	#elif MODE == FOUR_BIT_CONNECTION
	    /** set direction of PORT data to be output */
	    for (L_u8Iterator = 0 ; L_u8Iterator < 4 ; L_u8Iterator ++)
	    {

	    	MGPIO_voidSetPinMode  ( LCD_DATA_PORT , LCD_START_PIN + L_u8Iterator , OUTPUT_SPEED_10MHZ_PP  );
	    }
		
		/** set direction of register select to be output */
	    MGPIO_voidSetPinMode  ( LCD_RS_PORT , LCD_RS_PIN , OUTPUT_SPEED_10MHZ_PP  );

		/** set direction of Enable pin to be output */
	    MGPIO_voidSetPinMode  ( LCD_EN_PORT , LCD_EN_PIN , OUTPUT_SPEED_10MHZ_PP  );

		/** set direction of read/write pin to be output */
	    MGPIO_voidSetPinMode  ( LCD_RW_PORT , LCD_RW_PIN , OUTPUT_SPEED_10MHZ_PP  );

	    /** Return home*/
	    HLCD_voidSendCmd (CMD_RETURN_HOME) ;
		
		/* Wait for command to settle */
	   // ARM_DELAY (10) ;
	    
	    /** function set */
	    HLCD_voidSendCmd (FOUR_BIT_CONNECTION) ;
		
		///* Wait for command to settle */
	   // ARM_DELAY (1) ;
	    
	    /** Display ON/OFF Control */
	    HLCD_voidSendCmd (CMD_CURSOR_On_DISPLAY_ON) ;
		
		/* Wait for command to settle */
	   // ARM_DELAY (1) ;
	    
	    /** Display Clear */
	    HLCD_voidSendCmd (CMD_CLEAR) ;
		
		/* Wait for command to settle */
	    //ARM_DELAY (10) ;
	    
	    /** Entry mode set */
	    HLCD_voidSendCmd (CMD_ENTRY_MODE) ;
		
		/* Wait for command to settle */
	    //ARM_DELAY (1) ;
	#else 
		#error "selecct right mode"
	#endif
}
void HLCD_voidSendData(u8 A_u8Char)
{
	/*iterator for for loop*/
	u8 L_u8Iterator = 0 ;
	#if MODE == EIGHT_BIT_CONNECTION
	    
		/**set read/write to low */
	    MGPIO_VidSetPinValue (LCD_RW_PORT , LCD_RW_PIN  , LOW) ;
		
		/**send data to control register */
	    for (L_u8Iterator = 0 ; L_u8Iterator < 8 ; L_u8Iterator ++)
	    {
	    	 MGPIO_VidSetPinValue (LCD_DATA_PORT ,
	    	    			        LCD_START_PIN + L_u8Iterator ,
	    							GET_BIT(A_u8Char , L_u8Iterator)) ;
	    }

		/**set register select to high */
		MGPIO_VidSetPinValue  (LCD_RS_PORT , LCD_RS_PIN , HIGH) ;
		
		/**set enable to high */
		MGPIO_VidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , HIGH) ;
		
		/* Wait for E to settle */
		//ARM_DELAY (2) ;
		
		/**set enable to low */
		MGPIO_VidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , LOW) ;
		
		/* Wait for E to settle */
		//ARM_DELAY (2) ;
	
	#elif MODE == FOUR_BIT_CONNECTION
	    /**set read/write to low */
		MGPIO_voidSetPinValue  (LCD_RW_PORT , LCD_RW_PIN , GPIO_LOW) ;

	    /**send last four bits of data to last four bit at control register */
	    for (L_u8Iterator = 0 ; L_u8Iterator < 4 ; L_u8Iterator ++)
	    {
	    	MGPIO_voidSetPinValue (LCD_DATA_PORT                           ,
	    			               LCD_START_PIN + L_u8Iterator            ,
	    					       GET_BIT(A_u8Char , (L_u8Iterator + 4))) ;
	    }

	    /**set register select to high */
	    MGPIO_voidSetPinValue (LCD_RS_PORT , LCD_RS_PIN , GPIO_HIGH) ;

	    /**set enable to high */
	    MGPIO_voidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , GPIO_HIGH) ;

	    /* Wait for E to settle */
	   // ARM_DELAY (2) ;

	    /**set enable to low */
	    MGPIO_voidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , GPIO_LOW) ;

	    /* Wait for E to settle */
	    //ARM_DELAY (2) ;

	    /**set read/write to low */
	    MGPIO_voidSetPinValue  (LCD_RW_PORT , LCD_RW_PIN , GPIO_LOW) ;

	    /**send last four bits of data to last four bit at control register */
	    for (L_u8Iterator = 0 ; L_u8Iterator < 8 ; L_u8Iterator ++)
	    {
	    	MGPIO_voidSetPinValue (LCD_DATA_PORT                       ,
	    			               LCD_START_PIN + L_u8Iterator        ,
	    					       GET_BIT((A_u8Char) , L_u8Iterator)) ;
	    }

	    /**set register select to low */
	    MGPIO_voidSetPinValue (LCD_RS_PORT , LCD_RS_PIN , GPIO_HIGH) ;

	    /**set enable to high */
	    MGPIO_voidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , GPIO_HIGH) ;

	    /* Wait for E to settle */
	  //  ARM_DELAY (2) ;

	    /**set enable to low */
	    MGPIO_voidSetPinValue  (LCD_EN_PORT , LCD_EN_PIN , GPIO_LOW) ;

	    /* Wait for E to settle */
	  //  ARM_DELAY (2) ;
	    #else
	         #error "select write mode"
	    #endif
	    //ARM_DELAY(1) ;
}

void HLCD_voidDispStr(u8* A_Pu8String)
{
	/**Local loop index */
	u8 L_u8Index = 0 ;
	while (A_Pu8String [L_u8Index] != '\0')
	{
		/* Write Character on LCD */
		HLCD_voidSendData (A_Pu8String [L_u8Index]) ;
		
		/* Increment local loop index */
		L_u8Index ++ ;
	}
}

void HLCD_voidDispIntNum(u32 A_u32Number)
{
	if (A_u32Number < (u32)MIN_INT_NUM && A_u32Number > (u32)MAX_INT_NUM)
	{
		/**
		 * if the integer is more than MAX_INT_NUM or less than MIN_INT_NUM
		          **** "Overflow !!!!" will be displayed
		 */
		HLCD_voidClrScreen () ;
		HLCD_voidDispStr ((u8*)"Overflow !!!!") ;
	}
	else
	{
		/**array to stored conversion character*/
	    s8 L_Ps8String [16] = {0} ;

		/** convert integer to string*/
	   sprintf (L_Ps8String , "%d" , (int*)A_u32Number) ;
		/**display number after convesion*/
	    HLCD_voidDispStr ((u8*)L_Ps8String) ;
	}
}

void HLCD_voidDispFloatNum(f32 A_f32Number , u8 A_u8AfterDigit)
{
	u16 L_u16AfterDigit = 1 ;
	u8  L_u8Iterator = 0 ;
	/** display integer part */
    HLCD_voidDispIntNum ((u32)A_f32Number) ;

	/** display dot */
	HLCD_voidSendData   (',') ;

	for (L_u8Iterator = 0 ; L_u8Iterator < A_u8AfterDigit ; L_u8Iterator ++)
	{
		L_u16AfterDigit = L_u16AfterDigit * BASE ;
	}

	/** display fraction part */
	HLCD_voidDispIntNum ((A_f32Number - (u32) A_f32Number) * L_u16AfterDigit) ;
}

void HLCD_voidMovCursor(u8 A_u8RowId, u8 A_u8ColId)
{
	/**local variable to stored DDRAM address*/
	u8 L_u8DDRAMAddress ;
	
	/**if the row and col are out of range 
	         *** Do nothing
	  */
	if (A_u8RowId >= MIN_NUM_OF_ROW && A_u8RowId <= MAX_NUM_OF_ROW &&
	A_u8ColId >= MIN_NUM_OF_COL && A_u8ColId <= MAX_NUM_OF_COL)
	{
		/**for first row*/
		if (A_u8RowId == LCD_ROW1)
		{
			L_u8DDRAMAddress = FIRST_ROW_ADDRESS + A_u8ColId - 1 ;
			/**set DDRAM address*/
			HLCD_voidSendCmd (L_u8DDRAMAddress) ;
		}
		
		/**for second row*/
		else if (A_u8RowId == LCD_ROW2)
		{
			L_u8DDRAMAddress = SECOND_ROW_ADDRESS + A_u8ColId - 1 ;
			/**set DDRAM address*/
			HLCD_voidSendCmd (L_u8DDRAMAddress) ;
		}
	}
	else
	{
		/** DO Nothing */
	}
}

void HLCD_voidClrScreen (void)
{
	/**clear data and move cursor to first position*/
	HLCD_voidSendCmd (CMD_CLEAR) ;
}

void HLCD_voidShiftDisplayRight(void)
{
	/**shift display to right*/
	HLCD_voidSendCmd (SHIFT_DISPLAY_TO_RIGHT) ;
}

void HLCD_voidShiftDisplayLeft(void)
{
	/**shift display to left*/
	HLCD_voidSendCmd (SHIFT_DISPLAY_TO_LEFT) ;
}

void HLCD_voidDispSpecialChar(u8 * A_u8Array, u8 A_u8Block, u8 A_u8RowId, u8 A_u8ColId)
{
	/**iterator for for loop*/
	u8 L_u8Iterator ;
	
	/**set CGRAM address (001x xxxx) */
	HLCD_voidSendCmd ((A_u8Block * NUMBER_OF_BLOCKS_OF_CGRAM) | SET_CGRAM_ADDRESS) ;
	
	/** Send the array to be stored */
	for (L_u8Iterator =  FIRST_INDEX_OF_EACH_BLOCK ;
	     L_u8Iterator <= END_INDEX_OF_EACH_BLOCK   ;
		 L_u8Iterator ++ )
		 {
			 HLCD_voidSendData (A_u8Array [L_u8Iterator]) ;
		 }
    
	/* Move the cursor to required position */
	HLCD_voidMovCursor (A_u8RowId , A_u8ColId) ;
	
	/* Set the block to be displayed */
	HLCD_voidSendData (A_u8Block) ;
}
