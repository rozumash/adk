#include "algorithms.h"
#include <cmath>
#include "sortbyy.h"

Algorithms::Algorithms()
{

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

std::vector<QPoint> Algorithms::jarvisScan(std::vector<QPoint> &points)
{
    //Convex hull
    std::vector<QPoint> ch;

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
