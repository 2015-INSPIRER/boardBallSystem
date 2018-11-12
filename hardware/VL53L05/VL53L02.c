#include "VL53L02.h"
#include "myiic2.h"


#define VL53L0X_REG_IDENTIFICATION_MODEL_ID         0xc0
#define VL53L0X_REG_IDENTIFICATION_REVISION_ID      0xc2
#define VL53L0X_REG_PRE_RANGE_CONFIG_VCSEL_PERIOD   0x50
#define VL53L0X_REG_FINAL_RANGE_CONFIG_VCSEL_PERIOD 0x70
#define VL53L0X_REG_SYSRANGE_START                  0x00
#define VL53L0X_REG_RESULT_INTERRUPT_STATUS         0x13
#define VL53L0X_REG_RESULT_RANGE_STATUS             0x14
#define VL53L0X_Add 0x29


//IIC����д
//addr:������ַ 
//reg:�Ĵ�����ַ
//len:д�볤��
//buf:������
//����ֵ:0,����
//    ����,�������
u8 VL53L02X_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{
	u8 i; 
  IIC2_Start(); 
	IIC2_Send_Byte((addr<<1)|0);//����������ַ+д����	
	if(IIC2_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC2_Stop();		 
		return 1;		
	}
    IIC2_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC2_Wait_Ack();		//�ȴ�Ӧ��
	for(i=0;i<len;i++)
	{
		IIC2_Send_Byte(buf[i]);	//��������
		if(IIC2_Wait_Ack())		//�ȴ�ACK
		{
			IIC2_Stop();	 
			return 1;		 
		}		
	}    
    IIC2_Stop();	 
	return 0;	
} 
//IIC������
//addr:������ַ
//reg:Ҫ��ȡ�ļĴ�����ַ
//len:Ҫ��ȡ�ĳ���
//buf:��ȡ�������ݴ洢��
//����ֵ:0,����
//    ����,�������
u8 VL53L02X_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{ 
 	IIC2_Start(); 
	IIC2_Send_Byte((addr<<1)|0);//����������ַ+д����	
	if(IIC2_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC2_Stop();		 
		return 1;		
	}
    IIC2_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC2_Wait_Ack();		//�ȴ�Ӧ��
    IIC2_Start();
	  IIC2_Send_Byte((addr<<1)|1);//����������ַ+������	
    IIC2_Wait_Ack();		//�ȴ�Ӧ�� 
	while(len)
	{
		if(len==1)
			*buf=IIC2_Read_Byte(0);//������,����nACK 
		else 
			*buf=IIC2_Read_Byte(1);		//������,����ACK 
		len--;
		buf++; 
	}    
    IIC2_Stop();	//����һ��ֹͣ���� 
	return 0;	
}
//IICдһ���ֽ� 
//reg:�Ĵ�����ַ
//data:����
//����ֵ:0,����
//    ����,�������
u8 VL53L02X_Write_Byte(u8 reg,u8 data) 				 
{ 
  IIC2_Start(); 
	IIC2_Send_Byte((VL53L0X_Add<<1)|0);//����������ַ+д����	
	if(IIC2_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC2_Stop();		 
		return 1;		
	}
  IIC2_Send_Byte(reg);	//д�Ĵ�����ַ
  IIC2_Wait_Ack();		//�ȴ�Ӧ�� 
	IIC2_Send_Byte(data);//��������
	if(IIC2_Wait_Ack())	//�ȴ�ACK
	{
		IIC2_Stop();	 
		return 1;		 
	}	 
  IIC2_Stop();	 
	return 0;
}
//IIC��һ���ֽ� 
//reg:�Ĵ�����ַ 
//����ֵ:����������
u8 VL53L02X_Read_Byte(u8 reg)
{
	u8 res;
  IIC2_Start(); 
	//IIC_Send_Byte((VL53L0X_Add<<1)|0);//����������ַ+д����	
	IIC2_Send_Byte(0x52);//����������ַ+д����	
	IIC2_Wait_Ack();		//�ȴ�Ӧ�� 
  IIC2_Send_Byte(reg);	//д�Ĵ�����ַ
  IIC2_Wait_Ack();		//�ȴ�Ӧ��
  IIC2_Start();
	IIC2_Send_Byte(0x53 );//����������ַ+������	
  IIC2_Wait_Ack();		//�ȴ�Ӧ�� 
	res=IIC2_Read_Byte(0);//��ȡ����,����nACK 
  IIC2_Stop();			//����һ��ֹͣ���� 
	return res;		
}







