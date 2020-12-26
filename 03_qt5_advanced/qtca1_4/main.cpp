#include <QCoreApplication>
#include <QDebug>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("main");

    manager m;
    m.start();

    return a.exec();
}
