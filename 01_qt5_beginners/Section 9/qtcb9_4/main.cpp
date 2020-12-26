#include <QCoreApplication>
#include <QDebug>

#include "animal.h"

// Global memory
QString animal::name = "";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    animal cat(&a, "kitty");
    animal dog(&a, "fido");
    animal person(&a, "brian");

    // the variable got overwritten so all below will print 'brian'
    qInfo() << "Cat name is" << cat.name;
    qInfo() << "Dog name is" << dog.name;
    qInfo() << "Person name is" << person.name;

    return a.exec();
}
