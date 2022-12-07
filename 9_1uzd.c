#include <stdio.h>
#include <math.h>

typedef struct Point
{
    double x, y;
} Point;

Point createPoint(double x, double y);
double getDistance(Point a, Point b);
void printPoint(Point p);

int main()
{
    printf("%.1f\n", getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0)));
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b)
{
    float distance;
    distance = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    return distance;
}

// Neliko kreipimosi, taciau palikta vardan parodymo, jog buvo naudota
void printPoint(Point p)
{
    printf("(%.1f,%.1f)\n", p.x, p.y);
}