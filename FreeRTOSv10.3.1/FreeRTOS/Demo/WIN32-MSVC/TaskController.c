#include "TaskController.h"

//Bits for corresponding sensors
const uint8_t task_controller_bit_for_sensor1 = BIT_FOR_SENSOR1;
const uint8_t task_controller_bit_for_sensor2 = BIT_FOR_SENSOR2;
const uint8_t task_controller_bit_for_LoRa = BIT_FOR_LORA;

void taskController(void* taskControllerDataContainer) {
	task_controller_data_container_t* task_controller_data_container = taskControllerDataContainer;
	while (1) {
		//Read bits from both sensors to check
		uint32_t bit_from_sensor_1 = xEventGroupWaitBits(task_controller_data_container->event_group, task_controller_data_container->bit_sensor_1, pdTRUE, pdTRUE, EVENT_GROUP_WAITING_TIME);
		uint32_t bit_from_sensor_2 = xEventGroupWaitBits(task_controller_data_container->event_group, task_controller_data_container->bit_sensor_2, pdTRUE, pdTRUE, EVENT_GROUP_WAITING_TIME);

		//Log a proper information depending on the response
		if (bit_from_sensor_1 != task_controller_bit_for_sensor1) {
			if (xSemaphoreTake(task_controller_data_container->semaphore, portMAX_DELAY)) {
				printf(" Log: Sensor one is still measuring\n");
				xSemaphoreGive(task_controller_data_container->semaphore);
			}
		}
		else {
			if (xSemaphoreTake(task_controller_data_container->semaphore, portMAX_DELAY)) {
				printf(" Log: Sensor one is finished with the measurement and waiting for upload of the data\n");
				xSemaphoreGive(task_controller_data_container->semaphore);
			}
		}
		if (bit_from_sensor_2 != task_controller_bit_for_sensor2) {
			if (xSemaphoreTake(task_controller_data_container->semaphore, portMAX_DELAY)) {
				printf(" Log: Sensor two is still measuring\n");
				xSemaphoreGive(task_controller_data_container->semaphore);
			}
		}
		else {
			if (xSemaphoreTake(task_controller_data_container->semaphore, portMAX_DELAY)) {
				printf(" Log: Sensor two is finished with the measurement and waiting for upload of the data\n");
				xSemaphoreGive(task_controller_data_container->semaphore);
			}
		}

		//If both sensors are ready to send the data set a bit for LoRa to activate
		if ((bit_from_sensor_1 | bit_from_sensor_2) == (unsigned)(task_controller_bit_for_sensor1 | task_controller_bit_for_sensor2)) {
			uint8_t sensor1Data = sensor_getData(task_controller_data_container->sensor1);
			uint8_t sensor2Data = sensor_getData(task_controller_data_container->sensor2);
			//Declaration of data holder for LoRa package
			lora_payload_t messageLora = (lora_payload_t){ LORA_PAYLOAD_LENGTH, {sensor1Data, sensor2Data} };
			task_controller_data_container->loraContainer->message = messageLora;
			xEventGroupSetBits(task_controller_data_container->event_group, task_controller_data_container->loraContainer->bit_for_lora);
		}
	}
}