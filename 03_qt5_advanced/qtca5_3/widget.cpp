#include "widget.h"

Widget::Widget(QObject *parent) : QObject(parent)
{
    qInfo() << "ctor";
    age = 0;
}

void Widget::setAge(int value)
{
    qInfo() << "setAge";
    age = value;
}

void Widget::testFail()
{
    qInfo() << "testFail";
    QFAIL("NO REASON JUST FAILING!");
}

void Widget::testAge()
{
    qInfo() << "testAge";
    if(!age) {
        QFAIL("Age is not set!");
    }
}

void Widget::testWidget()
{
    qInfo() << "testWidget";
    int value = 45;

    // make sure age is valid
    QVERIFY(age > 0 && age < 100);

    // issue warnings
    if (age > 40) QWARN("Age is over 40!");
    if (age < 21) QFAIL("Must be an adult!");

    // make sure they are the same
    QCOMPARE(age, value);
}
