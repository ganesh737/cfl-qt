#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    num = 0;
    timer.setInterval(1000);
    connect(&timer, &QTimer::timeout, this, &test::timeout);
}

void test::timeout()
{
    num++;
    qInfo() << QTime::currentTime().toString(Qt::DateFormat::SystemLocaleLongDate);
    if(num == 5) {
        timer.stop();
        qInfo() << "Complete!";
    }
}

void test::dostuff()
{
    timer.start();
}
