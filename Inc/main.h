/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#define danQiNormal_out_Pin GPIO_PIN_2
#define danQiNormal_out_GPIO_Port GPIOE
#define danQiUp_out_Pin GPIO_PIN_3
#define danQiUp_out_GPIO_Port GPIOE
#define fuYaLow_out_Pin GPIO_PIN_4
#define fuYaLow_out_GPIO_Port GPIOE
#define fuYaNormal_out_Pin GPIO_PIN_5
#define fuYaNormal_out_GPIO_Port GPIOE
#define co2Low_in_Pin GPIO_PIN_7
#define co2Low_in_GPIO_Port GPIOE
#define co2Up_in_Pin GPIO_PIN_8
#define co2Up_in_GPIO_Port GPIOE
#define yaSuoLow_in_Pin GPIO_PIN_9
#define yaSuoLow_in_GPIO_Port GPIOE
#define yaSuoUp_in_Pin GPIO_PIN_10
#define yaSuoUp_in_GPIO_Port GPIOE
#define fuYaLow_in_Pin GPIO_PIN_11
#define fuYaLow_in_GPIO_Port GPIOE
#define fuYaUp_in_Pin GPIO_PIN_12
#define fuYaUp_in_GPIO_Port GPIOE
#define danQiLow_in_Pin GPIO_PIN_13
#define danQiLow_in_GPIO_Port GPIOE
#define danQiUp_in_Pin GPIO_PIN_14
#define danQiUp_in_GPIO_Port GPIOE
#define xiaoQiLow_in_Pin GPIO_PIN_15
#define xiaoQiLow_in_GPIO_Port GPIOE
#define xiaoQiUp_in_Pin GPIO_PIN_10
#define xiaoQiUp_in_GPIO_Port GPIOB
#define yaQiLow_in_Pin GPIO_PIN_11
#define yaQiLow_in_GPIO_Port GPIOB
#define yaQiUp_in_Pin GPIO_PIN_12
#define yaQiUp_in_GPIO_Port GPIOB
#define yangQiLow_in_Pin GPIO_PIN_13
#define yangQiLow_in_GPIO_Port GPIOB
#define yangQiUp_in_Pin GPIO_PIN_14
#define yangQiUp_in_GPIO_Port GPIOB
#define co2Up_out_Pin GPIO_PIN_10
#define co2Up_out_GPIO_Port GPIOD
#define co2Normal_out_Pin GPIO_PIN_11
#define co2Normal_out_GPIO_Port GPIOD
#define co2Low_out_Pin GPIO_PIN_12
#define co2Low_out_GPIO_Port GPIOD
#define yaSuoUp_out_Pin GPIO_PIN_13
#define yaSuoUp_out_GPIO_Port GPIOD
#define yaSuoNormal_out_Pin GPIO_PIN_14
#define yaSuoNormal_out_GPIO_Port GPIOD
#define yaSuoLow_out_Pin GPIO_PIN_15
#define yaSuoLow_out_GPIO_Port GPIOD
#define fuYaUp_out_Pin GPIO_PIN_6
#define fuYaUp_out_GPIO_Port GPIOC
#define beep_Pin GPIO_PIN_7
#define beep_GPIO_Port GPIOC
#define ctrl485_Pin GPIO_PIN_8
#define ctrl485_GPIO_Port GPIOA
#define mute_led_Pin GPIO_PIN_11
#define mute_led_GPIO_Port GPIOA
#define mute_bt_Pin GPIO_PIN_12
#define mute_bt_GPIO_Port GPIOA
#define yangQiLow_out_Pin GPIO_PIN_6
#define yangQiLow_out_GPIO_Port GPIOD
#define yangQiNormal_out_Pin GPIO_PIN_7
#define yangQiNormal_out_GPIO_Port GPIOD
#define yangQiUp_out_Pin GPIO_PIN_3
#define yangQiUp_out_GPIO_Port GPIOB
#define yaQiLow_out_Pin GPIO_PIN_4
#define yaQiLow_out_GPIO_Port GPIOB
#define yaQiNormal_out_Pin GPIO_PIN_6
#define yaQiNormal_out_GPIO_Port GPIOB
#define yaQiUp_out_Pin GPIO_PIN_7
#define yaQiUp_out_GPIO_Port GPIOB
#define xiaoQiLow_out_Pin GPIO_PIN_8
#define xiaoQiLow_out_GPIO_Port GPIOB
#define xiaoQiNormal_out_Pin GPIO_PIN_9
#define xiaoQiNormal_out_GPIO_Port GPIOB
#define xiaoQiUp_out_Pin GPIO_PIN_0
#define xiaoQiUp_out_GPIO_Port GPIOE
#define danQiLow_out_Pin GPIO_PIN_1
#define danQiLow_out_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */



void gasAlarm(void);
void muteStatus(void);


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
