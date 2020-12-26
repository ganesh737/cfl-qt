#include "animal.h"

animal::animal(QObject *parent, QString name) : QObject(parent)
{
    this->name = name;
    qInfo() << "Animal name parameter is at" << &name << "=" << name;
    qInfo() << "Animal name :" << &this->name << "=" << this->name;
}

void animal::sayHello(QString message)
{
    qInfo() << message << "from" << &name << "=" << name;
    qInfo() << message << "from" << &this->name << "=" << name;
}
