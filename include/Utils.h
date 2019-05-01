#include <Arduino.h>
#include "Properties.h"

struct Point
{
    double x, y;
};

void scanBelt(Point* points, int min, int max);
double calculateArea(Point* const scanRes, Point* const emptyBelt);
double getDeltaD();