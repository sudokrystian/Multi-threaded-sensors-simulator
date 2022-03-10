#include <stdlib.h>
#include "Sensor.h"

typedef struct Sensor1 {
	uint8_t data;
} sensor;
//Memory is allocated and pointer to the sensor is returned
sensor_t sensor_create(void) {
	sensor_t newSensor = (sensor_t)calloc(sizeof(sensor), 1);
	if (newSensor == NULL) {
		return NULL;
	}
	newSensor->data = 0;
	return newSensor;
}
//Sensor is destroyed and memory is freed
void sensor_destroy(sensor_t self) {
	free(self);
}
//Sensor updates its data in the memory
void sensor_measure(sensor_t self) {
	self->data = rand() % 255 + 1;
}
//Gets data from the sensor
uint8_t sensor_getData(sensor_t self) {
	return self->data;
}


