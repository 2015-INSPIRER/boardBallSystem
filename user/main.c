#include "stm32f10x.h"
#include "delay.h"
#include "sys.h" 
#include "stm32f10x_it.h"
#include "timer.h"
#include "usart.h"

#include "display.h"
#include "Control.h"

#include "moto.h"
#include "angle.h"
#include "bsp_ili9341_lcd.h"
#include "key.h" 
#include "openMV.h"

int cut = 0;
int main(void)
{	 
	SystemInit();
	delay_init();	    	 	//��ʱ������ʼ��	  
	NVIC_Configuration(); 	 	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);			//�����ô���
	TIM2_Int_Init(9999,71);		//1M�ļ���Ƶ�ʣ�10ms��һ���ж�
	
	// ��ʾ��ʼ��
	ILI9341_Init();
	ILI9341_GramScan ( 6 );
	LCD_SetFont(&Font8x16);
	LCD_SetColors(RED,BLACK);
	ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	
	
	// �Ƕȴ�������ʼ��
	initMPU();					
	motoInit();
	Key_GPIO_Config();
	openMVPortInit();
	
	
	PID_Init();
	controlDataInit();
	while(1)
	{
		// ��������
		if(getTime10MsFlag()){
			// ��ȡ����������
			getSensorData();
			// ����
			Key_button();
			// ����״̬�л�
			systemStateCtrl();
			
		}
		// ��ʾ����״̬
		if(getTime100MsFlag()){
			// ��ʾ
			displayWorkState();
			ballMoveCtrl();
		
		}
	}
}	
 
