#include "LoraDriver.h"

void print_message(lora_payload_t* lora_payload) {
	printf("/----------------------------------------------/\n");
	printf("\tLora sends bytes: {");
	for (uint8_t i = 0; i < LORA_PAYLOAD_LENGTH; i++)
	{
		printf("%d", lora_payload->bytes[i]);
		if (i != LORA_PAYLOAD_LENGTH - 1) {
			printf(",");
		}
	}
	printf("}\n");
	printf("/----------------------------------------------/\n");
}

void send_upload_message(task_lora_data_container_t* task_lora_data_container) {
	while (1) {
		//Read the bit responsible for LoRa to check if data is already collected and ready for the printout
		uint32_t loraBitResponse = xEventGroupWaitBits(task_lora_data_container->event_group, task_lora_data_container->bit_for_lora, pdTRUE, pdTRUE, EVENT_GROUP_WAITING_TIME);
		if (loraBitResponse == task_lora_data_container->bit_for_lora) {
			if (xSemaphoreTake(task_lora_data_container->semaphore, portMAX_DELAY)) {
				print_message(&(task_lora_data_container->message));
				xSemaphoreGive(task_lora_data_container->semaphore);
			}
		}
	}
}