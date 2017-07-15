#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "led_matrix.h"
#include "stm32746g_discovery_ts.h"

uint8_t radius;
uint16_t PIX_A;
uint16_t PIX_B;

/* Startup the LCD screen, it is dinamical so It will contain exactly same amount of "leds" as the real led matrix */
void screen_startup()
{
	uint16_t width = (uint16_t)BSP_LCD_GetXSize();
	uint16_t height = (uint16_t)BSP_LCD_GetYSize();

	//Calculate how big should be one "pixel"
	PIX_A =  width / LCD_MATRIX_ROWS;
	PIX_B = height / LCD_MATRIX_COLS;

	//uint8_t radius;

	// We need a circle now at the center of a pixel
	if (PIX_A < PIX_B)
		radius = PIX_A / 2;
	else
		radius = PIX_B / 2;

	// Fill the matrix with coordinates

	for (uint8_t row = 0; row < LCD_MATRIX_ROWS; row++) {
		for (uint8_t col = 0; col < LCD_MATRIX_COLS; col++) {
			lcd_points[row][col].A = row * PIX_A + PIX_A / 2;
			lcd_points[row][col].B = 272 - (col * PIX_B + radius);
			lcd_points[row][col].ON = 0;
		}
	}



	BSP_LCD_Clear(LCD_COLOR_BLACK);

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	for (uint8_t row = 0; row < LCD_MATRIX_ROWS; row++) {
		for (uint8_t col = 0; col < LCD_MATRIX_COLS; col++) {
			BSP_LCD_FillCircle(lcd_points[row][col].A, lcd_points[row][col].B, radius - 1);
		}
	}

}

void screen_for_led_matrix_thread(void const *argument) {
	screen_startup();

	while(1){

		for (uint8_t col = 0; col < LCD_MATRIX_COLS; col++) {
			for (uint8_t row = 0; row < LCD_MATRIX_ROWS; row++) {

				osMutexWait(led_matrix_mutex_id, osWaitForever);

				if (led_matrix_state[row][col] == 1) {
					BSP_LCD_SetTextColor(LCD_COLOR_RED);
					BSP_LCD_FillCircle(lcd_points[row][col].A, lcd_points[row][col].B, radius - 1);
				} else {
					BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
					BSP_LCD_FillCircle(lcd_points[row][col].A, lcd_points[row][col].B, radius - 1);
				}

				osMutexRelease(led_matrix_mutex_id);
				osDelay(1);
			} //forrow
		} //forcol
	} //while
}

void touch_screen_thread(void const *argument)
{
	screen_startup();

	TS_StateTypeDef status_of_ts;
	status_of_ts.touchDetected = 0;
	status_of_ts.touchX[0] = 0;
	status_of_ts.touchY[0] = 0;

	uint16_t A;
	uint16_t B;
	uint8_t Touched_ROW;
	uint8_t Touched_COL;
	uint8_t Touched_ROW_MEM;
	uint8_t Touched_COL_MEM;
	uint8_t Touch_Flag = 0;

	uint16_t A_MAX = LCD_MATRIX_ROWS * PIX_A - 1;
	uint16_t B_MAX = LCD_MATRIX_COLS * PIX_B - 1;

	while(1){

		BSP_TS_GetState(&status_of_ts);

		if (status_of_ts.touchDetected) {

			A = status_of_ts.touchX[0];
			B = 272 - status_of_ts.touchY[0];

			if (A > A_MAX)
				A = A_MAX;
			if (B > B_MAX)
				B = B_MAX;

			Touched_ROW = A / PIX_A;
			Touched_COL = B / PIX_B;

			if (!Touch_Flag) {

				Touch_Flag = 1; // Touch happend

				// Save the first touched row/col
				Touched_COL_MEM = Touched_COL;
				Touched_ROW_MEM = Touched_ROW;

			//	LCD_UsrLog("A: %u, B: %u Row: %u, Col: %u\n", A, B,  Touched_ROW, Touched_COL);

				if (!lcd_points[Touched_COL][Touched_ROW].ON) {
					lcd_points[Touched_COL][Touched_ROW].ON = 1;
					led_matrix_set(Touched_ROW, Touched_COL, 1);
					BSP_LCD_SetTextColor(LCD_COLOR_RED);
					BSP_LCD_FillCircle(lcd_points[Touched_ROW][Touched_COL].A, lcd_points[Touched_ROW][Touched_COL].B , radius - 1);
				} else {
					lcd_points[Touched_COL][Touched_ROW].ON = 0;
					led_matrix_set(Touched_ROW, Touched_COL, 0);
					BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
					BSP_LCD_FillCircle(lcd_points[Touched_ROW][Touched_COL].A, lcd_points[Touched_ROW][Touched_COL].B , radius - 1);
				}
			} else if (Touched_COL_MEM != Touched_COL || Touched_ROW_MEM != Touched_ROW) {
				Touch_Flag = 0;
			}
		} else {
			Touch_Flag = 0;
		}
		osDelay(10);
	}
}



void dot_print (LCD_POINT point, uint8_t turn_on)
{
	if (!point.ON && turn_on) {
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
		BSP_LCD_FillCircle(point.A, point.B , radius - 3);
	} else if (point.ON && !turn_on) {
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_FillCircle(point.A, point.B , radius - 3);
	}
}



































