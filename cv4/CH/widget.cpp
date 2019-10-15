#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //Create convex hull
    std::vector<QPoint> points = ui->Canvas->getPoints();
    std::vector<QPoint> ch = Algorithms::jarvisScan(points);
    ui->Canvas->setCH(ch);
    repaint();
}
