#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QtGui>
#include "qpoint3d.h"

class Algorithms
{
public:
    Algorithms();
    static int getPointLinePosition(QPoint3D &q,QPoint3D &p1,QPoint3D &p2);
    static double getCircleRadius(QPoint3D &p1, QPoint3D &p2, QPoint3D &p3);
    //static int getNearestpoint(QPoint3D &p, std::vector)

};

#endif // ALGORITHMS_H
