#ifndef _VL53L03_H
#define _VL53L03_H

#include "sys.h"

u8 VL53L03X_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf);//����д
u8 VL53L03X_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf);//������
u8 VL53L03X_Write_Byte(u8 reg,u8 data);//дһ���ֽ�
u8 VL53L03X_Read_Byte(u8 reg);//��һ���ֽ�

#endif

