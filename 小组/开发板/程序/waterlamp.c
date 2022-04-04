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
	/*��ʱ������*/
	TMOD = 0x01;
	TH0 = 0xB8;
	TL0 = 0x00;
	TR0 = 1;
	
	ENLED = 0;
	ADDR3 = 1;
	/*�����ܵ�ͨLEDS6*/
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;
	/*��ˮ��*/
	while(1)
	{
		/*����������ʱ����*/
		if(TF0==1)
		{
			TF0 = 0;
			TH0 = 0xB8;
			TL0 = 0x00;
			cnt++;
			/*�ڲ�������Ƶ�ַ*/
			/*���ѭ��50�ν����ڲ�*/
			/*�ڲ�ÿ�ν���1��*/
			if(cnt == 50)
			{
				cnt = 0;
				/*P0 0000 0001 �� 1000 0000 ȡ��,��ĳһλ����͵�ƽ������λ������*/
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