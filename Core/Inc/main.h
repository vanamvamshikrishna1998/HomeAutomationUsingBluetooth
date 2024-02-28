/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define Sensor_Gas_In_Pin GPIO_PIN_0
#define Sensor_Gas_In_GPIO_Port GPIOC
#define Lcd_En_Out_Pin GPIO_PIN_1
#define Lcd_En_Out_GPIO_Port GPIOC
#define Lcd_Rw_Out_Pin GPIO_PIN_2
#define Lcd_Rw_Out_GPIO_Port GPIOC
#define Lcd_Rs_Out_Pin GPIO_PIN_3
#define Lcd_Rs_Out_GPIO_Port GPIOC
#define Lcd_D7_Out_Pin GPIO_PIN_0
#define Lcd_D7_Out_GPIO_Port GPIOA
#define Lcd_D6_Out_Pin GPIO_PIN_1
#define Lcd_D6_Out_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define Lcd_D5_Out_Pin GPIO_PIN_4
#define Lcd_D5_Out_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define Sensor_Ir_In_Pin GPIO_PIN_6
#define Sensor_Ir_In_GPIO_Port GPIOA
#define Sensor_Dht_In_Pin GPIO_PIN_7
#define Sensor_Dht_In_GPIO_Port GPIOA
#define Lcd_D4_Out_Pin GPIO_PIN_0
#define Lcd_D4_Out_GPIO_Port GPIOB
#define Led_Out_Pin GPIO_PIN_10
#define Led_Out_GPIO_Port GPIOB
#define Sensor_Buzzer_Out_Pin GPIO_PIN_10
#define Sensor_Buzzer_Out_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define Fan_Out_Pin GPIO_PIN_4
#define Fan_Out_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
