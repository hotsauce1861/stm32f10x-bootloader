#ifndef USART_H
#define USART_H

//default 8N1
#define COM_PORT	USART3
#define TX_PIN		GPIO_Pin_10
#define RX_PIN		GPIO_Pin_11
#define BAUDRATE	115200

void usart_init(void);
int usart_printf(const char *fmt, ... );

#endif
