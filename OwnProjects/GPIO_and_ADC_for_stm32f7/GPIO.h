/* This driver was made by Marton Lorinczi
 *
 * How to use this driver?
 *
 * There are two gpio_pins_t arrays. stm32f7_digital_pins[] is for the digital pins, stm32f7_analog_pins[] is for analoge pins.
 * stm32f7_digital_pins[]'s first element (index : 0 ) is the D0 pin and the last element (index : 15) is the D15 pin.
 * stm32f7_analoge_pins[]'s first element (index : 0 ) is the A0 pin and the last element (index : 5) is the A5 pin.
 *
 * There are two init functions for init the analog or digital pins.
 * And there are some functions to read write etc... thoose pins.
 *
 * Example for digital pin:
 * Init:	gpio_init_digital_pin(5, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
 * Write: 	gpio_write_digital_pin(5, GPIO_PIN_SET);
 * Reset:   gpio_reset_digital_pin(5);
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H
#define __GPIO_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Exported functions ------------------------------------------------------- */

/* ########## Functions for Digital pins ########## */

/* Function name: GPIO_Set_PIN
 * Function purpose: Set PIN to output or input
 * Function input - GPIO_Pin_t *GPIO_Pin: This is the pin to be set
 * Function input - uint32_t pode: This is the mode it can be these:
 * 		GPIO_MODE_INPUT:		Input Floating Mode
 * 		GPIO_MODE_OUTPUT_PP: 	Output Push Pull Mode
 * 		GPIO_MODE_OUTPUT_OD: 	Output Open Drain Mode
 * 		GPIO_MODE_AF_PP:		Alternate Function Push Pull Mode
 *		GPIO_MODE_AF_OD:		Alternate Function Open Drain Mode
 * Function input - uint32_t pull can be:
 * 		GPIO_PULLDOWN
 * 		GPIO_PULLUP
 * 		GPIO_NOPULL
 */
void gpio_init_digital_pin(uint8_t pin_index, uint32_t mode, uint32_t pull);

/*	Function name: gpio_write_digital_pin
 * 	Function purpose: Turn on or off the digital pin
 *	Function input - uint8_t pin_index: index of the pin
 *  Function input - GPIO_PinState State: can be: GPIO_PIN_SET or GPIO_PIN_RESET
 */
void gpio_write_digital_pin(uint8_t pin_index, GPIO_PinState State);

/*	Function name: gpio_set_digital_pin
 * 	Function purpose: Turn on the digital pin
 *	Function input - uint8_t pin_index: index of the pin
 */
void gpio_set_digital_pin(uint8_t pin_index);

/*	Function name: gpio_reset_digital_pin
 * 	Function purpose: Turn off the digital pin
 *	Function input - uint8_t pin_index: index of the pin
 */
void gpio_reset_digital_pin(uint8_t pin_index);

/*	Function name: gpio_toggle_digital_pin
 * 	Function purpose: If the pin was set it turns it reset, if it was reset it turns it to set.
 *	Function input - uint8_t pin_index: index of the pin
 */
void gpio_toggle_digital_pin(uint8_t pin_index);

/*	Function name: gpio_read_digital_pin
 * 	Function purpose: Returns with the pin's value.
 *	Function input - uint8_t pin_index: index of the pin
 */
GPIO_PinState gpio_read_digital_pin(uint8_t pin_index);

/* ########## Functions for Analoge pins ########## */

/* Function name: gpio_init_analoge_pin
 * Function purpose: Init analoge input
 * function input: uint8_t pin_index - Index of the pin 0 is A0 ... 5 is A5
 */
void gpio_init_analoge_pin(uint8_t pin_index);

#endif /* __GPIO_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
