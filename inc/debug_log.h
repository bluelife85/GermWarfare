#ifndef DEBUG_LOG_H_
#define DEBUG_LOG_H_

#include "stm32f4xx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct debug_t {
	void (*initialize)(void);
	void (*putchar)(char c);
	uint8_t (*getchar)(char* dest);
	void (*puts)(char* str);
	int (*printf)(const char* str,...);
} debug_out_t;

extern const debug_out_t Debug;

#endif
