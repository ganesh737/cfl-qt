#include "laptop.h"

laptop::laptop(QObject *parent, QString name) : QObject(parent)
{
    // when created
    this->name = name;
    qInfo() << this << name << " constructed";
}

laptop::~laptop()
{
    // when destroyed
    qInfo() << this << name << " deconstructed";
}

double laptop::asKilograms()
{
    return this->weight * 0.45;
}

void laptop::test()
{
    qInfo() << this << name << asKilograms();
}
