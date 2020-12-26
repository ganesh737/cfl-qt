#include <QCoreApplication>
#include <QDebug>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test<int> intCalc;
    qInfo() << intCalc.add(1, 4);

    test<double> doubleCalc;
    qInfo() << doubleCalc.add(1.3, 4.13132);

    test<QString> strCalc;
    qInfo() << strCalc.add("hello ", "world");

    return a.exec();
}
