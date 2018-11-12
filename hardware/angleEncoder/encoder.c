#include "encoder.h"
#include "delay.h"

uint16_t m_iPrvSSI;
uint16_t iSSI = 0;
uint16_t inc_data;	   //ÿˢ��һ�ε�����ֵ

void encoder_gpio(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO,ENABLE);
												
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;       
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	 // ��������
	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13); 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; //| GPIO_Pin_2 | GPIO_Pin_3;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void getdata(void)   //����ʱ���ȡ����������
{	
	char bCrc = 0,uState=0;
	int a,ix,iSSI = 0,ire = 0;
	ENCOLD_CS = 0;
	delay_us(4);
	ENCOLD_CLK = 0;
	delay_us(4);
	ENCOLD_CLK = 1;
	delay_us(4);
	
	for(a=0;a<10;a++)
	{
		ENCOLD_CLK = 0;
		iSSI<<=1;
		if(ENCOLD_DATA)
		{
			iSSI|=1;
			bCrc=!bCrc;
		}
		ENCOLD_CLK = 1;
		delay_us(4);
    }
	 delay_us(8);
	 for(ix = 0; ix < 5;ix++)//��5��״̬λ��־!
	 {
	 	ENCOLD_CLK = 0;
		uState <<= 1; //����λ������״̬λ
		if(ENCOLD_DATA)
		{
			bCrc = !bCrc;//��λ�С�1���ĸ�����������ż��������У��
 			uState |= 1;//���ݵ���1��1
		}
		ENCOLD_CLK = 1;
		delay_us(4);
	 }
	 delay_us(8);
	
	 
	 if(ENCOLD_DATA == bCrc)//���һλУ��һ��,Ҫ����żͨ����,����ΪCRC���� ,�͵������Ч				
	 {	
	 	ENCOLD_CS = 1;//ʹ��CSN�ø�,Ϊ�´�׼��
	 	if((uState == 16)||(uState == 19))//;///&&(uState == uPrvState))	//16=10000;19=10011  ��ʾ״̬λ(5λuState) ���������Ϊ��������
		{
			if((iSSI < 256)&&(m_iPrvSSI > 768))	//                                      	iSSI(0-1023)����ζ���������   	m_iPrvSSI(0-1023)��һ�ζ���������
			{
				ire = iSSI - m_iPrvSSI + 1024;	//     ��һ�����
			}
			else if((m_iPrvSSI < 256)&&(iSSI > 768)) 
			{
				ire = iSSI - m_iPrvSSI - 1024;	//     �ڶ������
			}
			else
			{
				ire = iSSI - m_iPrvSSI;//		       ���������	  �����ݼ�ȥ������
			}
			m_iPrvSSI = iSSI;//	ˢ������,�������滻������ ,Ϊ��һ������׼��
			inc_data=ire;    
		}
   	}
	ENCOLD_CS = 1;//ʹ��CSN�ø�,Ϊ�´�׼��
}


uint16_t getEncoldData(void){
	getdata();
	return m_iPrvSSI;
}



