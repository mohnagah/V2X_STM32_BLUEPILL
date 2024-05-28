#ifndef HAL_LCD_LCD_CONF_H_
#define HAL_LCD_LCD_CONF_H_

/*
 *Connections of Data
     ** Options of PORTS :
	           *GPIO_PORTA
			   *GPIO_PORTB
			   *GPIO_PORTC
			   
	 ** Options of PINS :
	           *GPIO_PIN0
			   *GPIO_PIN1
			   *GPIO_PIN2
			   *GPIO_PIN3
			   *GPIO_PIN4
			   *GPIO_PIN5
			   *GPIO_PIN6
			   *GPIO_PIN7
			   *GPIO_PIN8
			   *GPIO_PIN9
			   *GPIO_PIN10
			   *GPIO_PIN11
			   *GPIO_PIN12
			   *GPIO_PIN13
			   *GPIO_PIN14
			   *GPIO_PIN15
*/

/*
 * "for LCD_PIN PA13 , PA14 , PA15 are forbidden pins"
 * "for LCD_PIN PB2 , PB3 , PB4 are forbidden pins"
 * "for LCD_PIN PC13 , PC14 , PC15 are only allowed pins"
 */

/* Data */
#define LCD_DATA_PORT GPIO_A

/*Define start pin*/
#define LCD_START_PIN PIN3

/* Register Select */
#define LCD_RS_PORT   GPIO_C
#define LCD_RS_PIN    PIN13

/* Enable */
#define LCD_EN_PORT   GPIO_C
#define LCD_EN_PIN    PIN14

/* Read / write  */
#define LCD_RW_PORT   GPIO_C
#define LCD_RW_PIN    PIN15

/*
 *Select the mode of connections
    ** Options 
	      *EIGHT_BIT_CONNECTION
		  *FOUR_BIT_CONNECTION
		  
	** If you select EIGHT_BIT_CONNECTION
	        eight pins of port connected to  eight data pins
			
	** If you select EIGHT_BIT_CONNECTION
	        high nibble pins of port connected to  last four data pins		
 */
#define MODE  FOUR_BIT_CONNECTION

/** Base of number that be converted to string */
#define BASE   10

#endif /* HAL_LCD_LCD_CONF_H_ */
