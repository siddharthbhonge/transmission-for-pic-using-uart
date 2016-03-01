 


#include <P18f4520.h>

#pragma config OSC=HS
#pragma config PWRT=OFF
#pragma config WDT=OFF
#pragma config DEBUG=OFF, LVP=OFF 
unsigned char data;

void main()
{
		
		TRISD = 0x00;
		
		ADCON1=0x0F;  

		TRISCbits.TRISC7=1;        //Make UART RX pin input
	    	RCSTA=0X90;			//Serial port enabled
		SPBRG=12; 		//Fill SPBRG register to set the baud rate
		//SPBRGH  = 0;    	 //4800bps 
		//BAUDCON=0X00;	        
	

		while(1)
			{
		 		 while(PIR1bits.RCIF==0);
 
             		  	 {
		             		data=RCREG;
					PORTD=data;
					
				}
			}
            }
