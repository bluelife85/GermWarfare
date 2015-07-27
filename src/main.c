#include "stm32f4xx.h"
#include "debug_log.h"
#include "lcd.h"
#include "GermWarBoard.h"

int main(void){
	
	LCD.initialize();
	
	LCD.clear(BLACK);
	
	DrawGameBoard();
	
	while(1){
	}
}
