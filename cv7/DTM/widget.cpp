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
    ui->Canvas->clearDT();

    std::vector<QPoint3D> points=ui->Canvas->getPoints();
    std::vector<Edge> dt = Algorithms::DT(points);
    ui->Canvas->setDt(dt);

    repaint();

}

void Widget::on_pushButton_2_clicked()
{
    ui->Canvas->clearPoints();
    repaint();
}

void Widget::on_pushButton_3_clicked()
{
    ui->Canvas->clearPoints();
    ui->Canvas->clearDT();
    repaint();
}
