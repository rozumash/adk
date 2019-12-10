#include "draw.h"
#include "qpointfb.h"
#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    ab = true;
}

void Draw::mousePressEvent(QMouseEvent *event)
{
     QPointFB q(event->x(), event->y());

     //Add to A
     if(ab)
         a.push_back(q);

     //Add to B
     else
         b.push_back(q);

     repaint();
}

void Draw::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.begin(this);

    //Draw A
    QPen polA(Qt::green);
    painter.setPen(polA);
    drawPolygon(painter, a);

    //Draw B
    QPen polB(Qt::blue);
    painter.setPen(polB);
    drawPolygon(painter, b);

    //Draw edges
    QPen polE(Qt::red);
    painter.setPen(polE);
    for(int i = 0; i < res.size(); i++)
    {
        painter.drawLine(res[i].getStart(), res[i].getEnd());
    }

    painter.end();
}

void Draw::drawPolygon(QPainter &painter, std::vector<QPointFB> &polygon)
{
    //Draw polygon
    QPolygon polyg;
    for(int i = 0; i < polygon.size(); i++)
    {
        int x = polygon[i].x();
        int y = polygon[i].y();
        polyg.append(QPoint (x, y));
    }

    painter.drawPolygon(polyg);
}
