#pragma once
#include "LoraDriver.h"
#include "Sensor.h"
#include "TaskController.h"
#include "SimulationOfSensor.h"

#include <conio.h>
#include <time.h>

#include "task.h"
#include "timers.h"


//Call method for creating everything and starts task scheduler
void start_simulation(void);
//Initializes all tasks, sensors, event group and semaphore
void initialize_tasks_and_sensors(void);
