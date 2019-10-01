#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <QWidget>
#include <QtGui>

class Draw : public QWidget
{
    Q_OBJECT

private:
    bool draw_mode;
    std::vector<QPoint> points;
    QPoint q;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void clearPoints();
    void setDrawMode(){draw_mode = !draw_mode;}



signals:

public slots:
};

#endif // DRAW_H
