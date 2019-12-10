#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include "types.h"

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
    ui->Canvas->changePolygon();
}

void Widget::on_pushButton_2_clicked()
{
    std::vector<QPointFB> polA = ui->Canvas->getA();
    std::vector<QPointFB> polB = ui->Canvas->getB();
    std::vector<Edge> res = Algorithms::booleanOperations(polA, polB, Union);
    ui->Canvas->setRes(res);
    repaint();


}
