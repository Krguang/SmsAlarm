#include "smsAlarm.h"
#include "cmsis_os.h"


const uint16_t INTERVAL_TIME = 5000;

uint16_t countTime[14];
uint16_t lowLevelCount[14];
uint16_t highLevelCount[14];
uint16_t gasStatus[14];
uint16_t lowLevelTemp[14];
uint16_t gasStatusTemp[14];
uint8_t smsCount[14];

//报警扫描函数
void alarmScan() {

	if (1 == HAL_GPIO_ReadPin(yangQiUp_in_GPIO_Port, yangQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[0] = COUNT_TIME_START-3;
		highLevelCount[0]++;
		if (highLevelCount[0] > 200)
		{
			highLevelCount[0] = 200;
		}
		if (highLevelCount[0] == 10) {

			printf("13600501179:0:氧气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氧气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氧气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[0] = 0;
			countTime[0] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[0] = 0;
		lowLevelCount[0]++;
		if (lowLevelCount[0] > countTime[0]) {
			lowLevelCount[0] = 0;

			printf("13600501179:0:氧气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氧气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氧气超压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[0]++;
			if (smsCount[0] >= 3)
			{
				smsCount[0] = 3;
				countTime[0] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(yangQiLow_in_GPIO_Port, yangQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[1] = COUNT_TIME_START-3;
		highLevelCount[1]++;
		if (highLevelCount[1] > 200)
		{
			highLevelCount[1] = 200;
		}
		if (highLevelCount[1] == 10) {

			printf("13600501179:0:氧气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氧气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氧气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[1] = 0;
			countTime[1] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[1] = 0;
		lowLevelCount[1]++;
		if (lowLevelCount[1] > countTime[1]) {
			lowLevelCount[1] = 0;

			printf("13600501179:0:氧气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氧气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氧气欠压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[1]++;
			if (smsCount[1] >= 3)
			{
				smsCount[1] = 3;
				countTime[1] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaQiUp_in_GPIO_Port, yaQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[2] = COUNT_TIME_START-3;
		highLevelCount[2]++;
		if (highLevelCount[2] > 200)
		{
			highLevelCount[2] = 200;
		}
		if (highLevelCount[2] == 10) {

			printf("13600501179:0:氩气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氩气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氩气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[2] = 0;
			countTime[2] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[2] = 0;
		lowLevelCount[2]++;
		if (lowLevelCount[2] > countTime[2]) {
			lowLevelCount[2] = 0;

			printf("13600501179:0:氩气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氩气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氩气超压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[2]++;
			if (smsCount[2] >= 3)
			{
				smsCount[2] = 3;
				countTime[2] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaQiLow_in_GPIO_Port, yaQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[3] = COUNT_TIME_START-3;
		highLevelCount[3]++;
		if (highLevelCount[3] > 200)
		{
			highLevelCount[3] = 200;
		}
		if (highLevelCount[3] == 10) {

			printf("13600501179:0:氩气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氩气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氩气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[3] = 0;
			countTime[3] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[3] = 0;
		lowLevelCount[3]++;
		if (lowLevelCount[3] > smsCount[3]) {
			lowLevelCount[3] = 0;

			printf("13600501179:0:氩气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氩气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氩气欠压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[3]++;
			if (smsCount[3] >= 3)
			{
				smsCount[3] = 3;
				countTime[3] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(xiaoQiUp_in_GPIO_Port, xiaoQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[4] = COUNT_TIME_START-3;
		highLevelCount[4]++;
		if (highLevelCount[4] > 200)
		{
			highLevelCount[4] = 200;
		}
		if (highLevelCount[4] == 10) {

			printf("13600501179:0:笑气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:笑气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:笑气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[4] = 0;
			countTime[4] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[4] = 0;
		lowLevelCount[4]++;
		if (lowLevelCount[4] > countTime[4]) {
			lowLevelCount[4] = 0;

			printf("13600501179:0:笑气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:笑气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:笑气超压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[4]++;
			if (smsCount[4] >= 3)
			{
				smsCount[4] = 3;
				countTime[4] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(xiaoQiLow_in_GPIO_Port, xiaoQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[5] = COUNT_TIME_START-3;
		highLevelCount[5]++;
		if (highLevelCount[5] > 200)
		{
			highLevelCount[5] = 200;
		}
		if (highLevelCount[5] == 10) {

			printf("13600501179:0:笑气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:笑气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:笑气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[5] = 0;
			countTime[5] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[5] = 0;
		lowLevelCount[5]++;
		if (lowLevelCount[5] > countTime[5]) {
			lowLevelCount[5] = 0;

			printf("13600501179:0:笑气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:笑气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:笑气欠压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[5]++;
			if (smsCount[5] >= 3)
			{
				smsCount[5] = 3;
				countTime[5] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(danQiUp_in_GPIO_Port, danQiUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[6] = COUNT_TIME_START-3;
		highLevelCount[6]++;
		if (highLevelCount[6] > 200)
		{
			highLevelCount[6] = 200;
		}
		if (highLevelCount[6] == 10) {

			printf("13600501179:0:氮气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氮气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氮气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[6] = 0;
			countTime[6] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[6] = 0;
		lowLevelCount[6]++;
		if (lowLevelCount[6] > countTime[6]) {
			lowLevelCount[6] = 0;

			printf("13600501179:0:氮气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氮气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氮气超压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[6]++;
			if (smsCount[6] >= 3)
			{
				smsCount[6] = 3;
				countTime[6] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(danQiLow_in_GPIO_Port, danQiLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[7] = COUNT_TIME_START-3;
		highLevelCount[7]++;
		if (highLevelCount[7] > 200)
		{
			highLevelCount[7] = 200;
		}
		if (highLevelCount[7] == 10) {

			printf("13600501179:0:氮气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氮气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氮气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[7] = 0;
			countTime[7] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[7] = 0;
		lowLevelCount[7]++;
		if (lowLevelCount[7] > countTime[7]) {
			lowLevelCount[7] = 0;

			printf("13600501179:0:氮气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:氮气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:氮气欠压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[7]++;
			if (smsCount[7] >= 3)
			{
				smsCount[7] = 3;
				countTime[7] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(fuYaUp_in_GPIO_Port, fuYaUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[8] = COUNT_TIME_START-3;
		highLevelCount[8]++;
		if (highLevelCount[8] > 200)
		{
			highLevelCount[8] = 200;
		}
		if (highLevelCount[8] == 10) {

			printf("13600501179:0:负压吸引超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:负压吸引超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:负压吸引超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[8] = 0;
			countTime[8] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[8] = 0;
		lowLevelCount[8]++;
		if (lowLevelCount[8] > countTime[8]) {
			lowLevelCount[8] = 0;

			printf("13600501179:0:负压吸引超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:负压吸引超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:负压吸引超压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[8]++;
			if (smsCount[8] >= 3)
			{
				smsCount[8] = 3;
				countTime[8] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(fuYaLow_in_GPIO_Port, fuYaLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[9] = COUNT_TIME_START-3;
		highLevelCount[9]++;
		if (highLevelCount[9] > 200)
		{
			highLevelCount[9] = 200;
		}
		if (highLevelCount[9] == 10) {

			printf("13600501179:0:负压吸引欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:负压吸引欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:负压吸引欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[9] = 0;
			countTime[9] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[9] = 0;
		lowLevelCount[9]++;
		if (lowLevelCount[9] > countTime[9]) {
			lowLevelCount[9] = 0;

			printf("13600501179:0:负压吸引欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:负压吸引欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:负压吸引欠压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[9]++;
			if (smsCount[9] >= 3)
			{
				smsCount[9] = 3;
				countTime[9] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaSuoUp_in_GPIO_Port, yaSuoUp_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[10] = COUNT_TIME_START-3;
		highLevelCount[10]++;
		if (highLevelCount[10] > 200)
		{
			highLevelCount[10] = 200;
		}
		if (highLevelCount[10] == 10) {

			printf("13600501179:0:压缩空气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:压缩空气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:压缩空气超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[10] = 0;
			countTime[10] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[10] = 0;
		lowLevelCount[10]++;
		if (lowLevelCount[10] > countTime[10]) {
			lowLevelCount[10] = 0;

			printf("13600501179:0:压缩空气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:压缩空气超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:压缩空气超压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[10]++;
			if (smsCount[10] >= 3)
			{
				smsCount[10] = 3;
				countTime[10] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(yaSuoLow_in_GPIO_Port, yaSuoLow_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[11] = COUNT_TIME_START-3;
		highLevelCount[11]++;
		if (highLevelCount[11] > 200)
		{
			highLevelCount[11] = 200;
		}
		if (highLevelCount[11] == 10) {

			printf("13600501179:0:压缩空气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:压缩空气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:压缩空气欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[11] = 0;
			countTime[11] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[11] = 0;
		lowLevelCount[11]++;
		if (lowLevelCount[11] > countTime[11]) {
			lowLevelCount[11] = 0;

			printf("13600501179:0:压缩空气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:压缩空气欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:压缩空气欠压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[11]++;
			if (smsCount[11] >= 3)
			{
				smsCount[11] = 3;
				countTime[11] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(co2Up_in_GPIO_Port, co2Up_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[12] = COUNT_TIME_START-3;
		highLevelCount[12]++;
		if (highLevelCount[12] > 200)
		{
			highLevelCount[12] = 200;
		}
		if (highLevelCount[12] == 10) {

			printf("13600501179:0:二氧化碳超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:二氧化碳超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:二氧化碳超压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[12] = 0;
			countTime[12] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[12] = 0;
		lowLevelCount[12]++;
		if (lowLevelCount[12] > countTime[12]) {
			lowLevelCount[12] = 0;

			printf("13600501179:0:二氧化碳超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:二氧化碳超压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:二氧化碳超压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[12]++;
			if (smsCount[12] >= 3)
			{
				smsCount[12] = 3;
				countTime[12] = COUNT_TIME_LATE;
			}
		}
	}

	if (1 == HAL_GPIO_ReadPin(co2Low_in_GPIO_Port, co2Low_in_Pin))		//IO 是高电平 对应没有报警状态  
	{
		lowLevelCount[13] = COUNT_TIME_START-3;
		highLevelCount[13]++;
		if (highLevelCount[13] > 200)
		{
			highLevelCount[13] = 200;
		}
		if (highLevelCount[13] == 10) {

			printf("13600501179:0:二氧化碳欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:二氧化碳欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:二氧化碳欠压恢复正常\n");
			osDelay(INTERVAL_TIME);
			smsCount[13] = 0;
			countTime[13] = COUNT_TIME_START;
		}
	}
	else {
		highLevelCount[13] = 0;
		lowLevelCount[13]++;
		if (lowLevelCount[13] > countTime[13]) {
			lowLevelCount[13] = 0;

			printf("13600501179:0:二氧化碳欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("13676607685:0:二氧化碳欠压报警\n");
			osDelay(INTERVAL_TIME);
			printf("15869068007:0:二氧化碳欠压报警\n");
			osDelay(INTERVAL_TIME);
			smsCount[13]++;
			if (smsCount[13] >= 3)
			{
				smsCount[13] = 3;
				countTime[13] = COUNT_TIME_LATE;
			}
		}
	}
}


