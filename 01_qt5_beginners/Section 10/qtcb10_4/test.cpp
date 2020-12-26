#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    qInfo() << "test ctor";
}

test::~test()
{
    qInfo() << "test dtor";
}
