#include <QCoreApplication>
#include <QDebug>

#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test* parent = new test(&a);

    parent->dog = new animal(parent);

    delete parent;

    return a.exec();
}
