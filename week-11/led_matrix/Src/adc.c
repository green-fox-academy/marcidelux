#include "adc.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"


/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef AdcHandle;
ADC_ChannelConfTypeDef adc_channel_config;
osPoolDef(mpool, 1, uint16_t);                    // Define memory pool
osPoolId  mpool;
osMessageQDef(MsgBox, 1, uint16_t);			   // Define message queue
//osMessageQId  MsgBox;


void adc_init()
{
	AdcHandle.Instance = ADC3;
	AdcHandle.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV4;
	AdcHandle.Init.Resolution = ADC_RESOLUTION_12B;
	AdcHandle.Init.ContinuousConvMode = DISABLE;

	adc_channel_config.Channel = ADC_CHANNEL_0;
	adc_channel_config.Rank = 1;
	adc_channel_config.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	//adc_channel_config.Offset = 0;

	HAL_ADC_Init(&AdcHandle);
	HAL_ADC_ConfigChannel(&AdcHandle, &adc_channel_config);
}

void led_matrix_delay_adc_thread(void const *argument)
{
	mpool = osPoolCreate(osPool(mpool));                 // create memory pool
	MsgBox = osMessageCreate(osMessageQ(MsgBox), NULL);
	uint16_t delay_value;

	while (1) {

		HAL_ADC_Start(&AdcHandle);
		HAL_ADC_PollForConversion(&AdcHandle, 100);

		delay_value = HAL_ADC_GetValue(&AdcHandle);

		HAL_ADC_Stop(&AdcHandle);

		osMessagePut(MsgBox, (uint32_t)delay_value, osWaitForever);

		//LCD_UsrLog("%u\n", delay_value);
		osDelay(100);
	}
}
