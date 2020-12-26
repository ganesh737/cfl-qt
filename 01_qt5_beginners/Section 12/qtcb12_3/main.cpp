#include <QCoreApplication>
#include <QDebug>
#include "car.h"
#include "racecar.h"
#include "feline.h"

//Static cast

//The static_cast operator performs a nonpolymorphic cast.
//For example, it can be used to cast a base class pointer into a derived class pointer.

void testDrive(car* obj) {
    obj->drive();
    obj->stop();
}

void race(racecar* obj) {
    obj->goFast();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    racecar* player1 = new racecar(&a);
    testDrive(player1); // we know this works but implicit casting is taking place

    car* gremlin = dynamic_cast<car*>(player1);
    if(gremlin) testDrive(gremlin);

    // up casting - going from the the car to the racecar
    //We can go from the base back to the derived because the classes we created are polymorphic
    //Static cast should work fine - this is the way to go from a base to a derived class saftly!!!!!!
    racecar* speedster = static_cast<racecar*>(gremlin);
    if(speedster) race(speedster);

    return a.exec();
}
