#include<reg52.h>

sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;


void main()
{
	unsigned char cnt = 0;
	unsigned char count = 0;
	unsigned char flag = 0;
	/*定时器设置*/
	TMOD = 0x01;
	TH0 = 0xB8;
	TL0 = 0x00;
	TR0 = 1;
	
	ENLED = 0;
	ADDR3 = 1;
	/*三极管导通LEDS6*/
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;
	/*流水灯*/
	while(1)
	{
		/*外层控制亮灭及时间间隔*/
		if(TF0==1)
		{
			TF0 = 0;
			TH0 = 0xB8;
			TL0 = 0x00;
			cnt++;
			/*内层控制亮灯地址*/
			/*外层循环50次进入内层*/
			/*内层每次进行1次*/
			if(cnt == 50)
			{
				cnt = 0;
				/*P0 0000 0001 到 1000 0000 取反,让某一位输出低电平点亮该位二极管*/
				if(flag == 0)
				{
					P0 = ~(0x01<<count);
					count++;
					if(count==8)
					{
						count = 0;
						flag = 1;
					}
				}
				if(flag == 1)
				{
					P0 = ~(0x80>>count);
					count++;
					if(count==8)
					{
						count = 0;
						flag = 0;
					}
				}
			}
		}
	}
}