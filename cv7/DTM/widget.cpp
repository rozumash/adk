#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    z_min = 0;
    z_max = 1000;
    dz = 10;

    //Set initial values
    ui->lineEdit->setText(QString::number(z_min));
    ui->lineEdit_2->setText(QString::number(z_max));
    ui->lineEdit_3->setText(QString::number(dz));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->Canvas->clearDT();

    //Construct DT
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

void Widget::on_pushButton_4_clicked()
{
    ui->Canvas->clearDT();

    //Construct DT
    std::vector<QPoint3D> points=ui->Canvas->getPoints();
    std::vector<Edge> dt = Algorithms::DT(points);
    ui->Canvas->setDt(dt);

    //Create contour lines
    std::vector<Edge> contours = Algorithms::createContourLines(dt, z_min, z_max, dz);
    ui->Canvas->setContours(contours);

    repaint();
}

void Widget::on_lineEdit_editingFinished()
{
    //Set z_min
    z_min = ui->lineEdit->text().toDouble();
}

void Widget::on_lineEdit_2_editingFinished()
{
    //Set z_max
    z_max = ui->lineEdit_2->text().toDouble();
}

void Widget::on_lineEdit_3_editingFinished()
{
    //Set dz
    dz = ui->lineEdit_3->text().toDouble();
}
