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
    QPolygon ch;
    std::vector<QPoint> points = ui->Canvas->getPoints();

    //Create CH
    if (ui->comboBox->currentIndex() == 0)
        ch = Algorithms::jarvisScan(points);
    else
        ch = Algorithms::qHull(points);

    //Draw
    ui->Canvas->setCH(ch);
    repaint();
}
