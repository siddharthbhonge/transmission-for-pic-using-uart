#include<p18f4520.h>
#pragma config OSC=HS
#pragma config PWRT=OFF
#pragma config WDT=OFF
#pragma config DEBUG=OFF, LVP=OFF 


void  sendUSART (void);
unsigned char text[]="\n\rSALIL";

unsigned int i=0;
void main(void)
 
{
        ADCON1=0x0F;
	TXSTA=0X20;
	SPBRG=12;		//BAUDRATE=4800
	TXSTAbits.TXEN=1;
	RCSTAbits.SPEN=1;
	 sendUSART ();
	while(1); 
}

void  sendUSART (void)
{
	while(text[i]!='\0')
		{	
			while(PIR1bits.TXIF==0);
				TXREG=text[i];
				i++;
		}
}
