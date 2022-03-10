#pragma once

#include <stdio.h>
#include <stdint.h>
#include "CustomConfig.h"
#include "LoraDriver.h"
#include "Sensor.h"

struct DataTaskController {
	EventGroupHandle_t				event_group;
	SemaphoreHandle_t				semaphore;
	sensor_t						sensor1;
	uint8_t							bit_sensor_1;
	sensor_t						sensor2;
	uint8_t							bit_sensor_2;
	task_lora_data_container_t* loraContainer;
} typedef task_controller_data_container_t;