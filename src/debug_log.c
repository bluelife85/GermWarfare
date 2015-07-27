#include "debug_log.h"

static char console_ring[256];
static uint32_t console_write_index;
static uint32_t console_read_index;

void debug_initialize(void){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
	USART_Init(USART1,&USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	USART_Cmd(USART1,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);
}

int fputc(int ch, FILE *f){
	
	USART1->DR = ch;
	
	while((USART1->SR & USART_FLAG_TXE) == 0x00);
	
	return ch;
}

uint8_t debug_getchar(char* dest){
	
	if(console_write_index == console_read_index)
		return 0;
	
	*dest = console_ring[console_read_index];
	
	if(console_read_index == 256)
		console_read_index = 0;
	else
		console_read_index++;
	
	return 1;
}

void debug_putchar(char ch){
	
	USART1->DR = ch;
	
	while((USART1->SR & USART_FLAG_TXE) == 0x00);
}

void debug_puts(char* str){
	
	while(*str){
		USART1->DR = *str++;;
		
		while((USART1->SR & USART_FLAG_TXE) == 0x00);
	}
	
	USART1->DR = 0x0d;
	
	while((USART1->SR & USART_FLAG_TXE) == 0x00);
	
	USART1->DR = 0x0a;
	
	while((USART1->SR & USART_FLAG_TXE) == 0x00);
}

void USART1_IRQHandler(void){
	
	char data = USART1->DR;
	
	console_ring[console_write_index++] = data;
	
	if(console_write_index == 256){
		console_write_index = 0;
	}
}

const debug_out_t Debug = {
	debug_initialize,
	debug_putchar,
	debug_getchar,
	debug_puts,
	printf
};
