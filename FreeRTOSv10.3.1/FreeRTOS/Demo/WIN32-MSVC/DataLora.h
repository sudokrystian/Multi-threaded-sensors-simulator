struct DataLoRa {
	EventGroupHandle_t		event_group;
	SemaphoreHandle_t		semaphore;
	uint8_t					bit_for_lora;
	lora_payload_t			message;
} typedef task_lora_data_container_t;