#include "draw.h"

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}

void Draw::mousePressEvent(QMouseEvent *e)
{
    //Get coordinates od the mouse
    int x = e->x();
    int y = e->y();

    //Create new point
    QPoint p(x,y);

    //Add point to the list
    points.push_back(p);

    repaint();
}

void Draw::paintEvent(QPaintEvent *e)
{
    QPainter qp(this);
    qp.begin(this);

    //Draw all points
    for (int i = 0; i < points.size(); i++)
    {
        qp.drawEllipse(points[i].x(),points[i].y(),10,10);
    }

    qp.end();
}

void Draw::clearPoints()
{
      points.clear();
      repaint();
}
