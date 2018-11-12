#ifndef __MYIIC3_H
#define __MYIIC3_H
#include "sys.h" 

   	   		   
//IO????
#define SDA3_IN()  {GPIOD->CRH&=0XFFFF0FFF;GPIOD->CRH|=8<<12;}
#define SDA3_OUT() {GPIOD->CRH&=0XFFFF0FFF;GPIOD->CRH|=3<<12;}

//IO????	 
#define IIC3_SCL    PDout(10) //SCL
#define IIC3_SDA    PDout(11) //SDA	 
#define READ3_SDA   PDin(11)  //??SDA 

//IIC���в�������
void IIC3_Init(void);                //��ʼ��IIC��IO��				 
void IIC3_Start(void);				//����IIC��ʼ�ź�
void IIC3_Stop(void);	  			//����IICֹͣ�ź�
void IIC3_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC3_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC3_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC3_Ack(void);					//IIC����ACK�ź�
void IIC3_NAck(void);				//IIC������ACK�ź�

void IIC3_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC3_Read_One_Byte(u8 daddr,u8 addr);	  
#endif
















