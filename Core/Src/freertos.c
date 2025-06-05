/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
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

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId InitHandle;
osThreadId MeasuredistHandle;
osThreadId OLEDHandle;
osThreadId MovecontrolHandle;
osThreadId LIGHT_TESTHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Init_Task(void const * argument);
void Measuredist_Task(void const * argument);
void OLED_Task(void const * argument);
void Movecontrol_Task(void const * argument);
void LIGHT_TEST_TASK(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

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
  /* definition and creation of Init */
  osThreadDef(Init, Init_Task, osPriorityRealtime, 0, 128);
  InitHandle = osThreadCreate(osThread(Init), NULL);

  /* definition and creation of Measuredist */
  osThreadDef(Measuredist, Measuredist_Task, osPriorityRealtime, 0, 128);
  MeasuredistHandle = osThreadCreate(osThread(Measuredist), NULL);

  /* definition and creation of OLED */
  osThreadDef(OLED, OLED_Task, osPriorityRealtime, 0, 128);
  OLEDHandle = osThreadCreate(osThread(OLED), NULL);

  /* definition and creation of Movecontrol */
  osThreadDef(Movecontrol, Movecontrol_Task, osPriorityRealtime, 0, 128);
  MovecontrolHandle = osThreadCreate(osThread(Movecontrol), NULL);

  /* definition and creation of LIGHT_TEST */
  osThreadDef(LIGHT_TEST, LIGHT_TEST_TASK, osPriorityRealtime, 0, 128);
  LIGHT_TESTHandle = osThreadCreate(osThread(LIGHT_TEST), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_Init_Task */
/**
  * @brief  Function implementing the Init thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Init_Task */
__weak void Init_Task(void const * argument)
{
  /* USER CODE BEGIN Init_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Init_Task */
}

/* USER CODE BEGIN Header_Measuredist_Task */
/**
* @brief Function implementing the Measuredist thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Measuredist_Task */
__weak void Measuredist_Task(void const * argument)
{
  /* USER CODE BEGIN Measuredist_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Measuredist_Task */
}

/* USER CODE BEGIN Header_OLED_Task */
/**
* @brief Function implementing the OLED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_OLED_Task */
__weak void OLED_Task(void const * argument)
{
  /* USER CODE BEGIN OLED_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END OLED_Task */
}

/* USER CODE BEGIN Header_Movecontrol_Task */
/**
* @brief Function implementing the Movecontrol thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Movecontrol_Task */
__weak void Movecontrol_Task(void const * argument)
{
  /* USER CODE BEGIN Movecontrol_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Movecontrol_Task */
}

/* USER CODE BEGIN Header_LIGHT_TEST_TASK */
/**
* @brief Function implementing the LIGHT_TEST thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LIGHT_TEST_TASK */
__weak void LIGHT_TEST_TASK(void const * argument)
{
  /* USER CODE BEGIN LIGHT_TEST_TASK */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END LIGHT_TEST_TASK */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

