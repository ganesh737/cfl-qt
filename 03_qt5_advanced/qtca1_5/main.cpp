#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QThreadPool>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main");
    QThreadPool* pool = QThreadPool::globalInstance();

    qInfo() << pool->maxThreadCount() << " threads";

    for(int i = 0; i < 5; i++) {
        counter* c = new counter;
        c->setAutoDelete(true);

        pool->start(c);
    }

    return a.exec();
}
