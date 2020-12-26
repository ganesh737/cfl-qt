#include "animal.h"

animal::animal(QObject *parent) : QObject(parent)
{
    qInfo() << "animal ctor";
}

animal::~animal()
{
    qInfo() << "animal dtor";

}
