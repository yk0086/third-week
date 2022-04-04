#include"reg51.h"
unsigned char s[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char num = 0;
void initcounter()
{		 
	TMOD = 0x06;//工作方式2:0000 0110
	TH0 = 256-3;
	TL0 = 256-3;
	ET0 = 1;//开启定时器0中断
	EA = 1;//开启总中断
	TR0 = 1;//启动定时器0
}	
void display()
{
	if(num==10)//到10后清0
	{
		num = 0;
	}
	/*每按3次定时器加1次*/
	P2 = s[num];
}
void main()
{
	initcounter();
	while(1)
	{
		display();
	}
}

void counter_isr() interrupt 1
{
	num++;
}