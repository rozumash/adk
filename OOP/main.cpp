//#include <QCoreApplication>

#include "point.h"
#include "algorithms.h"

int main(int argc, char *argv[])
{
    //Implicitni konstruktor
    Point p1;
    p1.print();
    Point p2;
    p2.print();

    //Parametricky konstruktor
    Point p3(15,10);
    p3.print();
    Point p4(1,1);
    p4.print();

    //Gettery a settery
    double x = p4.getX();
    std::cout << "x=" <<x ;
    p4.setX(46465);
    p4.print();

    //Komunikace objektu prostrednictvim objektu
    p4.setX(p3.getX());

    double x3 = p3.getX();
    p4.setX(3);

    //Predavani objektu jako parametru funkci
    Algorithms a;
    double d = a.getDistance(p3, p4);

    p1.print();
    p2.print();

    //Metoda tridy (staticka funkce)
    int n = Point::getCount();

    return 0;
}
