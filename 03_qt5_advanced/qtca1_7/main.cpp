#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include <QMutexLocker>
#include "counter.h"
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter ctr;
    QMutex mutex(QMutex::Recursive);
    QThreadPool* pool = QThreadPool::globalInstance();

    qInfo() << "count: " << ctr.count();

    for(int i = 0; i < pool->maxThreadCount(); i++) {
        // Worker* wrk = new Worker(&a, &ctr, &mutex);
        Worker* wrk = new Worker(nullptr, &ctr, &mutex);
        wrk->setAutoDelete(true);
        pool->start(wrk);
    }

    pool->waitForDone();

    qInfo() << "Done, count is " << ctr.count();

    return a.exec();
}
