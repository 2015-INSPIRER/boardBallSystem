#include "pwmOutput.h"


void tim3PwmInit(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;


	/* ����TIM3CLK Ϊ 72MHZ */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 

	/* GPIOA and GPIOB clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE); 

	/*GPIOA Configuration: TIM3 channel 1 and 2 as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // �����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = TIM_PERIOD;       //����ʱ����0������999����Ϊ1000�Σ�Ϊһ����ʱ����
	TIM_TimeBaseStructure.TIM_Prescaler = 8;	    //����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ72MHz
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	//����ʱ�ӷ�Ƶϵ��������Ƶ(�����ò���)
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* PWM1 Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
	TIM_OCInitStructure.TIM_Pulse = 0;	   				//��������ֵ�������������������ֵʱ����ƽ��������
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);	 //ʹ��ͨ��1
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM3, ENABLE);			 // ʹ��TIM3���ؼĴ���ARR

	/* TIM3 enable counter */
	TIM_Cmd(TIM3, ENABLE);                   //ʹ�ܶ�ʱ��3	
}

//
// �ı�ռ�ձ� 
// �ٷֱȱ�ʾ 0 - 999
//
void tim3PwmSetDutyCycle(uint16_t percent, uint8_t channel){
	uint16_t compare = 0;
	compare = percent * PERCENT_TO_CONPARE;
	switch(channel){
		case 1:
			TIM_SetCompare1(TIM3, compare);
			break;
		case 2:
			TIM_SetCompare2(TIM3, compare);
			break;
	}
}

//
// ��ʱ��1��PWM��ʼ��
//
//
void tim5PwmInit(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;


	/* ����TIM5CLK Ϊ 72MHZ */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE); 

	/* GPIOA and GPIOB clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE); 

	/*GPIOA Configuration: TIM5 channel 1 and 2 as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // �����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = TIM_PERIOD;       //����ʱ����0������999����Ϊ1000�Σ�Ϊһ����ʱ����
	TIM_TimeBaseStructure.TIM_Prescaler = 8;	    //����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ72MHz
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	//����ʱ�ӷ�Ƶϵ��������Ƶ(�����ò���)
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

	/* PWM1 Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
	TIM_OCInitStructure.TIM_Pulse = 0;	   				//��������ֵ�������������������ֵʱ����ƽ��������
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ
	
	TIM_OC1Init(TIM5, &TIM_OCInitStructure);	 //ʹ��ͨ��1
	TIM_OC2Init(TIM5, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM5, ENABLE);			 // ʹ��TIM5���ؼĴ���ARR

	/* TIM5 enable counter */
	TIM_Cmd(TIM5, ENABLE);                   //ʹ�ܶ�ʱ��3	
}

//
// �ı�ռ�ձ� 
// �ٷֱȱ�ʾ 0 - 1000
//
void tim5PwmSetDutyCycle(uint16_t percent, uint8_t channel){
	uint16_t compare = 0;
	compare = percent * PERCENT_TO_CONPARE;
	switch(channel){
		case 1:
			TIM_SetCompare1(TIM5, compare);
			break;
		case 2:
			TIM_SetCompare2(TIM5, compare);
			break;
	}
}


/*********************************************END OF FILE**********************/
