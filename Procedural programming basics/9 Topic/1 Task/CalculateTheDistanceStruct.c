#include <stdio.h>
#include <math.h>

typedef struct Point {
double x;
double y;
} Point;

double distanceCalculator(Point p1, Point p2);

void printPoint(Point p);

Point createPoint(double x, double y);

double getDistance(Point a, Point b);



int main() {



    printf("The distance is: %lf", getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0)));




return 0;
}

double distanceCalculator(Point p1, Point p2) {

    double xSkirtumas = p2.x - p1.x;
    double ySkirtumas = p2.y - p1.y;

    return sqrt(xSkirtumas * xSkirtumas + ySkirtumas * ySkirtumas);
}


void printPoint(Point p){
    printf("The coordinates are (x: %lf; y: %lf)\n",p.x, p.y);
}

Point createPoint(double x, double y) {

Point p;
p.x = x;
p.y = y;

return p;
}

double getDistance(Point a, Point b) {

    double xSkirtumas = a.x - b.x;
    double ySkirtumas = a.y - b.y;

    return sqrt(xSkirtumas * xSkirtumas + ySkirtumas * ySkirtumas);

}
