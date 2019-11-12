#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>

#include "qpoint3d.h"
#include "edge.h"

class Draw : public QWidget
{
    Q_OBJECT
private:
    std::vector<QPoint3D> points;
    std::vector<Edge> dt;

public:
    explicit Draw(QWidget *parent = nullptr);
    void setPoints(std::vector<QPoint3D> &points_){points=points_;}
    void setDt(std::vector<Edge> &dt_){dt=dt_;}
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    std::vector<QPoint3D> getPoints(){return points;}
    void clearPoints(){points.clear(); }
    void clearDT(){dt.clear();}

signals:

public slots:
};

#endif // DRAW_H
