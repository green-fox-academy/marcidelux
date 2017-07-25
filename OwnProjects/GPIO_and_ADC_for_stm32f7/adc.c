#include "adc.h"

ADC_HandleTypeDef AdcHandle;

 void adc_init(uint8_t pin_index, uint32_t resolution)
{
	// Enable clocks
	__HAL_RCC_ADC3_CLK_ENABLE();

	 //Init analoge pin
	 gpio_init_analoge_pin(pin_index);

	/*##-1- Configure the ADC peripheral #######################################*/
	AdcHandle.Instance          		 = ADC3;

	AdcHandle.Init.ClockPrescaler        = ADC_CLOCKPRESCALER_PCLK_DIV4;
	AdcHandle.Init.Resolution            = resolution;
	AdcHandle.Init.ScanConvMode          = DISABLE;
	AdcHandle.Init.ContinuousConvMode    = DISABLE;
	AdcHandle.Init.DiscontinuousConvMode = DISABLE;
	AdcHandle.Init.NbrOfDiscConversion   = 0;
	AdcHandle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
	AdcHandle.Init.NbrOfConversion       = 1;
	AdcHandle.Init.DMAContinuousRequests = DISABLE;
	AdcHandle.Init.EOCSelection          = DISABLE;

	HAL_ADC_Init(&AdcHandle);

	/*##-2- Configure ADC regular channel ######################################*/
	ADC_ChannelConfTypeDef sConfig;

	sConfig.Channel      = stm32f7_analog_pins[pin_index].ADC_channel;
	sConfig.Rank         = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	sConfig.Offset       = 0;

	HAL_ADC_ConfigChannel(&AdcHandle, &sConfig);
}

 uint32_t adc_get_voltage(){
	 HAL_ADC_Start(&AdcHandle);
	 HAL_ADC_PollForConversion(&AdcHandle, HAL_MAX_DELAY);
	 return HAL_ADC_GetValue(&AdcHandle);
 }