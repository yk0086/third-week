#include"reg51.h"

unsigned char ledat[] = {
	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
};

void delay(unsigned int n)
{
	unsigned int i = 0,j = 0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<120; j++);

	}
}
void led()	 
{
	unsigned int i;
	for(i=0; i<8; i++)
	{
		//Á÷Ë®µÆ
		P2 = ~ledat[i];
		//ÅÜÂíµÆ
		//P2 = ledat[i];
		delay(100);
	}

}

void main()
{
	while(1)
	{
		led();
	}
}