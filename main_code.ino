#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "uart.h"
#define BAUD 9600 //defining the baud rate 
#define BUTTON PIND

int main(void){
  uart_init(BAUD);
  
  char button_on[8] = "PRESSED\n";

  
 int buttonpin = 7;
  
  while(1){
//loop for running system
    
    char led = uart_receive();
    DIO_SetPinDirection('b',0,'o');
    if (led=='0'){
      DIO_SetPinState('b',8,1);
      uart_transmit_array("LED turned off\n",14);
      PORTB |= 0b00000001;
    }else if (led=='1'){
      DIO_SetPinState('b',8,0);
      uart_transmit_array("LED turned on\n",15);
      PORTB &= 0b11111110;
    }

  
      



 // BUTTON CODE    
    DIO_SetPinDirection('d',7,'i');
    DIO_SetPinState('d',7,'1');    
if (BUTTON & (1<<buttonpin)){
  
}
else {
 uart_transmit_array(button_on,8);
}
}
}






