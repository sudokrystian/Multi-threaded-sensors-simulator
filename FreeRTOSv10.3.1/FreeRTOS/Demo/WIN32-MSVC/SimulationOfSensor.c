#include "SimulationOfSensor.h"

//Task for sensor simulation
void simulationOfSensorTask(task_sensor_data_container_t* task_sensor_data_container) {
	while (1) {
		//Delays task by custom value specified in CustomConfig.h
		vTaskDelay(task_sensor_data_container->frequency);
		//Performs measurement in the sensor and saves the data in it
		sensor_measure(task_sensor_data_container->sensor);
		//Sets a bit assigned to the sensor to inform about successful operation
		xEventGroupSetBits(task_sensor_data_container->event_group, task_sensor_data_container->bit_for_sensor);
	}
}
