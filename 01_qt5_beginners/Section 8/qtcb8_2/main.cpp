#include <QCoreApplication>

#include "laptop.h"

void test(laptop &machine) {
    //By value would attempt to make a copy!!!
    machine.test();
}

void makeLaptops(QObject* parent) {
    laptop mine(parent,"my laptop");
    laptop yours(parent, "your laptop");

    mine.weight = 3;
    yours.weight = 5;

    test(mine);
    test(yours);

    //Stack will delete variables here
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    makeLaptops(&a);


    return a.exec();
}
