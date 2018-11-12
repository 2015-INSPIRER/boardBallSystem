#ifndef __MYIIC4_H
#define __MYIIC4_H
#include "sys.h" 

   	   		   
//IO????
#define SDA4_IN()  {GPIOE->CRH&=0XFFFF0FFF;GPIOE->CRH|=8<<12;}
#define SDA4_OUT() {GPIOE->CRH&=0XFFFF0FFF;GPIOE->CRH|=3<<12;}

//IO????	 
#define IIC4_SCL    PEout(10) //SCL
#define IIC4_SDA    PEout(11) //SDA	 
#define READ4_SDA   PEin(11)  //??SDA 

//IIC���в�������
void IIC4_Init(void);                //��ʼ��IIC��IO��				 
void IIC4_Start(void);				//����IIC��ʼ�ź�
void IIC4_Stop(void);	  			//����IICֹͣ�ź�
void IIC4_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC4_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC4_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC4_Ack(void);					//IIC����ACK�ź�
void IIC4_NAck(void);				//IIC������ACK�ź�

void IIC4_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC4_Read_One_Byte(u8 daddr,u8 addr);	  
#endif
















