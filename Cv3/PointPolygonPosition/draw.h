#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <QWidget>
#include <QtGui>

class Draw : public QWidget
{
    Q_OBJECT
private:
    boolean draw_mode;  //true = polygon, false = point
    std::vector <QPoint> polygon;
    QPoint q;

public:
    explicit Draw(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void changeMode(){draw_mode = !draw_mode;}


};

#endif // DRAW_H
