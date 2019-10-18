#include "Utils.h"
#include "Arduino.h"
#include "sensors.h"

double getLineLength(Point A, Point B)
{
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

double getQuadrilateralArea(Point A, Point B, Point C, Point D)
{
    //  D           C
    //  X-----------X
    //  /           /
    //  /           /
    //  /           /
    //  X-----------X
    //  A           B

    double a = getLineLength(A, B);
    double b = getLineLength(B, C);
    double c = getLineLength(C, D);
    double d = getLineLength(D, A);
    double p = getLineLength(D, B);
    double q = getLineLength(A, C);

    return 0.25 * sqrt((4.0 * pow(p,2) * pow(q,2)) - pow((pow(b,2) + pow(d,2) - pow(a,2) - pow(c,2)),2));
}

void scanBelt(Point* points, int min, int max)
{
    for(int i = 0; i < SENSOR_COUNT; i++)
    {
        points[i].y = readDistance(i);
    }
}

void initBelt(Point* points, int min, int max)
{
    for(int i = 0; i < SENSOR_COUNT; i++)
    {
        points[i] = Point{(i * SENSOR_SPACING), readDistance(i)};
    }
}

double calculateArea(Point* const scanRes, Point* const emptyBelt)
{
    double area = 0.;

    for(int i = 0; i < SENSOR_COUNT - 1; i++)
    {
        area += getQuadrilateralArea(emptyBelt[i], emptyBelt[i + 1], scanRes[i + 1], scanRes[i]);
    }

    return area;
}

double getDeltaD()
{
    return 10.;
}