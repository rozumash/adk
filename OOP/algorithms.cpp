#include "algorithms.h"
#include <cmath>

Algorithms::Algorithms()
{

}

double Algorithms::getDistance(Point &p1, Point &p2)
{
    double dx = p2.getX()-p1.getX();
    double dy = p2.getY()-p1.getY();

    return sqrt(dx * dx + dy * dy);
}
