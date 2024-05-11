
#include "main.h"


void SystemClock_Config(void);
static void MX_GPIO_Init(void);
uint32_t selam =0;

int main(void)
{

  HAL_Init();

  SystemClock_Config();


  MX_GPIO_Init();

  while (1)
  {

  }

}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);


  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }


  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}


static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef gpıoyap = {0};
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5 | GPIO_PIN_4| GPIO_PIN_6, GPIO_PIN_RESET);
  	gpıoyap.Mode=GPIO_MODE_IT_RISING_FALLING;
  	gpıoyap.Pin=GPIO_PIN_5 | GPIO_PIN_4;
  	gpıoyap.Pull=GPIO_NOPULL;
  	gpıoyap.Speed = GPIO_SPEED_FREQ_HIGH ;
  	HAL_GPIO_Init(GPIOA, &gpıoyap);

  	HAL_NVIC_SetPriority(EXTI4_15_IRQn,0,1);
  	HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);


}


void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==GPIO_PIN_5){
	  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, GPIO_PIN_SET);
		  for(uint32_t i=0;i<100000;i++){
		 		  /* KESME içinde DELAY kullanılmaz */
		 	  };

	}
}

void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==GPIO_PIN_4){
	  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, GPIO_PIN_RESET);
		  for(uint32_t i=0;i<100000;i++){
		 		  /* KESME içinde DELAY kullanılmaz */
		 	  };

	}

}


void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
