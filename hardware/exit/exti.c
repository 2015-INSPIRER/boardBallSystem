#include "exti.h"
/**
  * @brief  ����Ƕ�������жϿ�����NVIC
  * @param  ��
  * @retval ��
  */
//static void NVIC_Configuration(void)
//{
//  NVIC_InitTypeDef NVIC_InitStructure;
//  
//  /* Configure one bit for preemption priority */
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
//  
//  /* �����ж�Դ */
//  NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;		// ѡ��15_10ͨ��
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
//}

 /**
  * @brief  ���� PA0 Ϊ���жϿڣ��������ж����ȼ�
  * @param  ��
  * @retval ��
  */
//void EXTI_PA11_Config(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure; 
//	
//  EXTI_InitTypeDef EXTI_InitStructure;
//	
//	/* config the extiline clock and AFIO clock */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO,ENABLE);    /*AFIOΪGPIO�˿ڵĸ��ù���   */
//												
//	/* config the NVIC */
//	NVIC_Configuration();

//	/* EXTI line gpio config*/	
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;       
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
//  GPIO_Init(GPIOA, &GPIO_InitStructure);

//	/* EXTI line mode config */
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11); 
//	
//	EXTI_InitStructure.EXTI_Line = EXTI_Line11;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½����ж�
//	
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure); 
//}

////
//// PD0 �˿��ⲿ�ж�����
////
////
//void extiPinPD0Init(void){
//	GPIO_InitTypeDef GPIO_InitStructure; 

//	EXTI_InitTypeDef EXTI_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	/* config the extiline clock and AFIO clock */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO,ENABLE);    /*AFIOΪGPIO�˿ڵĸ��ù���   */
//											
//	/* config the NVIC */
//	 /* Configure one bit for preemption priority */
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

//	/* �����ж�Դ */
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;		// ѡ��0ͨ��
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);

//	/* EXTI line gpio config*/	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;       
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
//	GPIO_Init(GPIOD, &GPIO_InitStructure);

//	/* EXTI line mode config */
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource0); 

//	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½����ж�

//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&EXTI_InitStructure); 
//}

////
//// �������˿��ж�
////
////
//void extiPinPA3Init(void){
//	GPIO_InitTypeDef GPIO_InitStructure; 

//	EXTI_InitTypeDef EXTI_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	/* config the extiline clock and AFIO clock */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO,ENABLE);    /*AFIOΪGPIO�˿ڵĸ��ù���   */
//											
//	/* config the NVIC */
//	 /* Configure one bit for preemption priority */
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

//	/* �����ж�Դ */
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;		// ѡ��0ͨ��
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);

//	/* EXTI line gpio config*/	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;       
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
//	GPIO_Init(GPIOA, &GPIO_InitStructure);

//	/* EXTI line mode config */
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource3); 

//	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; //˫����

//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&EXTI_InitStructure);	
//}

//
// PD0�˿��ж�
//
void extiPinPD0Init(void){
	GPIO_InitTypeDef GPIO_InitStructure; 

	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* config the extiline clock and AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO,ENABLE);    /*AFIOΪGPIO�˿ڵĸ��ù���   */
											
	/* config the NVIC */
	 /* Configure one bit for preemption priority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* �����ж�Դ */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;		// ѡ��0ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* EXTI line gpio config*/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;       
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* EXTI line mode config */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource0); 

	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; //˫����

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	
}

//
// PD2�˿��ж�
//
void extiPinPD2Init(void){
	GPIO_InitTypeDef GPIO_InitStructure; 

	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* config the extiline clock and AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO,ENABLE);    /*AFIOΪGPIO�˿ڵĸ��ù���   */
											
	/* config the NVIC */
	 /* Configure one bit for preemption priority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* �����ж�Դ */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;		// ѡ��0ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* EXTI line gpio config*/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;       
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* EXTI line mode config */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource2); 

	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; //˫����

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	
}

//
// PD4�˿��ж�
//
void extiPinPD4Init(void){
	GPIO_InitTypeDef GPIO_InitStructure; 

	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* config the extiline clock and AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO,ENABLE);    /*AFIOΪGPIO�˿ڵĸ��ù���   */
											
	/* config the NVIC */
	 /* Configure one bit for preemption priority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* �����ж�Դ */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;		// ѡ��0ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* EXTI line gpio config*/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;       
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* EXTI line mode config */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource4); 

	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; //˫����

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	
}

//
// PD6�˿��ж�
//
void extiPinPD6Init(void){
	GPIO_InitTypeDef GPIO_InitStructure; 

	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* config the extiline clock and AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO,ENABLE);    /*AFIOΪGPIO�˿ڵĸ��ù���   */
											
	/* config the NVIC */
	 /* Configure one bit for preemption priority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* �����ж�Դ */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;		// ѡ��0ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* EXTI line gpio config*/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;       
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* EXTI line mode config */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource6); 

	EXTI_InitStructure.EXTI_Line = EXTI_Line6;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; //˫����

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	
}

//
// PD11�˿��ж�
//
void extiPinPD11Init(void){
	GPIO_InitTypeDef GPIO_InitStructure; 

	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* config the extiline clock and AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO,ENABLE);    /*AFIOΪGPIO�˿ڵĸ��ù���   */
											
	/* config the NVIC */
	 /* Configure one bit for preemption priority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* �����ж�Դ */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;		// ѡ��0ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* EXTI line gpio config*/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;       
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* EXTI line mode config */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource11); 

	EXTI_InitStructure.EXTI_Line = EXTI_Line11;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; //˫����

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	
}

void extiPinPG9Init(void){
	GPIO_InitTypeDef GPIO_InitStructure; 

	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* config the extiline clock and AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG | RCC_APB2Periph_AFIO,ENABLE);    /*AFIOΪGPIO�˿ڵĸ��ù���   */
											
	/* config the NVIC */
	 /* Configure one bit for preemption priority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* �����ж�Դ */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;		// ѡ��0ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* EXTI line gpio config*/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;       
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
	GPIO_Init(GPIOG, &GPIO_InitStructure);

	/* EXTI line mode config */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource9); 

	EXTI_InitStructure.EXTI_Line = EXTI_Line9;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; //˫����

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	
}


/*********************************************END OF FILE**********************/


