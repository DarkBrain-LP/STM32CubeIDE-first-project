/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define ONE_SECOND 1000
/* USER CODE END Includes */
uint16_t factorial(uint16_t n);
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
int Delay_time = 250;
int one_second_delay = 1000;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  // variables :
  GPIO_TypeDef* green_led = GPIOD;
  GPIO_TypeDef* portA = GPIOA;
  int pins_num = 4;
  int pins[] = {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};
  uint8_t pin_toggle_delay = 1000;
  int pin_speed = 4;

  GPIO_PinState btn_poussoir_state;
  int mavariable = 0;
  btn_poussoir_state = HAL_GPIO_ReadPin(portA, GPIO_PIN_0);

  int toto = 0;

  int tm = 1680000;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  //(GPIO_TypeDef*) GPIOD = GPIOD;

	  /*
	  // blink LEDs

	  if (GPIOD->ODR & 0x0000F000) // GPIOD−>ODR & 0x0000F000
	  {
		  GPIOD->BSRR |= 0xF0000000 ;
	  }
	  else
	  {
		  GPIOD->BSRR |= 0x0000F000 ;
	  }
	  HAL_Delay(Delay_time) ;
	  */

	  // Turn on the Green LED
	  /*
	  HAL_GPIO_WritePin(green_led, GPIO_PIN_12, GPIO_PIN_SET);
	  HAL_Delay(1000);
	  // turn it off
	  HAL_GPIO_WritePin(green_led, GPIO_PIN_12, GPIO_PIN_RESET);
	  HAL_Delay(1000);


	  HAL_GPIO_TogglePin(green_led, GPIO_PIN_12);
	  HAL_Delay(1000);

	  // 2

	  int t = 1000;
	  for(int i = 0; i < pins_num; i++)
	  {

		  uint16_t current_pin = ((uint16_t)pins[i]);

		  HAL_GPIO_TogglePin(green_led, current_pin);
	  }
		  HAL_Delay(pin_toggle_delay);

	  // =========== CHENILLARD ==============
	  // 3 bouton poussoir
		  GPIO_PinState btn_poussoir_state;
		  int mavariable = 0;
		  btn_poussoir_state = HAL_GPIO_ReadPin(portA, GPIO_PIN_0);
		  if(btn_poussoir_state == GPIO_PIN_SET){
			  mavariable = 1;
			  pin_toggle_delay /= pin_speed;
		  }
		  else{
			  mavariable = 0;
		  }

	  for(int i = 0; i < pins_num; i++)
	  {

		  uint16_t current_pin = ((uint16_t)pins[i]);


		  HAL_GPIO_TogglePin(green_led, current_pin);
		  HAL_Delay(pin_toggle_delay);
		  HAL_GPIO_TogglePin(green_led, current_pin);
		  HAL_Delay(pin_toggle_delay);
	  }

	  // ============== TP2 Programmation en C ==========
	  // 1
	  if(btn_poussoir_state == GPIO_PIN_SET){
		  mavariable = 1;
		  pin_toggle_delay /= pin_speed;
		  HAL_GPIO_WritePin(green_led, GPIO_PIN_14, GPIO_PIN_SET);
	  }
	  // 2
	  if(btn_poussoir_state == GPIO_PIN_SET){
		  mavariable = 1;
		  pin_toggle_delay /= pin_speed;
		  HAL_GPIO_WritePin(green_led, GPIO_PIN_14, GPIO_PIN_SET);
	  }
	  else{
		  mavariable = 0;
		  HAL_GPIO_WritePin(green_led, GPIO_PIN_14, GPIO_PIN_RESET);
	  }

	  // 3
	  btn_poussoir_state = HAL_GPIO_ReadPin(portA, GPIO_PIN_0);
	  switch(toto){

	  case 0:
		  if(btn_poussoir_state == GPIO_PIN_SET){
			  HAL_GPIO_WritePin(green_led, GPIO_PIN_12, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(green_led, GPIO_PIN_14, GPIO_PIN_SET);
		  }
		  else{
			  HAL_GPIO_WritePin(green_led, GPIO_PIN_15, GPIO_PIN_SET);
		  }
		  break;
	  case 1:
		  if(btn_poussoir_state == GPIO_PIN_SET){
			  HAL_GPIO_WritePin(green_led, GPIO_PIN_13, GPIO_PIN_SET);
		  }
		  else{
			  HAL_GPIO_WritePin(green_led, GPIO_PIN_14, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(green_led, GPIO_PIN_13, GPIO_PIN_SET);
		  }
		  break;
	  default:
		  break;
	  }
	  HAL_GPIO_WritePin(green_led, GPIO_PIN_15, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(green_led, GPIO_PIN_14, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(green_led, GPIO_PIN_13, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(green_led, GPIO_PIN_12, GPIO_PIN_RESET);

	  // Tempo
	  uint32_t max_val = 4294967294;
	  uint32_t tempo_var = 0;
	  while(tempo_var < max_val){
		  tempo_var ++;
	  }
	  //while((tempo_var++) < max_val);
	  tempo_var = 0;
	*/
	  HAL_GPIO_TogglePin(green_led, GPIO_PIN_12);
	  custom_delay(tm);
	  int res = factorial(4);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

// 2
uint16_t factorial(uint16_t n){
	// il faut que n soit choisit de sorte que son factoriel ne soit pas supérieur à 2^32
	uint16_t res = 1;
	for(int i = n; i > 1; i--){
		res = res * i;
		//res *= i;
	}
	return res;
}
// 3
// A revoir !!
void custom_delay(uint32_t max_val){
  uint32_t tempo_var = 0;
  while(tempo_var < max_val){
	  tempo_var ++;
  }
  //while((tempo_var++) < max_val);
  tempo_var = 0;
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, led_verte_Pin|led_orange_1_Pin|led_rouge_1_Pin|led_bleue_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : led_verte_Pin led_orange_1_Pin led_rouge_1_Pin led_bleue_Pin */
  GPIO_InitStruct.Pin = led_verte_Pin|led_orange_1_Pin|led_rouge_1_Pin|led_bleue_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
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
