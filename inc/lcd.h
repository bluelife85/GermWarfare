#ifndef LCD_CONTROL_H_
#define LCD_CONTROL_H_

#include "stm32f4xx.h"

typedef struct lcd_t{
	void (*initialize)(void);
	void (*clear)(uint16_t bg);
	void (*point)(uint16_t x, uint16_t y, uint16_t color);
	void (*vertical_line)(uint16_t x, uint16_t y, uint16_t height, uint16_t color);
	void (*horizontal_line)(uint16_t x, uint16_t y, uint16_t width, uint16_t color);
	void (*line)(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color);
	void (*circle)(uint16_t x, uint16_t y, uint16_t rad,  uint16_t color, uint8_t fill);
	void (*rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color, uint8_t fill);
}LCD_T;

#define WHITE 0xffff
#define BLACK 0x0000

#define GREY 0xf7de
#define BLUE 0x001f
#define SKY_BLUE 0x051f
#define RED 0xf800
#define MAGENTA 0xf81f
#define GREEN 0x07e0
#define CYAN 0x7fff
#define YELLOW 0xffe0

#define RGB565CONVERT(red, green, blue) (int32_t) (((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3))

extern const LCD_T LCD;

#endif
