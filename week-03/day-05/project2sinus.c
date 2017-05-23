
int main(void)
{
	SystemInit();

	MCP4821_Data_t DAC_data;
	DAC_data.start_zero = 0;
	DAC_data.dont_care = 0;
	DAC_data.gain = 0;
	DAC_data.shutdown = 1;
	DAC_data.data = 0x000;	

	float x = 0;
	float y;
	uint16_t adc_data;
	uint16_t data_to_DAC;
				
	while(1){
		while( x < 6.28 ){
			y = 2 * sin(x)+2;
			data_to_DAC = (uint16_t) (y*1000);
			DAC_data.data = data_to_DAC;
			MCP4821_SendData(&DAC_data);
			
			adc_data = ADC_Read();
			UART_SendCharacter(adc_data >> 2);
			x+=0.01;
		}
		x = 0;
	}
}