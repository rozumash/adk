#include "algorithms.h"

Algorithms::Algorithms()
{

}

int Algorithms::getPointLinePosition(QPoint &q, QPoint &p1, QPoint &p2)
{
    //Get point and line position
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = q.x() - p1.x();
    double vy = q.y() - p1.y();

    //Determinant
    double t = ux * vy - uy * vx;

    //Point in the left halfplane
    if ( t > 0)
         return 1;

    //Point in the right halfplane
    if (t < 0)
        return 0;

    //Point on the line
    return -1;
}
