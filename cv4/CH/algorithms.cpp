#include "algorithms.h"
#include <cmath>
#include "sortbyy.h"
#include "sortbyx.h"

Algorithms::Algorithms()
{

}

double Algorithms::getPointLineDistance(QPoint &q, QPoint &p1, QPoint &p2){
    //Calculate point and line distance
    double numerator = q.x() * (p1.y() - p2.y()) + p1.x() * (p2.y() - q.y()) + p2.x() * (q.y() - p1.y());
    double dx = p2.x() - p1.x();
    double dy = p2.y() - p1.y();
    double denumenator = sqrt(dx * dx + dy * dy);

    double dist = fabs(numerator)/denumenator;
    return dist;
}

int Algorithms::getPointLinePosition(QPoint &q,QPoint &p1,QPoint &p2)
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

double Algorithms::getAngle2Vectors(QPoint &p1, QPoint &p2, QPoint &p3, QPoint &p4)
{
    // Calculate Vector betwen 2 vectors.
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

QPolygon Algorithms::jarvisScan(std::vector<QPoint> &points)
{
    //Convex hull
    QPolygon ch;

    //Sort points by Y
    std::sort(points.begin(), points.end(), SortbyY());
    QPoint q=points[0];
    QPoint r(q.x()-1,q.y());

    //Initialize points pj, pjj
    QPoint pj = q;
    QPoint pjj = r;

    // Add to CH
    ch.push_back(q);

    // Find points of CH
    do
    {
        double om_max = 0;
        int i_max = -1;

        //Find point of CH
        for(int i = 0; i < points.size(); i++)
        {
            double omega = getAngle2Vectors(pj, pjj, pj, points[i]);

            // Actualize maximum.
            if (omega > om_max)
            {
                om_max = omega;
                i_max = i;
            }
        }

        //Add point to the convex hull
        ch.push_back(points[i_max]);

        //Change index
        pjj = pj;
        pj = points[i_max];

    } while (!(pj == q));

    return ch;

}

QPolygon Algorithms::qHull(std::vector<QPoint> &points)
{
    //Convex Hull by quick hull method
    QPolygon ch;
    std::vector<QPoint> upoints, lpoints;

    // Sort by X.
    std::sort(points.begin(), points.end(), SortbyY());
    QPoint q1 = points[0];
    QPoint q3 = points.back();

    //Add q1, q3 to upoints, lpoints
    upoints.push_back(q1);
    upoints.push_back(q3);

    lpoints.push_back(q1);
    lpoints.push_back(q3);

    // Split to upoints / lpoints
    for(unsigned int i=0; i < points.size();i++){

        //Add to the upper part
        if(getPointLinePosition(points[i], q1, q3) == 1)
            upoints.push_back(points[i]);

        //Add to the lower part
        else if (getPointLinePosition(points[i], q1, q3) == 0)
            lpoints.push_back(points[i]);
    }

    //Call recursive function
    ch.push_back(q3);
    qh(1, 0, upoints, ch);
    ch.push_back(q1);
    qh(0, 1, lpoints, ch);

    return ch;
}

void Algorithms::qh(int s, int e, std::vector<QPoint> &points, QPolygon &ch){

    //Recursive procedure
    int i_max = -1;
    double d_max = 0;

    // Browse all points
    for (int i = 2; i < points.size(); i++)
    {
       // Is the point in the right half plane
        if (getPointLinePosition(points[i], points[s], points[e]) == 0)
        {
            double d = getPointLineDistance(points[i], points[s], points[e]);

            //Actualization of d_max
            if(d > d_max){
                d_max = d;
                i_max = i;
            }
        }
    }

    //Suitable point has been found
    if(i_max != -1)
    {
        qh(s, i_max, points, ch);
        ch.push_back(points[i_max]);
        qh(i_max, e, points, ch);
    }

}
