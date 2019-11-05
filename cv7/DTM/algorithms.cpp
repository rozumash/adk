#include "algorithms.h"

Algorithms::Algorithms()
{

}

int Algorithms::getPointLinePosition(QPoint3D &q,QPoint3D &p1,QPoint3D &p2)
{
//Analyze point and line position
//1 point in the left half plane
//0 point in the right half plane
//-1 point on the line
double ux = p2.x() - p1.x();
double uy = p2.y() - p1.y();

double vx = q.x() - p1.x();
double vy = q.y() - p1.y();

double t = ux * vy - uy * vx;

//Point in the left half plane
if (t>0)
    return 1;
if (t<0)
    return 0;
return -1;
}

double Algorithms::getCircleRadius(QPoint3D &p1, QPoint3D &p2, QPoint3D &p3){

    //Return radius of the circle given by 3 points
    double x1 = p1.x();
    double y1 = p1.y();

    double x2 = p2.x();
    double y2 = p2.y();

    double x3 = p3.x();
    double y3 = p3.y();

    //Calculate coeficients k1-k12
    double k1 = x1*x1 + y1*y1;
    double k2 = x2*x2 + y2*y2;
    double k3 = x3*x3 + y3*y3;
    double k4 = y1 - y2;
    double k5 = y1 - y3;
    double k6 = y2 - y3;
    double k7 = x1 - x2;
    double k8 = x1 - x3;
    double k9 = x2 - x3;
    double k10 = x1 * x1;
    double k11 = x2 * x2;
    double k12 = x3 * x3;

    //Midpoint of the circle
    double m_numerator = k12 * (-k4) + k11 * k5 - (k10 + k4*k5)*k6;
    double m_denominator = x3*(-k4)+x2*k5+x1*(-k6);
    double m = 0.5 * m_numerator / m_denominator;

    double n_numerator = k1 * (-k9) + k2 * k8 + k3 * (-k7);
    double n_denominator = y1*(-k9) + y2 * k8 + y3 * (-k7);
    double n = 0.5 * n_numerator / n_denominator;

    //Radius of the circle
    return sqrt((x1-m)*(x1-m)+(y1-n)*(y1-n));
}
