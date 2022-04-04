#include <reg52.h>

#define ON  0
#define OFF 1

sbit BUZZER = P0^7;

void delay_ms(unsigned int nms)
{
	 unsigned int i,j;

	 for(i=nms;i>0;i--)
	 	for(j=120;j>0;j--);
}

void main()
{	
	BUZZER = ON;
	while(1);
}