#include<reg52.h>

sbit BUZZ = P1^6;

//高低位
unsigned char T0RH = 0;
unsigned char T0RL = 0;


//打开关闭蜂鸣器		   /*频率*/
void OpenBuzz(unsigned int frequ);
void StopBuzz();
void main()
{
	unsigned int i;
	//设置工作模式
	TMOD = 0x01;
	//使能全局中断
	EA = 1;
	while(1)
	{	
		//4k赫兹
		OpenBuzz(4000);
		for(i=0;i<40000;i++);
		StopBuzz();
		for(i=0;i<40000;i++);
	}
}
void OpenBuzz(unsigned int frequ)
{
	//计算初值
	unsigned int reload;
					/*机器周期*/
	reload = 65536-(11059200/12)/(frequ*2);
	/*16位分成两个8位*/
	//高位
	T0RH = (unsigned char)(reload>>8);
	//低位
	T0RL = (unsigned char)reload;

	TH0 = 0xFF;
	TL0 = 0xFE;

	ET0 = 1;
	TR0 = 1;
}
void StopBuzz()
{
	ET0 = 0;
	TR0 = 0;
}
void InterruptTimer0() interrupt 1
{
	TH0 = T0RH;
	TL0 = T0RL;
	BUZZ = ~BUZZ;
}