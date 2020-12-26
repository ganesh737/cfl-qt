#include "dog.h"

Dog::Dog(QObject *parent) : QObject(parent)
{
    qInfo() << "ctor";
}

void Dog::initTestCase()
{
    qInfo() << "initTestCase";
}

void Dog::init()
{
    qInfo() << "init";
}

void Dog::cleanupTestCase()
{
    qInfo() << "cleanupTestCase";
}

void Dog::cleanup()
{
    qInfo() << "cleanup";
}

void Dog::bark()
{
    qInfo() << "bark";
}

void Dog::roll()
{
    qInfo() << "roll";
}
