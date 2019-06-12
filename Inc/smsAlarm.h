#ifndef __SMS_ALARM_
#define __SMS_ALARM_

#include "main.h"

#define COUNT_TIME_START 60		//前三次发短信间隔时间
#define COUNT_TIME_LATE 3600		//三次之后发短信间隔时间


extern uint16_t highLevelCount[];
extern uint16_t countTime[];

void alarmScan();
#endif // !__SMS_ALARM_
