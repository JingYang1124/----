#include "delay.h"
#include "sys.h"
#include "24l01.h" 	 
#include "Key.h"

extern void LD3320_main(void);
extern void LD3320_Init(void); 

	u16 t=0;	
	u8 tmp_buf[33];		
	u8  Send_State;
 int main(void)
 {	
	delay_init();	    	 //��ʱ������ʼ��	 			
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
 	NRF24L01_Init();     //��ʼ��NRF24L01 
	LD3320_Init();	     //��ʼ��LD3320
	KEY_Init();	


	NRF24L01_TX_Mode(); //����NRF24L01Ϊ����ģʽ
  
	for(t=0;t<32;t++)//��ʼ��NRF24L01������Ϣ
	{
			tmp_buf[t]='A';	
	}	 
	tmp_buf[32]=0;//���������		
	
	while (1)
  {
		LD3320_main();	
		KEY_Scan();		
		Send_State = NRF24L01_TxPacket(tmp_buf);		
	}
	 
}


