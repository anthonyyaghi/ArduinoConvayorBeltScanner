#include <hcsr04.h>
#include "Properties.h"
#include "sensors.h"

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
    
}

double readDistance(int sensor_index) 
{
    activate_sensor(sensor_index);
    return readActiveSensor();
}