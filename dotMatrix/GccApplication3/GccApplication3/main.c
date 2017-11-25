#include <avr/io.h>
//header to enable data flow control over pins
#define F_CPU 1000000
//telling controller crystal frequency attached
#include <util/delay.h>
//header to enable delay function in program

char PORT[8] = {1,2,4,8,16,32,64,128};//pin values of PORTD
	static int ALPHA[27][8]={{0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111},
	{0,0b11111111,0b11111111,0b11011011,0b11011011,0b11011011,0b01111110,0b00111100},
	{0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100},
	{0,0b01111110,0b10111101,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111},
	{0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111},
	{0,0b11011000,0b11011000,0b11011000,0b11011000,0b11011000,0b11111111,0b11111111},
	{0b00011111,0b11011111,0b11011000,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111},
	{0,0b11111111,0b11111111,0b00011000,0b00011000,0b00011000,0b11111111,0b11111111},
	{0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011},
	{0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000011,0b11001111,0b11001111},
	{0,0b11000011,0b11100111,0b01111110,0b00111100,0b00011000,0b11111111,0b11111111},
	{0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111},
	{0b11111111,0b11111111,0b01100000,0b01110000,0b01110000,0b01100000,0b11111111,0b11111111},
	{0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111},
	{0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110},
	{0,0b01110000,0b11111000,0b11001100,0b11001100,0b11001100,0b11111111,0b11111111},
	{0b01111110,0b11111111,0b11001111,0b11011111,0b11011011,0b11000011,0b11111111,0b01111110},
	{0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111},  
	{0b11001110,0b11011111,0b11011011,0b11011011,0b11011011,0b11011011,0b11111011,0b01110011},
	{0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000},
	{0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110},
	{0b11100000,0b11111100,0b00011110,0b00000011,0b00000011,0b00011110,0b11111100,0b11100000},
	{0b11111110,0b11111111,0b00000011,0b11111111,0b11111111,0b00000011,0b11111111,0b11111110},
	{0b01000010,0b11100111,0b01111110,0b00111100,0b00111100,0b01111110,0b11100111,0b01000010},
	{0b01000000,0b11100000,0b01110000,0b00111111,0b00111111,0b01110000,0b11100000,0b01000000},
	{0b11000011,0b11100011,0b11110011,0b11111011,0b11011111,0b11001111,0b11000111,0b11000011},
	{0b11111111,0b11111111,0b11011000,0b11011100,0b11011110,0b11011111,0b11111011,0b01111001}};//characters a,
	char NAME[]={0,5,17,8,13,0,4,10,19,0,1,0,0,11};//circuit diagram character values
	uint8_t l =0;
int main(void)
{
	DDRD = 0xFF;//PORTB,C,D are set as output
	DDRA = 0xFF;
	DDRC = 0xFF;
	
	while(1)
	{
		/*
		
		for (int m=0;m<sizeof NAME;m++)
		{
			l = NAME[m];
			for (int n=0;n<200;n++)//execute 200 times for the eye to catch
			{
				for (int j=0;j<8;j++)
				{
					PORTA = PORT[j];// ROW
					PORTD = ~ALPHA[l][j];//show character (COLUMN)
					_delay_us(500);
					
				}
				
				PORTA=0x00;//clear screen after show
				for (int k=0;k<4;k++)
				{
					PORTC = PORT[k];// ROW
					
					PORTD = ~ALPHA[l][k+4];//show other half of character(COLUMN)
					_delay_us(500);
					
				}
				PORTC=0x00;//clear screen after show.
				
			}
		}
		
		*/
		rotate1();
		//rotate3();
		//blinkS();
		//_delay_ms(220);
	
		
		
	}
}

void rotate1()
{
	int i,j,k,tempAlpha,temp;
	unsigned char column;
	for(int i=0 ; i<=8; i++){
		for (int n=0;n<200;n++){ //to catch eye
				for (int j=0;j<8;j++)
				{
					PORTA = PORT[j];// ROW
					tempAlpha = ALPHA[0][j];
					temp = tempAlpha;
					temp<<=(8-i);
					temp= (tempAlpha>>i) | temp;//show character (COLUMN)
					PORTD = ~temp;//show character (COLUMN)

					_delay_us(500);
					
				}
				
				PORTA=0x00;//clear screen after show
				/*for (int k=0;k<4;k++)
				{
					PORTC = PORT[k];// ROW
					
					PORTD = ~ALPHA[l][k+4];//show other half of character(COLUMN)
					_delay_us(500);
					
				}
				PORTC=0x00;//clear screen after show.
				*/
			}
		}
}

void rotate2()
{
	int i,j,k,tempAlpha,temp;
	unsigned char column;
	for(int i=0 ; i<=8; i++){
		for (int n=0;n<200;n++){ //to catch eye
				for (int j=0;j<8;j++)
				{
					PORTA = PORT[j];// ROW
					tempAlpha = ALPHA[0][(i+j)%8];
					
					PORTD = ~tempAlpha;//show character (COLUMN)

					_delay_us(500);
					
				}
				
				PORTA=0x00;//clear screen after show
				/*for (int k=0;k<4;k++)
				{
					PORTC = PORT[k];// ROW
					
					PORTD = ~ALPHA[l][k+4];//show other half of character(COLUMN)
					_delay_us(500);
					
				}
				PORTC=0x00;//clear screen after show.
				*/
			}
		}
}

void blinkS()
{
	int i,j,k,tempAlpha,temp;
	unsigned char column;

		for (int n=0;n<20;n++){ //to catch eye
				for (int j=0;j<8;j++)
				{
					PORTA = PORT[j];// ROW
					tempAlpha = ALPHA[26][j];
					
					PORTD = ~tempAlpha;//show character (COLUMN)

					_delay_us(500);
					
				}
				
				PORTA=0x00;//clear screen after show
				_delay_us(500);
				/*for (int k=0;k<4;k++)
				{
					PORTC = PORT[k];// ROW
					
					PORTD = ~ALPHA[l][k+4];//show other half of character(COLUMN)
					_delay_us(500);
					
				}
				PORTC=0x00;//clear screen after show.
				*/
			}

}

void rotate3()
{
	int i,j,k,tempAlpha,temp;
	unsigned char column;
	for(int i=8 ; i>=0; i--){
		for (int n=0;n<200;n++){ //to catch eye
				for (int j=0;j<8;j++)
				{
					PORTA = PORT[j];// ROW
					tempAlpha = ALPHA[0][(i+j)%8];
					
					PORTD = ~tempAlpha;//show character (COLUMN)

					_delay_us(500);
					
				}
				
				PORTA=0x00;//clear screen after show
				/*for (int k=0;k<4;k++)
				{
					PORTC = PORT[k];// ROW
					
					PORTD = ~ALPHA[l][k+4];//show other half of character(COLUMN)
					_delay_us(500);
					
				}
				PORTC=0x00;//clear screen after show.
				*/
			}
		}
}
//show character (COLUMN)