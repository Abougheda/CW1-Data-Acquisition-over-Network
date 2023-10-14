void uart_SetBaudRate(int BRate){
  int ubrr = ((F_CPU)/(BRate*16UL)-1);  //function to change baudrate, = 103
  UBRR0H = (ubrr>>8);               //set the high baudrate
  UBRR0L = ubrr;                    //set the low baudrate
}

void uart_init(int BRate){
  uart_SetBaudRate(BRate); //run the previous BaudRate setup function
  UCSR0B |= (1<<TXEN0)|(1<<RXEN0);  //enable the transmitter and receiver
  UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);//set format to 8-bit
}

void uart_transmit(unsigned char data){
  int udr_empty; //initialize the udr empty boolean-like variable
  do{
    udr_empty = (UCSR0A & (1<<UDRE0)) != 0; //check the data buffer if empty or not
  }while(!udr_empty); //loop if data buffer is full

  UDR0 = data; //send the data to the data bus
}




void uart_transmit_array(char* data, int size){ //parameters are character array(string) and length of array to be able to loop on it
  for(int i = 0; i < size; i++){ //for loop
    while(!(UCSR0A & (1<<UDRE0))); //while loop to wait for the character to be received before sending another one
    UDR0 = (int) data[i]; //sending the character bit
  }
}


unsigned char uart_receive(void){
  if(!uart_receive_bit()){
    return;
  }else {
    return UDR0;
  } 
}

int uart_receive_bit(void){
  int flag = ((UCSR0A)&(1<<RXC0)) != 0; //checks the 7th bit of the register which means the received completed successfully
  return flag;
}

  

void DIO_init(){
  DIO_SetPinDirection('b',8,'o'); // output D8
  DIO_SetPinDirection('d',2,'i'); // input D7

}

void DIO_SetPinDirection(unsigned char port, int pin, unsigned char direction){
  if (port=='b' & pin<=7 & pin>=0){
    if(direction =='o'){
      DDRB = DDRB|(1<<pin); //bit set to 1 for output
  }else if (direction == 'i'){
    DDRB = DDRB&!(1<<pin); // bit cleared for 0 output
  }
}
 
 if (port=='d' & pin<=7 & pin>=0){
    if(direction =='o'){
      DDRD = DDRD|(1<<pin); //bit set to 1 for output
  }else if (direction == 'i'){
    DDRD = DDRD&!(1<<pin); // bit cleared for 0 output
  }
}
}

void DIO_SetPinState(unsigned char port, int pin, unsigned char state){
  if (port=='b' & pin<=7 & pin>=0){
    if(state =='1'){
      PORTB = PORTB|(1<<pin); // pin is set to 1 for high
    } else if (state =='0');{
      PORTB &= ~(1<<pin); //pin is cleared to 0 for low
    }
} 


 if (port=='d' & pin<=7 & pin>=0){
    if(state =='1'){
      PORTD = PORTD|(1<<pin); // pin is set to 1 for high
    } else if (state =='0');{
      PORTD &= ~(1<<pin); //pin is cleared to 0 for low
    }
 }
} 


