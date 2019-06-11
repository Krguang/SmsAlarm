/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

//#include <stdlib.h>
//#include <string.h>


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

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#define RS485Receive 	HAL_GPIO_WritePin(ctrl485_GPIO_Port,ctrl485_Pin,GPIO_PIN_RESET)
#define RS485Send			HAL_GPIO_WritePin(ctrl485_GPIO_Port,ctrl485_Pin,GPIO_PIN_SET)

#define BEEP_ON				HAL_GPIO_WritePin(beep_GPIO_Port,beep_Pin,GPIO_PIN_RESET)
#define BEEP_OFF			HAL_GPIO_WritePin(beep_GPIO_Port,beep_Pin,GPIO_PIN_SET)


void gasAlarm(void);
void muteStatus(void);
//void putInMQ(void);


const uint8_t KEY_TIME = 5;							//按键消抖延时时间 50ms

uint8_t keyLock;					//按键触发后自锁的变量标志
uint16_t keyTimeCount;				//按键去抖演示计数器
uint8_t keyStatus;					//按键状态   按下：1；抬起：0
uint8_t muteFlag;					//1:静音；0：有声音

const uint16_t COUNT_TIME = 60;

uint16_t lowLevelCount[14];
uint16_t highLevelCount[14];
uint16_t gasStatus[14];
uint16_t lowLevelTemp[14];
uint16_t gasStatusTemp[14];

/*

uint8_t yangQiUpCode = 0;
uint8_t yangQiNormalCode = 100;
uint8_t yangQiLowCode = 1;

uint8_t yaQiUpCode = 2;
uint8_t yaQiNormalCode = 102;
uint8_t yaQiLowCode = 3;

uint8_t xiaoQiUpCode = 4;
uint8_t xiaoQiNormalCode = 104;
uint8_t xiaoQiLowCode = 5;

uint8_t danQiUpCode = 6;
uint8_t danQiNormalCode = 106;
uint8_t danQiLowCode = 7;

uint8_t fuYaUpCode = 8;
uint8_t fuYaNormalCode = 108;
uint8_t fuYaLowCode = 9;

uint8_t yaSuoUpCode = 10;
uint8_t yaSuoNormalCode = 110;
uint8_t YaSuoLowCode = 11;

uint8_t co2UpCode = 12;
uint8_t co2NormalCode = 112;
uint8_t co2LowCode = 13;
*/

/*
struct node
{
	uint8_t data;
	struct node *pNext;
};

struct node * create_node(int data) {

	struct node *p = (struct node *)malloc(sizeof(struct node));
	if (NULL == p) {

		printf("malloc error.\n");
		return NULL;
	}
	//bzero(p,sizeof(struct node));
	memset(p, 0, sizeof(struct node));
	p->data = data;
	p->pNext = NULL;
	return p;

}
void insert_tail(struct node *pH, struct node *new) {

	struct node *p = pH;
	while (NULL != p->pNext) {

		p = p->pNext;
	}

	p->pNext = new;
}

struct node *pHeader;
*/

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
  MX_USART1_UART_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim4);

	RS485Send;

	//pHeader = create_node(200);


	for (size_t i = 0; i < 14; i++)
	{
		highLevelCount[i] = 200;	//初始化高电平数据，防止上电一分钟后报 气体恢复
	}

  /* USER CODE END 2 */

  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	//	gasAlarm();
	//	muteStatus();
		//putInMQ();

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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

//根据按键设置指示灯和静音标志位
void muteStatus() {

	if (1 == keyStatus) {

		keyStatus = 0;
		if (1 == muteFlag) {
			muteFlag = 0;
			HAL_GPIO_WritePin(mute_led_GPIO_Port, mute_led_Pin, GPIO_PIN_SET);
		}
		else {

			muteFlag = 1;
			BEEP_OFF;
			HAL_GPIO_WritePin(mute_led_GPIO_Port, mute_led_Pin, GPIO_PIN_RESET);
		}
	}
}

/*
//把要发送的信息存入队列
void putInMQ() {


	for (uint8_t i = 0; i<14; i++) {

		if (gasStatusTemp[i] != gasStatus[i]) {

			gasStatusTemp[i] = gasStatus[i];
			if (1 == gasStatus[i]) {

				insert_tail(pHeader, create_node(i));

			}
			else {

				insert_tail(pHeader, create_node(i + 100));
			}
		}
	}
}

void sendMessege(char* alarmMsg) {		//根据报警内容发送短信



}


void judgeAlarmMessege(uint8_t code) {		//通过代号判断要发送的短信

	switch (code) {
	case 0:
		printf("氧气超压\n");
		break;
	case 1:
		printf("氧气欠压\n");
		break;
	case 100:
		printf("氧气恢复正常\n");
		break;
	case 101:
		printf("氧气恢复正常\n");
		break;

	default:break;

	}
}



void getOutMessege() {

	struct node *p = NULL;

	if (pHeader->pNext != NULL) {								//判断头节点之后的第一个节点是否是空

		p = pHeader->pNext;											//开始操作这个节点

		judgeAlarmMessege(p->data);					//通过代号判断要发送的短信

		if (NULL == p->pNext) {				//如果是尾节点

			pHeader->pNext = NULL;
			free(p);
		}
		else {

			pHeader->pNext = p->pNext;
			free(p);
		}
	}
}
*/

//报警扫描函数
void alarmScan() {


	if (1 == HAL_GPIO_ReadPin(yangQiUp_in_GPIO_Port, yangQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[0] = 57;
		highLevelCount[0]++;
		if (highLevelCount[0] > 200)
		{
			highLevelCount[0] = 200;
		}
		if (highLevelCount[0] == 10) {

			printf("13600501179:0:氧气超压恢复正常\n");
		}
	}
	else {
		highLevelCount[0] = 0;
		lowLevelCount[0]++;
		if (lowLevelCount[0] > COUNT_TIME) {
			lowLevelCount[0] = 0;
			printf("13600501179:0:氧气超压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(yangQiLow_in_GPIO_Port, yangQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[1] = 57;
		highLevelCount[1]++;
		if (highLevelCount[1] > 200)
		{
			highLevelCount[1] = 200;
		}
		if (highLevelCount[1] == 10) {

			printf("13600501179:0:氧气欠压恢复正常\n");
		}
	}
	else {
		highLevelCount[1] = 0;
		lowLevelCount[1]++;
		if (lowLevelCount[1] > COUNT_TIME) {
			lowLevelCount[1] = 0;
			printf("13600501179:0:氧气欠压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaQiUp_in_GPIO_Port, yaQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[2] = 57;
		highLevelCount[2]++;
		if (highLevelCount[2] > 200)
		{
			highLevelCount[2] = 200;
		}
		if (highLevelCount[2] == 10) {

			printf("13600501179:0:氩气超压恢复正常\n");
		}
	}
	else {
		highLevelCount[2] = 0;
		lowLevelCount[2]++;
		if (lowLevelCount[2] > COUNT_TIME) {
			lowLevelCount[2] = 0;
			printf("13600501179:0:氩气超压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaQiLow_in_GPIO_Port, yaQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[3] = 57;
		highLevelCount[3]++;
		if (highLevelCount[3] > 200)
		{
			highLevelCount[3] = 200;
		}
		if (highLevelCount[3] == 10) {

			printf("13600501179:0:氩气欠压恢复正常\n");
		}
	}
	else {
		highLevelCount[3] = 0;
		lowLevelCount[3]++;
		if (lowLevelCount[3] > COUNT_TIME) {
			lowLevelCount[3] = 0;
			printf("13600501179:0:氩气欠压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(xiaoQiUp_in_GPIO_Port, xiaoQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[4] = 57;
		highLevelCount[4]++;
		if (highLevelCount[4] > 200)
		{
			highLevelCount[4] = 200;
		}
		if (highLevelCount[4] == 10) {

			printf("13600501179:0:笑气超压恢复正常\n");
		}
	}
	else {
		highLevelCount[4] = 0;
		lowLevelCount[4]++;
		if (lowLevelCount[4] > COUNT_TIME) {
			lowLevelCount[4] = 0;
			printf("13600501179:0:笑气超压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(xiaoQiLow_in_GPIO_Port, xiaoQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[5] = 57;
		highLevelCount[5]++;
		if (highLevelCount[5] > 200)
		{
			highLevelCount[5] = 200;
		}
		if (highLevelCount[5] == 10) {

			printf("13600501179:0:笑气欠压恢复正常\n");
		}
	}
	else {
		highLevelCount[5] = 0;
		lowLevelCount[5]++;
		if (lowLevelCount[5] > COUNT_TIME) {
			lowLevelCount[5] = 0;
			printf("13600501179:0:笑气欠压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(danQiUp_in_GPIO_Port, danQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[6] = 57;
		highLevelCount[6]++;
		if (highLevelCount[6] > 200)
		{
			highLevelCount[6] = 200;
		}
		if (highLevelCount[6] == 10) {

			printf("13600501179:0:氮气超压恢复正常\n");
		}
	}
	else {
		highLevelCount[6] = 0;
		lowLevelCount[6]++;
		if (lowLevelCount[6] > COUNT_TIME) {
			lowLevelCount[6] = 0;
			printf("13600501179:0:氮气超压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(danQiLow_in_GPIO_Port, danQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[7] = 57;
		highLevelCount[7]++;
		if (highLevelCount[7] > 200)
		{
			highLevelCount[7] = 200;
		}
		if (highLevelCount[7] == 10) {

			printf("13600501179:0:氮气欠压恢复正常\n");
		}
	}
	else {
		highLevelCount[7] = 0;
		lowLevelCount[7]++;
		if (lowLevelCount[7] > COUNT_TIME) {
			lowLevelCount[7] = 0;
			printf("13600501179:0:氮气欠压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(fuYaUp_in_GPIO_Port, fuYaUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[8] = 57;
		highLevelCount[8]++;
		if (highLevelCount[8] > 200)
		{
			highLevelCount[8] = 200;
		}
		if (highLevelCount[8] == 10) {

			printf("13600501179:0:负压吸引超压恢复正常\n");
		}
	}
	else {
		highLevelCount[8] = 0;
		lowLevelCount[8]++;
		if (lowLevelCount[8] > COUNT_TIME) {
			lowLevelCount[8] = 0;
			printf("13600501179:0:负压吸引超压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(fuYaLow_in_GPIO_Port, fuYaLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[9] = 57;
		highLevelCount[9]++;
		if (highLevelCount[9] > 200)
		{
			highLevelCount[9] = 200;
		}
		if (highLevelCount[9] == 10) {

			printf("13600501179:0:负压吸引欠压恢复正常\n");
		}
	}
	else {
		highLevelCount[9] = 0;
		lowLevelCount[9]++;
		if (lowLevelCount[9] > COUNT_TIME) {
			lowLevelCount[9] = 0;
			printf("13600501179:0:负压吸引欠压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaSuoUp_in_GPIO_Port, yaSuoUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[10] = 57;
		highLevelCount[10]++;
		if (highLevelCount[10] > 200)
		{
			highLevelCount[10] = 200;
		}
		if (highLevelCount[10] == 10) {

			printf("13600501179:0:压缩空气超压恢复正常\n");
		}
	}
	else {
		highLevelCount[10] = 0;
		lowLevelCount[10]++;
		if (lowLevelCount[10] > COUNT_TIME) {
			lowLevelCount[10] = 0;
			printf("13600501179:0:压缩空气超压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaSuoLow_in_GPIO_Port, yaSuoLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[11] = 57;
		highLevelCount[11]++;
		if (highLevelCount[11] > 200)
		{
			highLevelCount[11] = 200;
		}
		if (highLevelCount[11] == 10) {

			printf("13600501179:0:压缩空气欠压恢复正常\n");
		}
	}
	else {
		highLevelCount[11] = 0;
		lowLevelCount[11]++;
		if (lowLevelCount[11] > COUNT_TIME) {
			lowLevelCount[11] = 0;
			printf("13600501179:0:压缩空气欠压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(co2Up_in_GPIO_Port, co2Up_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[12] = 57;
		highLevelCount[12]++;
		if (highLevelCount[12] > 200)
		{
			highLevelCount[12] = 200;
		}
		if (highLevelCount[12] == 10) {

			printf("13600501179:0:二氧化碳超压恢复正常\n");
		}
	}
	else {
		highLevelCount[12] = 0;
		lowLevelCount[12]++;
		if (lowLevelCount[12] > COUNT_TIME) {
			lowLevelCount[12] = 0;
			printf("13600501179:0:二氧化碳超压报警\n");
		}
	}

	if (1 == HAL_GPIO_ReadPin(co2Low_in_GPIO_Port, co2Low_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[13] = 57;
		highLevelCount[13]++;
		if (highLevelCount[13] > 200)
		{
			highLevelCount[13] = 200;
		}
		if (highLevelCount[13] == 10) {

			printf("13600501179:0:二氧化碳欠压恢复正常\n");
		}
	}
	else {
		highLevelCount[13] = 0;
		lowLevelCount[13]++;
		if (lowLevelCount[13] > COUNT_TIME) {
			lowLevelCount[13] = 0;
			printf("13600501179:0:二氧化碳欠压报警\n");
		}
	}

}


//按键扫描函数
void keyScan() {


	if (1 == HAL_GPIO_ReadPin(mute_bt_GPIO_Port, mute_bt_Pin))		//IO 是高电平，说明按键没有被按下，这时要及时清零一些标志位
	{
		keyLock = 0;			//按键自锁标志清零
		keyTimeCount = 0;		//按键去抖动延时计数器清零
	}
	else if (keyLock == 0)		//有按键按下，且是第一次被按下
	{
		keyTimeCount++;
		if (keyTimeCount > KEY_TIME)
		{
			keyTimeCount = 0;
			keyLock = 1;
			keyStatus = 1;
		}
	}


	/*

	if (1 == HAL_GPIO_ReadPin(yangQiUp_in_GPIO_Port, yangQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[0] = 0;

		if (highLevelCount[0] > 200) {
			highLevelCount[0] = 200;
		}
		highLevelCount[0]++;
		if (highLevelCount[0] > COUNT_TIME) {
			gasStatus[0] = 0;
		}
	}
	else {

		highLevelCount[0] = 0;
		if (lowLevelCount[0] > 200) {
			lowLevelCount[0] = 200;
		}
		lowLevelCount[0]++;
		if (lowLevelCount[0] > COUNT_TIME) {
			gasStatus[0] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(yangQiLow_in_GPIO_Port, yangQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[1] = 0;

		if (highLevelCount[1] > 200) {
			highLevelCount[1] = 200;
		}
		highLevelCount[1]++;
		if (highLevelCount[1] > COUNT_TIME) {
			gasStatus[1] = 0;
		}
	}
	else {

		highLevelCount[1] = 0;
		if (lowLevelCount[1] > 200) {
			lowLevelCount[1] = 200;
		}
		lowLevelCount[1]++;
		if (lowLevelCount[1] > COUNT_TIME) {
			gasStatus[1] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaQiUp_in_GPIO_Port, yaQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[2] = 0;

		if (highLevelCount[2] > 200) {
			highLevelCount[2] = 200;
		}
		highLevelCount[2]++;
		if (highLevelCount[2] > COUNT_TIME) {
			gasStatus[2] = 0;
		}
	}
	else {

		highLevelCount[2] = 0;
		if (lowLevelCount[2] > 200) {
			lowLevelCount[2] = 200;
		}
		lowLevelCount[2]++;
		if (lowLevelCount[2] > COUNT_TIME) {
			gasStatus[2] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaQiLow_in_GPIO_Port, yaQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[3] = 0;

		if (highLevelCount[3] > 200) {
			highLevelCount[3] = 200;
		}
		highLevelCount[3]++;
		if (highLevelCount[3] > COUNT_TIME) {
			gasStatus[3] = 0;
		}
	}
	else {

		highLevelCount[3] = 0;
		if (lowLevelCount[3] > 200) {
			lowLevelCount[3] = 200;
		}
		lowLevelCount[3]++;
		if (lowLevelCount[3] > COUNT_TIME) {
			gasStatus[3] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(xiaoQiUp_in_GPIO_Port, xiaoQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[4] = 0;

		if (highLevelCount[4] > 200) {
			highLevelCount[4] = 200;
		}
		highLevelCount[4]++;
		if (highLevelCount[4] > COUNT_TIME) {
			gasStatus[4] = 0;
		}
	}
	else {

		highLevelCount[4] = 0;
		if (lowLevelCount[4] > 200) {
			lowLevelCount[4] = 200;
		}
		lowLevelCount[4]++;
		if (lowLevelCount[4] > COUNT_TIME) {
			gasStatus[4] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(xiaoQiLow_in_GPIO_Port, xiaoQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[5] = 0;

		if (highLevelCount[5] > 200) {
			highLevelCount[5] = 200;
		}
		highLevelCount[5]++;
		if (highLevelCount[5] > COUNT_TIME) {
			gasStatus[5] = 0;
		}
	}
	else {

		highLevelCount[5] = 0;
		if (lowLevelCount[5] > 200) {
			lowLevelCount[5] = 200;
		}
		lowLevelCount[5]++;
		if (lowLevelCount[5] > COUNT_TIME) {
			gasStatus[5] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(danQiUp_in_GPIO_Port, danQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[6] = 0;

		if (highLevelCount[6] > 200) {
			highLevelCount[6] = 200;
		}
		highLevelCount[6]++;
		if (highLevelCount[6] > COUNT_TIME) {
			gasStatus[6] = 0;
		}
	}
	else {

		highLevelCount[6] = 0;
		if (lowLevelCount[6] > 200) {
			lowLevelCount[6] = 200;
		}
		lowLevelCount[6]++;
		if (lowLevelCount[6] > COUNT_TIME) {
			gasStatus[6] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(danQiLow_in_GPIO_Port, danQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[7] = 0;

		if (highLevelCount[7] > 200) {
			highLevelCount[7] = 200;
		}
		highLevelCount[7]++;
		if (highLevelCount[7] > COUNT_TIME) {
			gasStatus[7] = 0;
		}
	}
	else {

		highLevelCount[7] = 0;
		if (lowLevelCount[7] > 200) {
			lowLevelCount[7] = 200;
		}
		lowLevelCount[7]++;
		if (lowLevelCount[7] > COUNT_TIME) {
			gasStatus[7] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(fuYaUp_in_GPIO_Port, fuYaUp_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[8] = 0;

		if (highLevelCount[8] > 200) {
			highLevelCount[8] = 200;
		}
		highLevelCount[8]++;
		if (highLevelCount[8] > COUNT_TIME) {
			gasStatus[8] = 0;
		}
	}
	else {

		highLevelCount[8] = 0;
		if (lowLevelCount[8] > 200) {
			lowLevelCount[8] = 200;
		}
		lowLevelCount[8]++;
		if (lowLevelCount[8] > COUNT_TIME) {
			gasStatus[8] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(fuYaLow_in_GPIO_Port, fuYaLow_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[9] = 0;

		if (highLevelCount[9] > 200) {
			highLevelCount[9] = 200;
		}
		highLevelCount[9]++;
		if (highLevelCount[9] > COUNT_TIME) {
			gasStatus[9] = 0;
		}
	}
	else {

		highLevelCount[9] = 0;
		if (lowLevelCount[9] > 200) {
			lowLevelCount[9] = 200;
		}
		lowLevelCount[9]++;
		if (lowLevelCount[9] > COUNT_TIME) {
			gasStatus[9] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaSuoUp_in_GPIO_Port, yaSuoUp_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[10] = 0;

		if (highLevelCount[10] > 200) {
			highLevelCount[10] = 200;
		}
		highLevelCount[10]++;
		if (highLevelCount[10] > COUNT_TIME) {
			gasStatus[10] = 0;
		}
	}
	else {

		highLevelCount[10] = 0;
		if (lowLevelCount[10] > 200) {
			lowLevelCount[10] = 200;
		}
		lowLevelCount[10]++;
		if (lowLevelCount[10] > COUNT_TIME) {
			gasStatus[10] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaSuoLow_in_GPIO_Port, yaSuoLow_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[11] = 0;

		if (highLevelCount[11] > 200) {
			highLevelCount[11] = 200;
		}
		highLevelCount[11]++;
		if (highLevelCount[11] > COUNT_TIME) {
			gasStatus[11] = 0;
		}
	}
	else {

		highLevelCount[11] = 0;
		if (lowLevelCount[11] > 200) {
			lowLevelCount[11] = 200;
		}
		lowLevelCount[11]++;
		if (lowLevelCount[11] > COUNT_TIME) {
			gasStatus[11] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(co2Up_in_GPIO_Port, co2Up_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[12] = 0;

		if (highLevelCount[12] > 200) {
			highLevelCount[12] = 200;
		}
		highLevelCount[12]++;
		if (highLevelCount[12] > COUNT_TIME) {
			gasStatus[12] = 0;
		}
	}
	else {

		highLevelCount[12] = 0;
		if (lowLevelCount[12] > 200) {
			lowLevelCount[12] = 200;
		}
		lowLevelCount[12]++;
		if (lowLevelCount[12] > COUNT_TIME) {
			gasStatus[12] = 1;
		}
	}

	if (1 == HAL_GPIO_ReadPin(co2Low_in_GPIO_Port, co2Low_in_Pin))		//IO 是高电平 对应没有报警状态  gasStatus[0] = 0;
	{

		lowLevelCount[13] = 0;

		if (highLevelCount[13] > 200) {
			highLevelCount[13] = 200;
		}
		highLevelCount[13]++;
		if (highLevelCount[13] > COUNT_TIME) {
			gasStatus[13] = 0;
		}
	}
	else {

		highLevelCount[13] = 0;
		if (lowLevelCount[13] > 200) {
			lowLevelCount[13] = 200;
		}
		lowLevelCount[13]++;
		if (lowLevelCount[13] > COUNT_TIME) {
			gasStatus[13] = 1;
		}
	}
	*/
}


void gasAlarm() {

	if ((0 == HAL_GPIO_ReadPin(yangQiUp_in_GPIO_Port, yangQiUp_in_Pin)) || (0 == HAL_GPIO_ReadPin(yangQiLow_in_GPIO_Port, yangQiLow_in_Pin))) {										//氧气报警

		HAL_GPIO_WritePin(yangQiNormal_out_GPIO_Port, yangQiNormal_out_Pin, GPIO_PIN_RESET);

		if (0 == HAL_GPIO_ReadPin(yangQiUp_in_GPIO_Port, yangQiUp_in_Pin)) {
			HAL_GPIO_WritePin(yangQiUp_out_GPIO_Port, yangQiUp_out_Pin, GPIO_PIN_SET);
		}

		if (0 == HAL_GPIO_ReadPin(yangQiLow_in_GPIO_Port, yangQiLow_in_Pin)) {
			HAL_GPIO_WritePin(yangQiLow_out_GPIO_Port, yangQiLow_out_Pin, GPIO_PIN_SET);
		}

		if (0 == muteFlag) {

			BEEP_ON;
		}

	}
	else {
		HAL_GPIO_WritePin(yangQiNormal_out_GPIO_Port, yangQiNormal_out_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yangQiUp_out_GPIO_Port, yangQiUp_out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yangQiLow_out_GPIO_Port, yangQiLow_out_Pin, GPIO_PIN_RESET);

	}


	if ((0 == HAL_GPIO_ReadPin(yaQiUp_in_GPIO_Port, yaQiUp_in_Pin)) || (0 == HAL_GPIO_ReadPin(yaQiLow_in_GPIO_Port, yaQiLow_in_Pin))) {										//氩气报警

		HAL_GPIO_WritePin(yaQiNormal_out_GPIO_Port, yaQiNormal_out_Pin, GPIO_PIN_RESET);

		if (0 == HAL_GPIO_ReadPin(yaQiUp_in_GPIO_Port, yaQiUp_in_Pin)) {
			HAL_GPIO_WritePin(yaQiUp_out_GPIO_Port, yaQiUp_out_Pin, GPIO_PIN_SET);
		}

		if (0 == HAL_GPIO_ReadPin(yaQiLow_in_GPIO_Port, yaQiLow_in_Pin)) {
			HAL_GPIO_WritePin(yaQiLow_out_GPIO_Port, yaQiLow_out_Pin, GPIO_PIN_SET);
		}
		if (0 == muteFlag) {

			BEEP_ON;
		}

	}
	else {
		HAL_GPIO_WritePin(yaQiNormal_out_GPIO_Port, yaQiNormal_out_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yaQiUp_out_GPIO_Port, yaQiUp_out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yaQiLow_out_GPIO_Port, yaQiLow_out_Pin, GPIO_PIN_RESET);

	}

	if ((0 == HAL_GPIO_ReadPin(xiaoQiUp_in_GPIO_Port, xiaoQiUp_in_Pin)) || (0 == HAL_GPIO_ReadPin(xiaoQiLow_in_GPIO_Port, xiaoQiLow_in_Pin))) {										//笑气报警

		HAL_GPIO_WritePin(xiaoQiNormal_out_GPIO_Port, xiaoQiNormal_out_Pin, GPIO_PIN_RESET);

		if (0 == HAL_GPIO_ReadPin(xiaoQiUp_in_GPIO_Port, xiaoQiUp_in_Pin)) {
			HAL_GPIO_WritePin(xiaoQiUp_out_GPIO_Port, xiaoQiUp_out_Pin, GPIO_PIN_SET);
		}

		if (0 == HAL_GPIO_ReadPin(xiaoQiLow_in_GPIO_Port, xiaoQiLow_in_Pin)) {
			HAL_GPIO_WritePin(xiaoQiLow_out_GPIO_Port, xiaoQiLow_out_Pin, GPIO_PIN_SET);
		}

		if (0 == muteFlag) {

			BEEP_ON;
		}

	}
	else {
		HAL_GPIO_WritePin(xiaoQiNormal_out_GPIO_Port, xiaoQiNormal_out_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(xiaoQiUp_out_GPIO_Port, xiaoQiUp_out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(xiaoQiLow_out_GPIO_Port, xiaoQiLow_out_Pin, GPIO_PIN_RESET);

	}

	if ((0 == HAL_GPIO_ReadPin(danQiUp_in_GPIO_Port, danQiUp_in_Pin)) || (0 == HAL_GPIO_ReadPin(danQiLow_in_GPIO_Port, danQiLow_in_Pin))) {										//氮气报警

		HAL_GPIO_WritePin(danQiNormal_out_GPIO_Port, danQiNormal_out_Pin, GPIO_PIN_RESET);

		if (0 == HAL_GPIO_ReadPin(danQiUp_in_GPIO_Port, danQiUp_in_Pin)) {
			HAL_GPIO_WritePin(danQiUp_out_GPIO_Port, danQiUp_out_Pin, GPIO_PIN_SET);
		}

		if (0 == HAL_GPIO_ReadPin(danQiLow_in_GPIO_Port, danQiLow_in_Pin)) {
			HAL_GPIO_WritePin(danQiLow_out_GPIO_Port, danQiLow_out_Pin, GPIO_PIN_SET);
		}

		if (0 == muteFlag) {

			BEEP_ON;
		}

	}
	else {
		HAL_GPIO_WritePin(danQiNormal_out_GPIO_Port, danQiNormal_out_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(danQiUp_out_GPIO_Port, danQiUp_out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(danQiLow_out_GPIO_Port, danQiLow_out_Pin, GPIO_PIN_RESET);

	}

	if ((0 == HAL_GPIO_ReadPin(fuYaUp_in_GPIO_Port, fuYaUp_in_Pin)) || (0 == HAL_GPIO_ReadPin(fuYaLow_in_GPIO_Port, fuYaLow_in_Pin))) {										//负压报警

		HAL_GPIO_WritePin(fuYaNormal_out_GPIO_Port, fuYaNormal_out_Pin, GPIO_PIN_RESET);

		if (0 == HAL_GPIO_ReadPin(fuYaUp_in_GPIO_Port, fuYaUp_in_Pin)) {
			HAL_GPIO_WritePin(fuYaUp_out_GPIO_Port, fuYaUp_out_Pin, GPIO_PIN_SET);
		}

		if (0 == HAL_GPIO_ReadPin(fuYaLow_in_GPIO_Port, fuYaLow_in_Pin)) {
			HAL_GPIO_WritePin(fuYaLow_out_GPIO_Port, fuYaLow_out_Pin, GPIO_PIN_SET);
		}

		if (0 == muteFlag) {

			BEEP_ON;
		}

	}
	else {
		HAL_GPIO_WritePin(fuYaNormal_out_GPIO_Port, fuYaNormal_out_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(fuYaUp_out_GPIO_Port, fuYaUp_out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(fuYaLow_out_GPIO_Port, fuYaLow_out_Pin, GPIO_PIN_RESET);

	}

	if ((0 == HAL_GPIO_ReadPin(yaSuoUp_in_GPIO_Port, yaSuoUp_in_Pin)) || (0 == HAL_GPIO_ReadPin(yaSuoLow_in_GPIO_Port, yaSuoLow_in_Pin))) {										//压缩空气报警

		HAL_GPIO_WritePin(yaSuoNormal_out_GPIO_Port, yaSuoNormal_out_Pin, GPIO_PIN_RESET);

		if (0 == HAL_GPIO_ReadPin(yaSuoUp_in_GPIO_Port, yaSuoUp_in_Pin)) {
			HAL_GPIO_WritePin(yaSuoUp_out_GPIO_Port, yaSuoUp_out_Pin, GPIO_PIN_SET);
		}

		if (0 == HAL_GPIO_ReadPin(yaSuoLow_in_GPIO_Port, yaSuoLow_in_Pin)) {
			HAL_GPIO_WritePin(yaSuoLow_out_GPIO_Port, yaSuoLow_out_Pin, GPIO_PIN_SET);
		}

		if (0 == muteFlag) {

			BEEP_ON;
		}

	}
	else {
		HAL_GPIO_WritePin(yaSuoNormal_out_GPIO_Port, yaSuoNormal_out_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yaSuoUp_out_GPIO_Port, yaSuoUp_out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yaSuoLow_out_GPIO_Port, yaSuoLow_out_Pin, GPIO_PIN_RESET);

	}

	if ((0 == HAL_GPIO_ReadPin(co2Up_in_GPIO_Port, co2Up_in_Pin)) || (0 == HAL_GPIO_ReadPin(co2Low_in_GPIO_Port, co2Low_in_Pin))) {										//CO2报警

		HAL_GPIO_WritePin(co2Normal_out_GPIO_Port, co2Normal_out_Pin, GPIO_PIN_RESET);

		if (0 == HAL_GPIO_ReadPin(co2Up_in_GPIO_Port, co2Up_in_Pin)) {
			HAL_GPIO_WritePin(co2Up_out_GPIO_Port, co2Up_out_Pin, GPIO_PIN_SET);
		}

		if (0 == HAL_GPIO_ReadPin(co2Low_in_GPIO_Port, co2Low_in_Pin)) {
			HAL_GPIO_WritePin(co2Low_out_GPIO_Port, co2Low_out_Pin, GPIO_PIN_SET);
		}

		if (0 == muteFlag) {

			BEEP_ON;
		}

	}
	else {
		HAL_GPIO_WritePin(co2Normal_out_GPIO_Port, co2Normal_out_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(co2Up_out_GPIO_Port, co2Up_out_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(co2Low_out_GPIO_Port, co2Low_out_Pin, GPIO_PIN_RESET);
	}

	if ((1 == HAL_GPIO_ReadPin(yangQiUp_in_GPIO_Port, yangQiUp_in_Pin)) && (HAL_GPIO_ReadPin(yangQiLow_in_GPIO_Port, yangQiLow_in_Pin)) &&
		(1 == HAL_GPIO_ReadPin(yaQiUp_in_GPIO_Port, yaQiUp_in_Pin)) && (HAL_GPIO_ReadPin(yaQiLow_in_GPIO_Port, yaQiLow_in_Pin)) &&
		(1 == HAL_GPIO_ReadPin(xiaoQiUp_in_GPIO_Port, xiaoQiUp_in_Pin)) && (HAL_GPIO_ReadPin(xiaoQiLow_in_GPIO_Port, xiaoQiLow_in_Pin)) &&
		(1 == HAL_GPIO_ReadPin(danQiUp_in_GPIO_Port, danQiUp_in_Pin)) && (HAL_GPIO_ReadPin(danQiLow_in_GPIO_Port, danQiLow_in_Pin)) &&
		(1 == HAL_GPIO_ReadPin(fuYaUp_in_GPIO_Port, fuYaUp_in_Pin)) && (HAL_GPIO_ReadPin(fuYaLow_in_GPIO_Port, fuYaLow_in_Pin)) &&
		(1 == HAL_GPIO_ReadPin(yaSuoUp_in_GPIO_Port, yaSuoUp_in_Pin)) && (HAL_GPIO_ReadPin(yaSuoLow_in_GPIO_Port, yaSuoLow_in_Pin)) &&
		(1 == HAL_GPIO_ReadPin(co2Up_in_GPIO_Port, co2Up_in_Pin)) && (HAL_GPIO_ReadPin(co2Low_in_GPIO_Port, co2Low_in_Pin))
		) {

		BEEP_OFF;
	}

}

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM5 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

	if (htim->Instance == TIM3) {	//10ms 定时器
		keyScan();
	}

	if (htim->Instance == TIM4) {	//1s定时器
	//	alarmScan();
	}

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM5) {
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
	tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
