#ifndef __LCD_MATRIX_H
#define __LCD_MATRIX_H

#include "stm32f7xx_hal.h"
#include "cmsis_os.h"

#define LCD_MATRIX_COLS		8
#define LCD_MATRIX_ROWS		12

/* Exported typedef -----------------------------------------------------------*/
typedef struct {
	uint16_t A;
	uint16_t B;
	uint8_t ON;
} LCD_POINT;

/* Exported variables ---------------------------------------------------------*/
LCD_POINT lcd_points[LCD_MATRIX_ROWS][LCD_MATRIX_COLS];

// Mutex global variable
osMutexId led_matrix_mutex_id;

/* Exported functions ------------------------------------------------------- */
void dot_print (LCD_POINT point, uint8_t turn_on);
void screen_startup();
void screen_for_led_matrix_thread(void const *argument);
void touch_screen_thread(void const *argument);

#endif /* __LCD_MATRIX_H */
