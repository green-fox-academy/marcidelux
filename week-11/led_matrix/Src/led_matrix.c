/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "adc.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

// Each LED state is stored in this 2D array
//GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS]; <-MOST

// Mutex definition
//osMutexDef(LED_MATRIX_MUTEX_DEF); <-MOST

// Mutex global variable
//osMutexId led_matrix_mutex_id; <-MOST

/* Private function prototypes -----------------------------------------------*/
void setup_led_matrix();

/* Private functions ---------------------------------------------------------*/
void print_led_matrix();

// TODO:
// Write this function!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state) {

	//LCD_UsrLog("Set started\n");
	osDelay(1);
	GPIO_PinState pin_state;

	if (state)
		pin_state = GPIO_PIN_SET;
	else
		pin_state = GPIO_PIN_RESET;

	// TODO:
	// Wait for the mutex
	osMutexWait(led_matrix_mutex_id, osWaitForever);

	//LCD_UsrLog("Mux in set holded\n");
	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!
	led_matrix_state[row][col] = pin_state;
	lcd_points[row][col].ON = pin_state;

	// TODO:
	// Release the mutex
	osMutexRelease(led_matrix_mutex_id);
	//LCD_UsrLog("Mux in set released\n");
}

// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array
	init_matrix_pins();

//	LCD_UsrLog("Pins - Initialized\n");

	setup_led_matrix();

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF


//	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality

		// Step 1:
		// Iterate through every column

		for (uint8_t col = 0; col < LED_MATRIX_COLS; col++) {
			// Step 2:
			// Wait for the mutex
			osMutexWait(led_matrix_mutex_id, osWaitForever);

			// Step 3:
			// Turn on the column
			HAL_GPIO_WritePin(LED_PIN_COLUMNS[col].gpio_port, LED_PIN_COLUMNS[col].gpio_pin, GPIO_PIN_SET);

			// Step 4:
			// Turn on the leds in that column or row
			for (uint8_t row = 0; row < LED_MATRIX_ROWS; row++) {
				HAL_GPIO_WritePin(LED_PIN_ROWS[row].gpio_port, LED_PIN_ROWS[row].gpio_pin, !led_matrix_state[row][col]);
			}

			// Step 5:
			// Release the mutex
			osMutexRelease(led_matrix_mutex_id);
			//LCD_UsrLog("\tMux released in update theread\n");
			// Step 6:
			// Delay
			osDelay(1);

			// Step 7:
			// Turn off the column
			HAL_GPIO_WritePin(LED_PIN_COLUMNS[col].gpio_port, LED_PIN_COLUMNS[col].gpio_pin, GPIO_PIN_RESET);

		}
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
	}

}

// This thread is a waterfall type animation
void led_matrix_waterfall_thread(void const *argument)
{
	uint16_t delay_get_value = 15;
	osEvent evt;

//	LCD_UsrLog("Waterfall started\n");

	while (1) {


		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
				evt = osMessageGet(MsgBox, osWaitForever);
				if (evt.status == osEventMessage) {
					delay_get_value = evt.value.v;
					delay_get_value = delay_get_value / 20 + 50;
					//LCD_UsrLog("%u\n", delay_get_value);
				}

				led_matrix_set(r, c, 1);
				osDelay(delay_get_value);
				led_matrix_set(r, c, 0);
			}
		}

	}

	while (1) {
		LCD_ErrLog("led_matrix_waterfall - terminating...\n");
		osThreadTerminate(NULL);
	}
}

void setup_led_matrix()
{
	for (uint8_t row = 0; row < LED_MATRIX_ROWS; row++) {
		for (uint8_t col = 0; col < LED_MATRIX_COLS; col++) {
			led_matrix_state[row][col] = GPIO_PIN_RESET;
		}
	}
}

void print_led_matrix()
{
	for (uint8_t row = 0; row < LED_MATRIX_ROWS; row++) {
			for (uint8_t col = 0; col < LED_MATRIX_COLS; col++) {
			LCD_UsrLog("%d",led_matrix_state[row][col]);
		}
		LCD_UsrLog("\n");
	}
}
/*
 * This Function loads the LED_PINS array.
 */
void load_led_pin_columns(void)
{
	LED_PIN_COLUMNS[0].board_pin = 0;
	LED_PIN_COLUMNS[0].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_COLUMNS[0].gpio_port = GPIOC;
	LED_PIN_COLUMNS[0].gpio_pin = GPIO_PIN_7;

	LED_PIN_COLUMNS[1].board_pin = 1;
	LED_PIN_COLUMNS[1].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_COLUMNS[1].gpio_port = GPIOC;
	LED_PIN_COLUMNS[1].gpio_pin = GPIO_PIN_6;

	LED_PIN_COLUMNS[2].board_pin = 2;
	LED_PIN_COLUMNS[2].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_COLUMNS[2].gpio_port = GPIOG;
	LED_PIN_COLUMNS[2].gpio_pin = GPIO_PIN_6;

	LED_PIN_COLUMNS[3].board_pin = 3;
	LED_PIN_COLUMNS[3].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_COLUMNS[3].gpio_port = GPIOB;
	LED_PIN_COLUMNS[3].gpio_pin = GPIO_PIN_4;

	LED_PIN_COLUMNS[4].board_pin = 4;
	LED_PIN_COLUMNS[4].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_COLUMNS[4].gpio_port = GPIOG;
	LED_PIN_COLUMNS[4].gpio_pin = GPIO_PIN_7;
}

void load_led_pin_rows(void)
{
	LED_PIN_ROWS[0].board_pin = 5;
	LED_PIN_ROWS[0].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_ROWS[0].gpio_port = GPIOI;
	LED_PIN_ROWS[0].gpio_pin = GPIO_PIN_0;

	LED_PIN_ROWS[1].board_pin = 6;
	LED_PIN_ROWS[1].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_ROWS[1].gpio_port = GPIOH;
	LED_PIN_ROWS[1].gpio_pin = GPIO_PIN_6;

	LED_PIN_ROWS[2].board_pin = 7;
	LED_PIN_ROWS[2].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_ROWS[2].gpio_port = GPIOI;
	LED_PIN_ROWS[2].gpio_pin = GPIO_PIN_3;

	LED_PIN_ROWS[3].board_pin = 8;
	LED_PIN_ROWS[3].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_ROWS[3].gpio_port = GPIOI;
	LED_PIN_ROWS[3].gpio_pin = GPIO_PIN_2;

	LED_PIN_ROWS[4].board_pin = 9;
	LED_PIN_ROWS[4].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_ROWS[4].gpio_port = GPIOA;
	LED_PIN_ROWS[4].gpio_pin = GPIO_PIN_15;

	LED_PIN_ROWS[5].board_pin = 10;
	LED_PIN_ROWS[5].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_ROWS[5].gpio_port = GPIOA;
	LED_PIN_ROWS[5].gpio_pin = GPIO_PIN_8;

	LED_PIN_ROWS[6].board_pin = 11;
	LED_PIN_ROWS[6].gpio_mode = GPIO_MODE_OUTPUT_PP;
	LED_PIN_ROWS[6].gpio_port = GPIOB;
	LED_PIN_ROWS[6].gpio_pin = GPIO_PIN_15;
}

/*
 * Inits the loaded array's pins.
 */
void init_d_pin_columns()
{
	GPIO_InitTypeDef gpio_init_structure;

	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	for (uint8_t i = 0; i < LED_MATRIX_COLS; i++) {
		gpio_init_structure.Pin = LED_PIN_COLUMNS[i].gpio_pin;
		gpio_init_structure.Mode = LED_PIN_COLUMNS[i].gpio_mode;
		gpio_init_structure.Pull = GPIO_PULLUP;
		gpio_init_structure.Speed = GPIO_SPEED_HIGH;

		HAL_GPIO_Init(LED_PIN_COLUMNS[i].gpio_port, &gpio_init_structure);

		HAL_GPIO_WritePin(LED_PIN_COLUMNS[i].gpio_port, LED_PIN_COLUMNS[i].gpio_pin, GPIO_PIN_RESET);
	}
}

void init_d_pin_rows()
{

	GPIO_InitTypeDef gpio_init_structure;

	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	for (uint8_t i = 0; i < LED_MATRIX_ROWS; i++) {
		gpio_init_structure.Pin = LED_PIN_ROWS[i].gpio_pin;
		gpio_init_structure.Mode = LED_PIN_ROWS[i].gpio_mode;
		gpio_init_structure.Pull = GPIO_PULLUP;
		gpio_init_structure.Speed = GPIO_SPEED_HIGH;

		HAL_GPIO_Init(LED_PIN_ROWS[i].gpio_port, &gpio_init_structure);

		HAL_GPIO_WritePin(LED_PIN_ROWS[i].gpio_port, LED_PIN_ROWS[i].gpio_pin, GPIO_PIN_SET);
	}
}

void init_matrix_pins()
{
	load_led_pin_columns();
	load_led_pin_rows();
	init_d_pin_columns();
	init_d_pin_rows();
}

void pin_high(PIN_GPIO *gpio_array, uint8_t pin_number)
{
	HAL_GPIO_WritePin(gpio_array[pin_number].gpio_port, gpio_array[pin_number].gpio_pin, GPIO_PIN_SET);
}

void pin_low(PIN_GPIO *gpio_array, uint8_t pin_number)
{
	HAL_GPIO_WritePin(gpio_array[pin_number].gpio_port, gpio_array[pin_number].gpio_pin, GPIO_PIN_RESET);
}




/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
