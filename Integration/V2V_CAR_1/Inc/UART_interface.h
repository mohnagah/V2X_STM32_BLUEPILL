#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#define USART1_DISABLE          0
#define USART1_ENABLE           1



#define _8BIT_WORD_LENGTH       0
#define _9BIT_WORD_LENGTH       1

#define PARITY_DISABLE          0
#define EVEN_PARITY             1
#define ODD_PARITY              2

#define INT_DISABLE             0
#define TXE_INT_ENABLE          1
#define TCE_INT_ENABLE          3
#define RXNE_INT_ENABLE         5

#define TRANSMITTER_DISABLE     0
#define TRANSMITTER_ENABLE      1

#define RECEIVER_DISBLE         0
#define RECEIVER_ENABLE         1

#define ONE_STOP_BIT            0
#define HALF_STOP_BIT           1
#define TWO_STOP_BIT            2
#define ONE_AND_HALF_STOP_BIT   3


void MUSART_VidInit             ( void                ) ;



void MUSART1_VidSendCharSync    ( u8 Copy_u8Char      ) ;



void MUSART1_VidSendStringSynch ( u8 * Copy_ptrString ) ;



u8   MUSART1_u8RecCharSynch     ( void                ) ;



u8 * MUSART1_PtrReadStringSynch ( void                ) ;



void MUSART1_VidSetCallBack     ( void (*ptr) (void)  ) ;


void MUSART1_voidTransmit(u8 data);






















#define UART3_RX_PORT GPIO_PORTB
#define UART3_RX_PIN  GPIO_PIN11

#define UART3_TX_PORT GPIO_PORTB
#define UART3_TX_PIN  GPIO_PIN10

void UART3_voidInit(void);

void UART3_voidDisable(void);

void UART3_voidEnable(void);

void UART3_voidTransmitSynch(u8 u8DataCpy);

u8 UART3_u8ReceiveSynch(void);

void UART3_voidTransmitStringSynch(const u8* pu8DataCpy);

u8 UART3_u8GetData(void);

void UART3_voidReceiveIntEnable(void);

void UART3_voidReceiveIntDisable(void);

void UART3_voidSetCallBack(pf pfUART3ISRCpy);

u32* UART3_pu32DMAReceiveAddress(void);

#endif
