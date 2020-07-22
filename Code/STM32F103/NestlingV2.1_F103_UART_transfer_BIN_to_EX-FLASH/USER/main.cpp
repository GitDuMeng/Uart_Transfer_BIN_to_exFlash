
#include "main.h"
#include "../BSP/delay/delay.h"
#include "../BSP/usart/usart.h"
#include "../BSP/TIM/myTIM.h"
#include "../BSP/LED/LED.h"
#include "../bsp/transfer_BIN_to_EX_FLASH/transfer_BIN_to_EX_FLASH.h"
#include "../bsp/w25qxx/w25qxx.h" 
#include <stdio.h>

//���±�ʾ��ַΪW25QXX�ĵ�һ������ĵ�0������
#define W25QXX_STORAGE_Block	1
#define W25QXX_STORAGE_Sector	0
u32 W25QXX_StorageAddress = W25QXX_STORAGE_Block * 4 * 1024 * 16 + 4 * 1024 * W25QXX_STORAGE_Sector;	//Ҫ��¼�ľ����ַ
u32 mybytesStored = 0;	//�Ѿ�������ֽ�
u8 buf[72];
int main()
{

	SystemInit();	//����ʱ�ӳ�ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//4λ��ռ���ȼ�
	DelayInit();	//��ʱ������ʼ��
	LED_init();
	//usart1_init(115200);
	usart1_init(230400);
	TIM2_Int_Init(10 - 1, 7200 - 1); //1MS
	W25QXX_Init();
	std::printf("NestlingV2.1_Demo\r\n");
	
	
//	std::printf("FLASH ID:%X\r\n", W25QXX_ReadID());
//	for(u8 j = 0; j < 200; j++)
//	{
//	
//		std::printf("-----[%d]-----: \r\n", j);
//		W25QXX_Read(buf, W25QXX_StorageAddress + 5827 * 72 + mybytesStored, 72);
//		mybytesStored += 72;
//		for(u8 i = 0; i < 72; i++){
//			std::printf("%02X ", buf[i]);
//		}
//		std::printf("\r\n");
//	}


	while(1){
		TBEF_mainFun();
		
		
	}
	return 0;
}



