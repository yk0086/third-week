#include"reg51.h"
unsigned char s[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char num = 0;
void initcounter()
{		 
	TMOD = 0x06;//������ʽ2:0000 0110
	TH0 = 256-3;
	TL0 = 256-3;
	ET0 = 1;//������ʱ��0�ж�
	EA = 1;//�������ж�
	TR0 = 1;//������ʱ��0
}	
void display()
{
	if(num==10)//��10����0
	{
		num = 0;
	}
	/*ÿ��3�ζ�ʱ����1��*/
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