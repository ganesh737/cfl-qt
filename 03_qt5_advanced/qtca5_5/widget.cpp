#include "widget.h"

Widget::Widget(QObject *parent) : QObject(parent)
{

}

void Widget::testFor()
{
    QVector<int> list;
    list.fill(0, 100);

    // called multiple times
    QBENCHMARK
    {
        for(int i = 0; i < list.size(); i++){
            // do stuff
        }
    }
}

void Widget::testForEach()
{
    QVector<int> list;
    list.fill(0, 100);

    // called multiple times
    QBENCHMARK
    {
        foreach(int value, list){
            // do stuff
        }
    }
}

void Widget::testString()
{
    QString him = "Ganesh";
    QString her = "Ashwini";

    QBENCHMARK
    {
        int ret = him.compare(her);
    }
}

void Widget::testComp()
{
    QString him = "Ganesh";
    QString her = "Ashwini";

    QBENCHMARK
    {
        QCOMPARE(him, her);
    }
}
