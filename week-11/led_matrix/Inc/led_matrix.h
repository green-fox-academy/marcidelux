/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LED_MATRIX_H
#define __LED_MATRIX_H

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "lcd_matrix.h"

/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/
#define LED_MATRIX_COLS     LCD_MATRIX_COLS
#define LED_MATRIX_ROWS		LCD_MATRIX_ROWS

typedef struct {
	uint8_t board_pin;
	GPIO_TypeDef *gpio_port;
	uint32_t gpio_pin;
	uint32_t gpio_mode;
}PIN_GPIO;

/* Exported variables --------------------------------------------------------*/
PIN_GPIO LED_PIN_COLUMNS[LED_MATRIX_COLS];
PIN_GPIO LED_PIN_ROWS[LED_MATRIX_ROWS];

GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];


/* Exported functions ------------------------------------------------------- */
void led_matrix_update_thread(void const *argument);
void led_matrix_waterfall_thread(void const *argument);

void load_led_pin_columns(void);
void load_led_pin_rows(void);
void init_d_pin_columns();
void init_d_pin_rows();
void init_matrix_pins();

void pin_high(PIN_GPIO *gpio_array, uint8_t pin_number);
void pin_low(PIN_GPIO *gpio_array, uint8_t pin_number);


#endif /* __LED_MATRIX_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
