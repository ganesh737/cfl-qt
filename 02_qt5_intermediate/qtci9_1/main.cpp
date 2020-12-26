#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QtAlgorithms>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<test*> list;
    for(int i = 0; i < 10; i++){
        test* t = new test();
        t->setObjectName(QString::number(i));
        list.append(t);
    }

    qInfo() << list.at(0);

    // delete all of them
    // Note: It does not clear the list so we need to do that seperately
    qDeleteAll(list);

    // objects are still valid when we clear leaving behind dangling pointers
    list.clear();
    return a.exec();
}
