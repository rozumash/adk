#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "types.h"
#include "qpointfb.h"
#include <vector>
#include "edge.h"

class Algorithms
{
public:
    Algorithms();
    static TPointLinePosition getPointLinePosition(QPointFB &q,QPointFB &p1,QPointFB &p2);
    static double getAngle2Vectors(QPointFB &p1,QPointFB &p2,QPointFB &p3,QPointFB &p4);
    static TPointPolygonPosition positionPointPolygonWinding(QPointFB &q, std::vector<QPointFB> &pol);
    static T2LinesPosition get2LinesPosition(QPointFB &p1, QPointFB &p2, QPointFB &p3, QPointFB &p4, QPointFB &pi);
    std::vector<Edge> booleanOperations(std::vector<QPointFB> &polygonA,std::vector<QPointFB> &polygonB, TBooleanOparation &operation);
};

#endif // ALGORITHMS_H
