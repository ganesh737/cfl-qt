#include <QCoreApplication>
#include <QDebug>
#include <QThreadPool>
#include <QSemaphore>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList data;
    for (int i = 0; i < 100; i++) {
        data.append(QString::number(i));
    }

    QThreadPool* pool = QThreadPool::globalInstance();
    QSemaphore sem(100);

    for (int i = 0; i < data.length(); i++) {
        worker* wrk = new worker(nullptr, &data, &sem, i);
        wrk->setAutoDelete(true);
        pool->start(wrk);
    }

    for(int i = 0; i < data.length(); i++) {
        worker* wrk = new worker(nullptr, &data, &sem, i);
        wrk->setAutoDelete(true);
        pool->start(wrk);
    }

    pool->waitForDone();

    foreach(QString str, data) {
        qInfo() << str;
    }

    return a.exec();
}
