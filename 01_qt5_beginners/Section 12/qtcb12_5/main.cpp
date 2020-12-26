#include <QCoreApplication>
#include <QDebug>
#include "car.h"
#include "racecar.h"
#include "dog.h"

//QObject cast does not use the C++ RTTI, only used on QObjects

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Derived to base
    racecar* player1 = new racecar(&a);
    car* mycar = qobject_cast<car*>(player1);
    mycar->drive();

    //Base to derived
    racecar* fastcar = qobject_cast<racecar*>(mycar);
    fastcar->goFast();

    //will not use non-qt objects!!!!
    dog* fido = qobject_cast<dog*>(fastcar);
    Q_UNUSED(fido);

    return a.exec();
}
