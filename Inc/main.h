/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

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

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
