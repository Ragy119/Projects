#ifndef DIO_1
#define DIO_1

void DIO_VidInitPortDir(void);
void DIO_VidInitPortValue(void);
void DIO_VidWritPin(u8 copy_u8PinNum,u8 copy_u8PinVal);
u8 DIO_u8ReadPin(u8 copy_u8PinNum);
void DIO_VidWritPort(u8 copy_u8PortNum,u8 copy_u8PortVal);
u8 DIO_u8ReadPort(u8 copy_u8PortNum);



#endif