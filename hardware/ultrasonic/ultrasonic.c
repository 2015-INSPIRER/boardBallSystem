#include "stdbool.h"
#include "delay.h"
#include "exti.h"
#include "timer5.h"
#include "ultrasonic.h"

u16 ultrasonicData[5] = {0};			// ���������� mmΪ��λ
//************************************************
// ���º�����ʹ�õ���ģ��ĳ������������Ǵ��ڶ�ֵ��
//************************************************

//
// ��������ض˿ڳ�ʼ��
//
void UTInit(void){
	// ���IO����
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;       
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	// ���ն˿�
	extiPinPD11Init();
	
	TIM5_Int_Init(10000,72); // ����Ƶ�� 1mhz 10ms���һ��
}
//
// ��������������
//
void TrigUT(void){
	GPIO_SetBits(GPIOD, GPIO_Pin_10);

	delay_us(20);

	GPIO_ResetBits(GPIOD, GPIO_Pin_10);
}

//
// �������жϴ���
// ʹ�����ж���
// ������ʾ�Ǹ�������
void UTProcess(uint8_t wat){
	static uint64_t start[5] = {0};
	uint32_t detTime[5] = {0};
	switch(wat){
		case 0:
			if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_11)){	// λ�ߵ�ƽ��ʼ
				start[0] = getTimeUs();
			} else {										// �͵�ƽ����ʱ��
				detTime[0] = getTimeUs() - start[0];		// ����ʱ���
				if(detTime[0] > 200000){
					ultrasonicData[0] = 6000; 
				} else {
					ultrasonicData[0] = (uint16_t)(detTime[0] / 5.566);
				}
			}
			break;
		case 1:
			if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2)){	// λ�ߵ�ƽ��ʼ
				start[1] = getTimeUs();
			} else {										// �͵�ƽ����ʱ��
				detTime[1] = getTimeUs() - start[1];		// ����ʱ���
				if(detTime[1] > 200000){
					ultrasonicData[0] = 6000; 
				} else {
					ultrasonicData[1] = (uint16_t)(detTime[1] / 5.566);
				}
			}
			break;
		case 2:
			if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_4)){	// λ�ߵ�ƽ��ʼ
				start[2] = getTimeUs();
			} else {										// �͵�ƽ����ʱ��
				detTime[2] = getTimeUs() - start[2];		// ����ʱ���
				if(detTime[2] > 200000){
					ultrasonicData[2] = 6000; 
				} else {
					ultrasonicData[2] = (uint16_t)(detTime[2] / 5.566);
				}
			}
			break;
		case 3:
			if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6)){	// λ�ߵ�ƽ��ʼ
				start[3] = getTimeUs();
			} else {										// �͵�ƽ����ʱ��
				detTime[3] = getTimeUs() - start[3];		// ����ʱ���
				if(detTime[3] > 200000){
					ultrasonicData[3] = 6000; 
				} else {
					ultrasonicData[3] = (uint16_t)(detTime[3] / 5.566);
				}
			}
			break;
		
		case 4:
			if(GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_9)){	// λ�ߵ�ƽ��ʼ
				start[4] = getTimeUs();
			} else {										// �͵�ƽ����ʱ��
				detTime[4] = getTimeUs() - start[4];		// ����ʱ���
				if(detTime[4] > 200000){
					ultrasonicData[4] = 6000; 
				} else {
					ultrasonicData[4] = (uint16_t)(detTime[4] / 5.566);
				}
			}
			break;
	}
	
}

