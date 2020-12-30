#ifndef USART_H_
#define USART_H_

void USART_vodinit(void);
u8 USART_u8ReadChar(void);
void USART_u8WriteData(u8 Data);
u8 USART_u8CheckReceive(void);


#endif

