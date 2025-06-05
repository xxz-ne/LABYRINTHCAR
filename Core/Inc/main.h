/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define ECHO1_Pin GPIO_PIN_0
#define ECHO1_GPIO_Port GPIOA
#define ECHO2_Pin GPIO_PIN_1
#define ECHO2_GPIO_Port GPIOA
#define ECHO3_Pin GPIO_PIN_2
#define ECHO3_GPIO_Port GPIOA
#define TRIGL_Pin GPIO_PIN_3
#define TRIGL_GPIO_Port GPIOA
#define TRIGF_Pin GPIO_PIN_4
#define TRIGF_GPIO_Port GPIOA
#define TRIGR_Pin GPIO_PIN_5
#define TRIGR_GPIO_Port GPIOA
#define LIGHT_LEFT_Pin GPIO_PIN_12
#define LIGHT_LEFT_GPIO_Port GPIOB
#define OLED_RES_Pin GPIO_PIN_8
#define OLED_RES_GPIO_Port GPIOA
#define OLED_DC_Pin GPIO_PIN_9
#define OLED_DC_GPIO_Port GPIOA
#define OLED_CS_Pin GPIO_PIN_10
#define OLED_CS_GPIO_Port GPIOA
#define LIGHT_FRONT_Pin GPIO_PIN_11
#define LIGHT_FRONT_GPIO_Port GPIOA
#define LIGHT_RIGHT_Pin GPIO_PIN_12
#define LIGHT_RIGHT_GPIO_Port GPIOA
#define IN4_Pin GPIO_PIN_15
#define IN4_GPIO_Port GPIOA
#define IN3_Pin GPIO_PIN_3
#define IN3_GPIO_Port GPIOB
#define IN2_Pin GPIO_PIN_4
#define IN2_GPIO_Port GPIOB
#define IN1_Pin GPIO_PIN_5
#define IN1_GPIO_Port GPIOB
#define ENA_Pin GPIO_PIN_6
#define ENA_GPIO_Port GPIOB
#define ENB_Pin GPIO_PIN_7
#define ENB_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
