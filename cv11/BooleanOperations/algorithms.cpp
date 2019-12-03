#include "algorithms.h"
#include <cmath>


Algorithms::Algorithms()
{

}

TPointLinePosition Algorithms::getPointLinePosition(QPointFB &q, QPointFB &p1, QPointFB &p2)
{
    //Analyze point and line position
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = q.x() - p1.x();
    double vy = q.y() - p1.y();

    //Determinant test
    double t = ux * vy - uy * vx;

    //Point in the left half plane
    if (t > 0)
        return LeftHp;

    //Point in the right half plane
    if (t < 0)
        return RightHp;

    //Otherwise, colinear point
    return Colinear;
}


double Algorithms::getAngle2Vectors(QPointFB &p1, QPointFB &p2, QPointFB &p3, QPointFB &p4)
{
    //Calculate angle betwen 2 vectors
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();

    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    //Norms
    double nu = sqrt(ux * ux + uy * uy);
    double nv = sqrt(vx * vx + vy * vy);

    //Dot product
    double scalar = ux * vx + uy * vy;

    double angle = fabs(acos(scalar/(nu*nv)));
    return angle;
}


TPointPolygonPosition Algorithms::positionPointPolygonWinding(QPointFB &q, std::vector<QPointFB> &pol)
{
    //Analyze position of the point and the polygon
    double wn = 0.0;

    // Tolerance
    double eps = 1.0e-6;

    // The size of polygon
    int n = pol.size();

    //Process all points of polygon
    for (int i = 0; i < n; i++)
    {
        //Measure angle betweeen two vectors
        double omega = getAngle2Vectors(pol[i], q, pol[(i+1)%n], q);

        // Point on boundary
        if (fabs(fabs(omega) - M_PI) <= eps)
            return On;

        //Get orientation of the point and the polygon edge
        int orient = getPointLinePosition(q, pol[i], pol[(i+1)%n]);

        //Point in the left half plane
        if (orient == LeftHp)
            wn += omega;

        //Point in the right half plane
        else
            wn -= omega;
    }

    //Point inside polygon
    if (fabs(fabs(wn) - 2 * M_PI) <= eps)
        return Inner;

    //Point outside polygon
    return Outer;
}


T2LinesPosition Algorithms::get2LinesPosition(QPointFB &p1, QPointFB &p2, QPointFB &p3, QPointFB &p4, QPointFB &pi)
{
    //Analyze position of two lines
    double eps = 10e-6;

    //Compute vectors
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();
    double wx = p1.x() - p3.x();
    double wy = p1.y() - p3.y();

    //Compute k1-k3
    double k1 = vx * wy - vy * wx;
    double k2 = ux * wy - uy * wx;
    double k3 = ux * vy - uy * vx;

    //Colinear lines
    if ((fabs(k1) < eps) && (fabs(k2) < eps) && (fabs(k3) < eps))
        return Identical;

    //Parallel lines
    if ((fabs(k1) < eps) && (fabs(k2) < eps))
        return Paralel;

    //Compute alpha, beta
    double alpha = k1 / k3;
    double beta = k2 / k3;

    //Intersection exists
    if((alpha >=0) && (alpha <= 1) && (beta >=0) && (beta <= 1))
    {
        //Coordinates of the intersection
        double xpi = p1.x() + alpha * ux;
        double ypi = p1.y() + alpha * uy;

        pi.setX(xpi);
        pi.setY(ypi);
        pi.setAlpha(alpha);
        pi.setBeta(beta);

        return Intersected;
    }

    //Intersection does not exist
    return NonIntersected;
}


std::vector<Edge> booleanOperations(std::vector<QPointFB> &polygonA, std::vector<QPointFB> &polygonB, TBooleanOparation &operation)
{
    //Create polygon overlay
    std::vector<Edge> result;

    return result;
}
