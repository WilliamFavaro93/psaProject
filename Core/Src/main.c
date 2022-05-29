/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define COMMAND_SIZE 8
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

uint8_t Command[COMMAND_SIZE];
extern uint8_t charState[];
uint8_t boh;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;

/* Definitions for StateTask */
osThreadId_t StateTaskHandle;
const osThreadAttr_t StateTask_attributes = {
  .name = "StateTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for OutTask */
osThreadId_t OutTaskHandle;
const osThreadAttr_t OutTask_attributes = {
  .name = "OutTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for ModeTask */
osThreadId_t ModeTaskHandle;
const osThreadAttr_t ModeTask_attributes = {
  .name = "ModeTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for TxValveState */
osThreadId_t TxValveStateHandle;
const osThreadAttr_t TxValveState_attributes = {
  .name = "TxValveState",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for UART_RxMxTask */
osThreadId_t UART_RxMxTaskHandle;
const osThreadAttr_t UART_RxMxTask_attributes = {
  .name = "UART_RxMxTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for ManageReceive */
osThreadId_t ManageReceiveHandle;
const osThreadAttr_t ManageReceive_attributes = {
  .name = "ManageReceive",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* USER CODE BEGIN PV */
extern QueueStruct AirFlux;
extern QueueStruct Oxygen;
extern RelayStruct Relay[];
extern PSAStruct PSA;
extern uint8_t DigitalInput;
extern uint8_t Condition;
extern uint16_t EEPRAM[][EEPRAM_INT_PER_PAGE];
extern uint32_t Modbus[];
const TickType_t deciseconds = pdMS_TO_TICKS(100);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN1_Init(void);
static void MX_CAN2_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
void StartStateTask(void *argument);
void StartOutTask(void *argument);
void StartModeTask(void *argument);
void StartCAN1_TxValveStateTask(void *argument);
void StartUART_RxMxTask(void *argument);
void StartTask06(void *argument);
/* USER CODE BEGIN PFP */
int __io_putchar(int character);
uint16_t Convert_Command_Value(uint8_t * Command, uint8_t Command_Size, uint8_t PrefixLength);
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
  MX_CAN1_Init();
  MX_CAN2_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of StateTask */
  StateTaskHandle = osThreadNew(StartStateTask, NULL, &StateTask_attributes);

  /* creation of OutTask */
  OutTaskHandle = osThreadNew(StartOutTask, NULL, &OutTask_attributes);

  /* creation of ModeTask */
  ModeTaskHandle = osThreadNew(StartModeTask, NULL, &ModeTask_attributes);

  /* creation of TxValveState */
  TxValveStateHandle = osThreadNew(StartCAN1_TxValveStateTask, NULL, &TxValveState_attributes);

  /* creation of UART_RxMxTask */
  UART_RxMxTaskHandle = osThreadNew(StartUART_RxMxTask, NULL, &UART_RxMxTask_attributes);

  /* creation of ManageReceive */
  ManageReceiveHandle = osThreadNew(StartTask06, NULL, &ManageReceive_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 16;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_1TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */

  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief CAN2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN2_Init(void)
{

  /* USER CODE BEGIN CAN2_Init 0 */

  /* USER CODE END CAN2_Init 0 */

  /* USER CODE BEGIN CAN2_Init 1 */

  /* USER CODE END CAN2_Init 1 */
  hcan2.Instance = CAN2;
  hcan2.Init.Prescaler = 16;
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_1TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan2.Init.TimeTriggeredMode = DISABLE;
  hcan2.Init.AutoBusOff = DISABLE;
  hcan2.Init.AutoWakeUp = DISABLE;
  hcan2.Init.AutoRetransmission = DISABLE;
  hcan2.Init.ReceiveFifoLocked = DISABLE;
  hcan2.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN2_Init 2 */

  /* USER CODE END CAN2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
int __io_putchar(int character)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)&character, 1, 0xFFFFFFFF);
	return character;
}

uint16_t Convert_Command_Value(uint8_t * Command, uint8_t Command_Size, uint8_t PrefixLength)
{
	uint16_t Value;
	for(uint8_t i = 0;  i < (Command_Size - PrefixLength); i++)
	{/* if it's a number */
		if(Command[PrefixLength + i] >= '0' && Command[PrefixLength + i] <= '9')
		{
			Value *= 10;
			Value += Command[PrefixLength + i] - '0';
		}
		else
			return Value;
	}
	return Value;
}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartStateTask */
/**
  * @brief  Function implementing the StateTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartStateTask */
void StartStateTask(void *argument)
{
  /* USER CODE BEGIN 5 */
	vTaskResume(StateTaskHandle);
	PSA.State = 1;
	TickType_t StateTaskDelayTimer = xTaskGetTickCount();
  /* Infinite loop */
  for(;;)
  {
	  PSA.State = State_AdsorptionCycleNStandby(PSA.State);
#ifdef DEBUG_UART_TX_STATE
		 HAL_UART_Transmit(&huart2, (uint8_t*)&charState, 2, 0xFFFFFFFF);
#endif /* DEBUG_UART_TX_STATE */
	  vTaskDelayUntil(&StateTaskDelayTimer, 20 * deciseconds);
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartOutTask */
/**
* @brief Function implementing the OutTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartOutTask */
void StartOutTask(void *argument)
{
  /* USER CODE BEGIN StartOutTask */
	vTaskResume(OutTaskHandle);
	  /* Infinite loop */
	  for(;;)
	  {
		  if(PSA.OUT_1)
		  {/* If OUT1 is controlled */
			  if(PSA.KE1_OxygenSensor_1.Value > PSA.KE1_OxygenSensor_1.UpperThreshold)
			  {/* If KE < SO2-1 -> OUT1 open*/
				  PSA.OUT_1 = 2;
				  if((PSA.B2_OutputPressure_1.Value > PSA.B2_OutputPressure_1.UpperThreshold) && (PSA.State))
				  {/*If B2 > SB2H & No Standby -> Standby */
					  PSA.State = PSA_STATE__TURN_TO_STANDBY_MODE;
				  }
			  }
			  if((PSA.B2_OutputPressure_1.Value < PSA.B2_OutputPressure_1.LowerThreshold) && (!(PSA.State)))
			  {/* If B2 < SB2L + Standby -> ADSOCycle */
				  PSA.State = PSA_STATE__TURN_TO_ADSOCYCLE_MODE;
			  }
		  }

		  if(PSA.OUT_2)
		  {/* If OUT1 is controlled */
			  if(PSA.KE2_OxygenSensor_2.Value > PSA.KE2_OxygenSensor_2.UpperThreshold)
			  {/* If KE < SO2-1 -> OUT1 open*/
				  PSA.OUT_2 = 2;
				  if((PSA.B4_OutputPressure_2.Value > PSA.B4_OutputPressure_2.UpperThreshold) && (PSA.State))
				  {/*If B4 > SB4H & No Standby -> Standby */
					  PSA.State = PSA_STATE__TURN_TO_STANDBY_MODE;
				  }

			  }
			  if((PSA.B4_OutputPressure_2.Value < PSA.B4_OutputPressure_2.LowerThreshold) && (!(PSA.State)))
			  {/* If B4 < SB4L + Standby -> ADSOCycle */
				  PSA.State = PSA_STATE__TURN_TO_ADSOCYCLE_MODE;
			  }
		  }

	    vTaskDelay(deciseconds);
	  }
  /* USER CODE END StartOutTask */
}

/* USER CODE BEGIN Header_StartModeTask */
/**
* @brief Function implementing the ModeTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartModeTask */
void StartModeTask(void *argument)
{
  /* USER CODE BEGIN StartModeTask */
  /* Infinite loop */
  for(;;)
  {
	  /* Mode_OFF -> Mode_ON */
	  if((PSA.Mode.Ready & (!PSA.Mode.Run)) && (PSA.B1_IncomingAirPressure.Value > PSA.B1_IncomingAirPressure.UpperThreshold) && ((PSA.KE1_OxygenSensor_1.LowerThreshold != 0)||(PSA.KE2_OxygenSensor_2.LowerThreshold != 0)))
	  {/* Mode_ReadyButNotRunning && (B1 > SB1H) && ((SO2-1 != OFF)||(SO2-2 != OFF)): starting condition */
		  /* USER CODE BEGIN -> ModeON */
		  vTaskResume(StateTaskHandle);
		  vTaskResume(OutTaskHandle);
		  /* USER CODE END -> ModeON */
		  if((PSA.KE1_OxygenSensor_1.LowerThreshold != 0)&&(PSA.KE2_OxygenSensor_2.LowerThreshold != 0)&&((PSA.OUTPriority == 1)||(PSA.OUTPriority == 2)))
		  {/* (SO2-1 != OFF)&&(SO2-2 != OFF) -> OUT_priority */
			  if(PSA.OUTPriority == 1)
				  PSA.OUT_1 = 1;
			  else
				  PSA.OUT_2 = 1;

		  }
		  else if(PSA.KE1_OxygenSensor_1.LowerThreshold != 0)
		  {/* (SO2-1 != OFF) -> OUT_1 else OUT_2 */
			  PSA.OUT_1 = 1;
		  }
		  else
			  PSA.OUT_2 = 1;
	  }


    vTaskDelay(deciseconds);
  }
  /* USER CODE END StartModeTask */
}

/* USER CODE BEGIN Header_StartCAN1_TxValveStateTask */
/**
* @brief Function implementing the TxValveState thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCAN1_TxValveStateTask */
void StartCAN1_TxValveStateTask(void *argument)
{
  /* USER CODE BEGIN StartCAN1_TxValveStateTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCAN1_TxValveStateTask */
}

/* USER CODE BEGIN Header_StartUART_RxMxTask */
/**
* @brief Function implementing the UART_RxMxTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartUART_RxMxTask */
void StartUART_RxMxTask(void *argument)
{
  /* USER CODE BEGIN StartUART_RxMxTask */
  /* Infinite loop */
  for(;;)
  {

	  boh = HAL_UART_Receive_DMA(&huart2, (uint8_t*)&Command, COMMAND_SIZE);
	  osDelay(100);
  }
  /* USER CODE END StartUART_RxMxTask */
}

/* USER CODE BEGIN Header_StartTask06 */
/**
* @brief Function implementing the ManageReceive thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask06 */
void StartTask06(void *argument)
{
  /* USER CODE BEGIN StartTask06 */
#ifdef	DEBUG_UART_TX_COMMAND
#endif
  /* Infinite loop */
  for(;;)
  {
	  if(Command[0] != 0)
	  { /* Check out: Analog Input */
		  if(Command[0] == 'B' && Command[1] == '1')/* B1 */
			  PSA.B1_IncomingAirPressure.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 2);
		  if(Command[0] == 'B' && Command[1] == '2')/* B2 */
			  PSA.B2_OutputPressure_1.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 2);
		  if(Command[0] == 'B' && Command[1] == '3')/* B3 */
			  PSA.B3_ProcessTankPressure.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 2);
		  if(Command[0] == 'B' && Command[1] == '4')/* B4 */
			  PSA.B4_OutputPressure_2.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 2);
		  if(Command[0] == 'F' && Command[1] == 'M')/* FM */
			  PSA.FM_NitrogenFlowmeter.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 2);
		  if(Command[0] == 'D' && Command[1] == 'W')/* DW */
			  PSA.DW_IncomingAirDewpoint.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 2);
		  if(Command[0] == 'K' && Command[1] == 'E' && Command[2] == '1')/* KE1 */
			  PSA.KE1_OxygenSensor_1.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 3);
		  if(Command[0] == 'K' && Command[1] == 'E' && Command[2] == '2')/* KE2 */
			  PSA.KE2_OxygenSensor_2.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 3);
		  /* Check out: Digital Input */
		  if(Command[0] == 'I' && Command[1] == 'N' && Command[2] == '5')/* IN5 */
			  PSA.IN5_RemoteStartOUT_2.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 3);
		  if(Command[0] == 'I' && Command[1] == 'N' && Command[2] == '6')/* IN6 */
			  PSA.IN6_RemoteStartOUT_1.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 3);
		  if(Command[0] == 'I' && Command[1] == 'N' && Command[2] == '8')/* IN8 */
			  PSA.IN8_FaultAL11_EXT.Value = Convert_Command_Value((uint8_t *)&Command, COMMAND_SIZE, 3);
		  	  }
	  /* Clear all */
	  for(int i = 0; i < COMMAND_SIZE; i++)
	  			  Command[i] = 0;
	  vTaskDelay(100);
  }
  /* USER CODE END StartTask06 */
}


/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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

