#ifndef __SMS_ALARM_
#define __SMS_ALARM_

#include "main.h"

#define COUNT_TIME_START 60		//ǰ���η����ż��ʱ��
#define COUNT_TIME_LATE 3600		//����֮�󷢶��ż��ʱ��


extern uint16_t highLevelCount[];
extern uint16_t countTime[];

void alarmScan();
#endif // !__SMS_ALARM_
