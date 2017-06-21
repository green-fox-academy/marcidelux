#include "main.h"
#include <math.h>

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	int32_t x;
	int32_t y;
} coordinate_t;

/* Private define ------------------------------------------------------------*/
#define R 20
#define R_C 3 // radius of the clearing  range
#define RANGE_MAX 4

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
USBD_HandleTypeDef USBD_Device;
uint8_t HID_Buffer[4];

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void CPU_CACHE_Enable(void);
void system_lcd_init();
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
	/* Enable the CPU Cache */

	CPU_CACHE_Enable();

	/* STM32F7xx HAL library initialization:
	 - Configure the Flash ART accelerator on ITCM interface
	 - Configure the Systick to generate an interrupt each 1 msec
	 - Set NVIC Group Priority to 4
	 - Low Level Initialization
	 */
	HAL_Init();

	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();

	/* Configure LED1 */
	BSP_LED_Init(LED1);

	/* Init Device Library */
	USBD_Init(&USBD_Device, &HID_Desc, 0);

	/* Add Supported Class */
	USBD_RegisterClass(&USBD_Device, USBD_HID_CLASS);

	/* Start Device Process */
	USBD_Start(&USBD_Device);


	system_lcd_init();


	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
	system_lcd_init();

	TS_StateTypeDef status_of_ts;

	uint32_t lcd_width = BSP_LCD_GetXSize();
	uint32_t lcd_height = BSP_LCD_GetYSize();
	uint8_t touch_happend_flag = 0;
	uint8_t maybe_click_flag = 0;
	uint8_t clear_circle_flag = 0;
	uint8_t range;
	uint8_t range_circle;

	coordinate_t begin_cord = {0,0};
	coordinate_t prev_cord = {0,0};
	coordinate_t now_cord = {0,0};
	coordinate_t begin_circle_cord = {0,0};

	uint32_t tick_time_up;
	uint32_t tick_time_down;
	uint32_t tick_time_diference;

	while (1) {

		BSP_TS_GetState(&status_of_ts);

		HID_Buffer[1] = 0;
		HID_Buffer[2] = 0;

		if (status_of_ts.touchDetected) {

			now_cord.x = status_of_ts.touchX[0];
			now_cord.y = status_of_ts.touchY[0];

			if (!touch_happend_flag) {
				touch_happend_flag = 1;
				maybe_click_flag = 1;

				tick_time_down = HAL_GetTick();
				begin_cord.x = now_cord.x;
				begin_cord.y = now_cord.y;

				if (tick_time_down > tick_time_up  && (tick_time_down - tick_time_up) <= 150) {
					HID_Buffer[0] = 0b001;
				}

			} else {
				HID_Buffer[1] = 3 * (now_cord.x - prev_cord.x);
				HID_Buffer[2] = 3 * (now_cord.y - prev_cord.y);
			}

			if (!clear_circle_flag) {
				clear_circle_flag = 1;
				begin_circle_cord.x = now_cord.x;
				begin_circle_cord.y = now_cord.y;
			}

			prev_cord.x = now_cord.x;
			prev_cord.y = now_cord.y;

			range_circle = sqrt(((now_cord.x - begin_circle_cord.x)^2) + ((now_cord.y - begin_circle_cord.y)^2));
			range = sqrt(((now_cord.x - begin_cord.x)^2) + ((now_cord.y - begin_cord.y)^2));

			if (range > RANGE_MAX) {
				maybe_click_flag = 0;
			}

			USBD_HID_SendReport(&USBD_Device, HID_Buffer, 4);

			if ((now_cord.x + R) < lcd_width && (now_cord.x - R) > 0 && (now_cord.y + R) < lcd_height && (now_cord.y - R) > 0) {
				BSP_LCD_FillCircle(now_cord.x, now_cord.y, R);
			}

			if (range_circle > R_C) {
				BSP_LCD_Clear(LCD_COLOR_DARKYELLOW);
				clear_circle_flag = 0;
				begin_circle_cord.x = 0;
				begin_circle_cord.y = 0;
			}


		} else {
			if (maybe_click_flag) {
				tick_time_up = HAL_GetTick();
				HAL_Delay(10);
				HID_Buffer[0] = 0b001;
				USBD_HID_SendReport(&USBD_Device, HID_Buffer, 4);
				HAL_Delay(10);
				HID_Buffer[0] = 0;
				USBD_HID_SendReport(&USBD_Device, HID_Buffer, 4);
			}

			BSP_LCD_Clear(LCD_COLOR_DARKYELLOW);
			HID_Buffer[0] = 0;
			prev_cord.x = 0;
			prev_cord.y = 0;
			now_cord.x = 0;
			now_cord.y = 0;
			begin_cord.x = 0;
			begin_cord.y = 0;
			begin_circle_cord.x = 0;
			begin_circle_cord.y = 0;

			touch_happend_flag = 0;
			maybe_click_flag = 0;
			clear_circle_flag = 0;

		}
	}
}

/**
 * @brief This function provides accurate delay (in milliseconds) based
 *        on SysTick counter flag.
 * @note This function is declared as __weak to be overwritten in case of other
 *       implementations in user file.
 * @param Delay: specifies the delay time length, in milliseconds.
 * @retval None
 */

void HAL_Delay(__IO uint32_t Delay) {
	while (Delay) {
		if (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) {
			Delay--;
		}
	}
}

void system_lcd_init()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
	BSP_LCD_DisplayOn();
	BSP_LCD_Clear(LCD_COLOR_DARKYELLOW);
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 216000000
 *            HCLK(Hz)                       = 216000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 25
 *            PLL_N                          = 432
 *            PLL_P                          = 2
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 7
 * @param  None
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 432;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* Activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
	RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}


/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void) {
	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif
