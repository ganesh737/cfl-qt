#include "car.h"

car::car(QObject *parent) : QObject(parent)
{

}

void car::drive()
{
    qInfo() << "drive";
}

void car::stop()
{
    qInfo() << "stop";
}
