#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QtGui>


class Algorithms
{
public:
    Algorithms();
    static int getPointLinePosition(QPoint &q,QPoint &p1,QPoint &p2);
    static double getAngle2Vectors(QPoint &p1,QPoint &p2,QPoint &p3,QPoint &p4);
    static std::vector<QPoint> jarvisScan(std::vector<QPoint> &points);
};

#endif // ALGORITHMS_H
