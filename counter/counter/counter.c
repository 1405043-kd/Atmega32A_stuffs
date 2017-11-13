#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>


int main(void)
{
	unsigned char c = 0, up = 0, down = 0;
	DDRA = 0x0F;
	PORTA = 0xFF;
	//PORTC = 0x00;
	DDRB=0x00;
	PORTB = 0x00;
	
	
    /* Replace with your application code */
    while (1) 
    {
		PORTA = c;
		//up = PINC;
		down = PINB;
		if(down==0b00001000){
			c++;
			if(c>15) c = 0;
			_delay_ms(500);
		}
		if(down==0b000010000){
			c--;
			if(c<0) c = 15;
			_delay_ms(500);
		}
		
    }
}

