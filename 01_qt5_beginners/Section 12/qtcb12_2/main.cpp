#include <QCoreApplication>
#include <QDebug>

#include "feline.h"
#include "car.h"
#include "racecar.h"

//Dynamic cast

//dynamic_cast can be used only with pointers and references to objects.
//Its purpose is to ensure that the result of the type conversion is a valid complete object of the requested class.

void testDrive(car* obj)
{
    obj->drive();
    obj->stop();
}

void race(racecar* obj)
{
    obj->goFast();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    racecar* player1 = new racecar(&a);
    testDrive(player1); // its converted automatically/implicitly from racecar to car

    // the correct way to cast
    car* obj = dynamic_cast<car*>(player1);
    if (obj)
    {
        testDrive(obj);
    }

    // error
    // feline* cat = dynamic_cast<racecar*>(player1);

    return a.exec();
}
