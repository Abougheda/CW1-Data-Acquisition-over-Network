void uart_SetBaudRate(int BRate);
void uart_init(int BRate);
void uart_transmit(char* data);
unsigned char uart_receive(void);
int uart_receive_bit(void);
void DIO_SetPinDirection(unsigned char port, int pin, unsigned char direction);
void DIO_SetPinState(unsigned char port, int pin, unsigned char direction); 