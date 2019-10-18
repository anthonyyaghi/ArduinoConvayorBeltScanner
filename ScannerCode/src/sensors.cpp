#include <hcsr04.h>
#include "Properties.h"
#include "sensors.h"

void idToAddress(int id, int* add) {
  int i = 0;
  int s = ceil(log(id)/log(2));
  if (s > 5)
  {
    return;
  }
  while (id != 0)
  {
    add[i] = id % 2;
    id = id >> 1;
    i++;
  }
}

HCSR04 active_sensor(TRIG_PIN, ECHO_PIN, MIN_DIST, MAX_DIST);

double readActiveSensor()
{
    double cum_dist = 0.0;
    for (int i = 0; i < 20; i++)
    {
        cum_dist += active_sensor.distanceInMillimeters();
    }
    return cum_dist/20.0;
}

void activate_sensor(int sensor_index)
{
    int add[] = {0, 0, 0, 0, 0};
    idToAddress(sensor_index, add);

    for (int i = 0; i < ADD_SIZE; i++)
    {
        digitalWrite(ADD_PINS[i], add[i]);
    }
}

double readDistance(int sensor_index) 
{
    activate_sensor(sensor_index);
    return readActiveSensor();
}