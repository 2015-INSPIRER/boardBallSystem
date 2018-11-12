#include "usart2.h"
#include "openMV.h"

spot_t spot;

//
// ����openMV��ض˿ڳ�ʼ��
//
//
void openMVPortInit(void){
	USART2_Init(115200);
}

//
// ���ڴ����ж��д�����յ���openMV����
//
//
void openMVDataProess(uint8_t res){
	static uint8_t rxBuf[200];
	static int16_t rxBufCut = 0;
	uint16_t vas = 0;
	uint16_t i = 0;
	// R Ϊ��ʼ��־
	if(res == 'R'){
		rxBufCut = 0;
	}
	if(rxBufCut > 199){
		rxBufCut = -1;
	}
	// ��ֵ��������
	if(rxBufCut >= 0){
		rxBuf[rxBufCut ++] = res;
	}
	
	if(rxBuf[0] == 'R' && res == 'O'){
		// �յ�һ֡���ݿ�ʼ����
		if(rxBuf[1] == '('){
			i = 0;
			while(rxBuf[2 + i] != ','){
				vas = (rxBuf[2 + i] - '0') + vas * 10;
				i ++;
			}
			spot.x = vas;
			vas = 0;
			while(rxBuf[4 + i] != ')'){
				vas = (rxBuf[4 + i] - '0') + vas * 10;
				i ++;
			}
			spot.y = vas;
			vas = 0;
		}
	}
	
}

//
// ��ȡλ������
//
void getCoordinate(void){
	
}


