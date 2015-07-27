#include "GermWarBoard.h"

uint8_t DashBoard[5][5];

void DrawGameBoard(void){
	
	uint16_t interval = 0;
	uint32_t i;
	
	for(i=0;i<6;i++){
		
		LCD.horizontal_line(BOARD_VERTICAL_START,BOARD_HORIZONTAL_START+interval,200,GREEN);
		LCD.vertical_line(BOARD_VERTICAL_START + interval,BOARD_HORIZONTAL_START,200,GREEN);
		interval += 40;
	}
}

void ClearOneCell(uint16_t x, uint16_t y){
	
	LCD.rectangle((BOARD_VERTICAL_START + (x * 40) + 1),(BOARD_HORIZONTAL_START + (y * 40) + 1), 38, 38, BLACK, 1);
}

void DrawGerm(uint16_t x,uint16_t y){
	
	uint16_t vertical_center = (BOARD_VERTICAL_START + ((x + 1) * 40)) - 20;
	uint16_t horizontal_center = (BOARD_HORIZONTAL_START + ((y + 1) * 40)) - 20;
	uint16_t circle_top = (horizontal_center - 5);
	
	// draw body
	LCD.circle(vertical_center,(horizontal_center-4),5,RED,1);
	LCD.circle(vertical_center,(horizontal_center+4),5,RED,1);
	
	// draw left feeler
	LCD.point((vertical_center-3),(circle_top-5),GREEN);
	LCD.point((vertical_center-3),(circle_top-6),GREEN);
	LCD.point((vertical_center-3),(circle_top-7),GREEN);
	LCD.point((vertical_center-4),(circle_top-8),GREEN);
	LCD.point((vertical_center-4),(circle_top-9),GREEN);
	LCD.point((vertical_center-5),(circle_top-9),GREEN);
	LCD.point((vertical_center-5),(circle_top-8),GREEN);
	LCD.point((vertical_center-6),(circle_top-8),GREEN);
	LCD.point((vertical_center-7),(circle_top-7),GREEN);
	LCD.point((vertical_center-8),(circle_top-6),GREEN);
	LCD.point((vertical_center-9),(circle_top-5),GREEN);
	LCD.point((vertical_center-9),(circle_top-4),GREEN);
	LCD.point((vertical_center-9),(circle_top-3),GREEN);
	LCD.point((vertical_center-9),(circle_top-2),GREEN);
	
	// draw right feeler
	LCD.point((vertical_center+5),(circle_top-5),GREEN);
	LCD.point((vertical_center+5),(circle_top-6),GREEN);
	LCD.point((vertical_center+5),(circle_top-7),GREEN);
	LCD.point((vertical_center+6),(circle_top-8),GREEN);
	LCD.point((vertical_center+6),(circle_top-9),GREEN);
	LCD.point((vertical_center+7),(circle_top-9),GREEN);
	LCD.point((vertical_center+7),(circle_top-8),GREEN);
	LCD.point((vertical_center+8),(circle_top-8),GREEN);
	LCD.point((vertical_center+9),(circle_top-7),GREEN);
	LCD.point((vertical_center+10),(circle_top-6),GREEN);
	LCD.point((vertical_center+11),(circle_top-5),GREEN);
	LCD.point((vertical_center+11),(circle_top-4),GREEN);
	LCD.point((vertical_center+11),(circle_top-3),GREEN);
	LCD.point((vertical_center+11),(circle_top-2),GREEN);
	
	// draw left arm
	LCD.horizontal_line((vertical_center-10),(circle_top+3),3,GREEN);
	LCD.vertical_line((vertical_center-10),(circle_top+3),3,GREEN);
	
	// draw right arm
	LCD.horizontal_line((vertical_center+5),(circle_top+3),3,GREEN);
	LCD.vertical_line((vertical_center+5+3),(circle_top+3),3,GREEN);
	
	// draw left leg
	LCD.horizontal_line((vertical_center-8),(horizontal_center+7),2,GREEN);
	LCD.vertical_line((vertical_center-8),(horizontal_center+7),6,GREEN);
	
	// draw right leg
	LCD.horizontal_line((vertical_center+5),(horizontal_center+7),2,GREEN);
	LCD.vertical_line((vertical_center+5+2),(horizontal_center+7),6,GREEN);
}

void DrawPill(uint16_t x, uint16_t y){
	
	uint16_t vertical_center = (BOARD_VERTICAL_START + ((x + 1) * 40)) - 20;
	uint16_t horizontal_center = (BOARD_HORIZONTAL_START + ((y + 1) * 40)) - 30;
	
	LCD.circle(vertical_center, horizontal_center, 5, RED, 1);
	LCD.circle(vertical_center, (horizontal_center+20), 5, BLUE, 1);
	
	LCD.rectangle((vertical_center-5),horizontal_center, 10, 10, RED, 1);
	LCD.rectangle((vertical_center-5),(horizontal_center+10), 10, 10, BLUE, 1);
}
