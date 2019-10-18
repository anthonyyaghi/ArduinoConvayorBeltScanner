#include <Arduino.h>
#include "Properties.h"
#include "Utils.h"

Point emptyBelt[SENSOR_COUNT];
double area = 0.;
Point scanRes[SENSOR_COUNT];

void setup() {
  initBelt(emptyBelt, 2, 2);
  Serial.begin(9600);
}

void loop() {
  scanBelt(scanRes, 1, 1);
  area = calculateArea(scanRes, emptyBelt) * getDeltaD();
  Serial.print("are: ");
  Serial.println(area);
  delay(1000);
}