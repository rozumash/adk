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
    else if(ui->comboBox->currentIndex() == 1)
        ch = Algorithms::qHull(points);
    else
        ch = Algorithms::sweepLine(points);

    //Draw
    ui->Canvas->setCH(ch);
    repaint();
}

void Widget::on_pushButton_2_clicked()
{
    ui->Canvas->clearPoints();
}

void Widget::on_pushButton_3_clicked()
{
    ui->Canvas->clearCH();
}
