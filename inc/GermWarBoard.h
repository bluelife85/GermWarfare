#ifndef GERM_WAR_BOARD_H_
#define GERM_WAR_BOARD_H_

#include "lcd.h"

#define BOARD_VERTICAL_START 58
#define BOARD_HORIZONTAL_START 24

void DrawGameBoard(void);
void DrawGerm(uint16_t x,uint16_t y);
void DrawPill(uint16_t x, uint16_t y);
void ClearOneCell(uint16_t x, uint16_t y);

#endif
