#include <QCoreApplication>
#include <QDebug>
#include "animal.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name = "ganesh";
    qInfo() << "My name is at:" << &name << "=" << name;

    animal cat(&a, "fluffy");
    animal dog(&a, "tommy");
    animal person(&a, name);

    person.sayHello("yo");
    return a.exec();
}
