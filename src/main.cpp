#include <Arduino.h>
#include "Properties.h"
#include "Utils.h"

Point emptyBelt[SENSOR_COUNT];
double volume = 0.;

void setup() {
  scanBelt(emptyBelt, 2, 2);
  Serial.begin(9600);
}

void loop() {
  Point scanRes[SENSOR_COUNT];
  scanBelt(scanRes, 1, 1);
  volume += calculateArea(scanRes, emptyBelt) * getDeltaD();
  Serial.print("Volume: ");
  Serial.println(volume);
  delay(1000);
}