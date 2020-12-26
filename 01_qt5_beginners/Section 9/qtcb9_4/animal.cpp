#include "animal.h"

animal::animal(QObject *parent, QString name) : QObject(parent)
{
    // error since this-> name is static
//    this->name = name;
    animal::name = name;
    qInfo() << "name changed in " << this << " " << animal::name;
}
