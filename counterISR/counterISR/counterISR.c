#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000
#include <util/delay.h>

int count=0;


ISR(INT0_vect)
{
	count++;
	if(count==16){
		count=0;
	}
	
	PORTA = count;
	
	_delay_ms(200);
	GIFR = 0xFF;
	
}

ISR(INT1_vect)
 {	
	 count--;
	 if(count==-1){
		count=15;
	 }
	
	 PORTA = count;
	 	_delay_ms(200);

	 	GIFR = 0xFF;
	// _delay_ms(500);
 }
	
int main(void) { 
	
	DDRA = 0x0F;
	PORTA = count;
	
	GICR |= (1<<INT0) | (1<<INT1);

	//MCUCSR = MCUCSR & 0b10111111;
	MCUCR =  0b00001010; 
	
	sei();
	while(1); 
}
