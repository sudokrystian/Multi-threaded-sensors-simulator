#pragma once
#include "FreeRTOS.h"
#include "event_groups.h"
#include "semphr.h"

//Length of LoRa package
#define LORA_PAYLOAD_LENGTH (2)

//Delays for sensors (you can safely modify them to change the order of console output)
#define SENSOR1_FREQUENCY				(450)
#define SENSOR2_FREQUENCY				(920)
#define EVENT_GROUP_WAITING_TIME		(400)

//Bits for corresponding sensors
#define BIT_FOR_SENSOR1					(1 << 0);
#define BIT_FOR_SENSOR2					(1 << 1);
#define BIT_FOR_LORA					(1 << 2);
