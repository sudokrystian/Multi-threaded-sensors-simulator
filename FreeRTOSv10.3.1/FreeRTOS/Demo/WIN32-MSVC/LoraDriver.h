#pragma once

#include <stdio.h>
#include <stdint.h>
#include "CustomConfig.h"
#include "LoraPayload.h"
#include "DataLora.h"

//Simulates sending message by printing out package to the console
void print_message(lora_payload_t* lora_payload);
//Task for LoRa Simulator
void send_upload_message(task_lora_data_container_t* task_lora_data_container);