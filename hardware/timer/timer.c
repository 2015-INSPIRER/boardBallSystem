#include <stdint.h>
#include <stdbool.h>

#include "timer.h"

static u8 time_10MsFlag = 0;
static u8 time100MsFlag = 0;
static u8 time30MsFlag	= 0;
static u8 time100MsCut	= 0;
static uint64_t	timeCut	= 0;
static uint8_t	time30MsCut = 0; 

static bool timeSFlag = 0;
static uint16_t timeSCut = 0;

void TIM2_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��
	
	//��ʱ��TIM2��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM2�ж�,��������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���


	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIMx					 
}
//��ʱ��3�жϷ������
void TIM2_IRQHandler(void)   //TIM2�ж�
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //���TIM2�����жϷ������
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update );  //���TIMx�����жϱ�־ 
		time_10MsFlag = 1;
		time100MsCut ++;
		timeSCut ++;
		time30MsCut ++;
		if(time100MsCut == 10){
			time100MsCut = 0;
			time100MsFlag = 1;
		}
		if(timeSCut == 100){
			timeSCut = 0;
			timeSFlag = 1;
		}
		if(time30MsCut >= 3){
			time30MsCut = 0;
			time30MsFlag = 1;
		}
		timeCut ++;
	}
}
//
// 10ms��־
//
u8 getTime10MsFlag(void)
{
	if(time_10MsFlag == 1)
	{
		time_10MsFlag = 0;
		return  1;
	}
	else return 0;
}
//
// 100ms��־
//
u8 getTime100MsFlag(void){
	if(time100MsFlag == 1){
		time100MsFlag = 0;
		return 1;
	}
	else return 0;
}
//
// 1S �ı�־
//
//
bool getTime1SFlag(void){
	if(timeSFlag == 1){
		timeSFlag = 0;
		return true;
	}
	else return false;
}

//
// 30ms ��־
//
//
bool getTime30MsFlag(void){
	if(time30MsFlag == 1){
		time30MsFlag = 0;
		return true;
	}
	else return false;
}
//
// ����ϵͳ����ʱ��
// ��λ 1us
//
uint64_t getTime(void){
	uint64_t temp = 0;
	temp = timeCut * 10000 + TIM_GetCounter(TIM2); 
	return temp;
}










