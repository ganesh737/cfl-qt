#include "worker.h"

Worker::Worker(QObject *parent, Counter *ctr, QMutex *mutex) : QObject(parent), QRunnable()
{
    this->ctr = ctr;
    this->mutex = mutex;
}

void Worker::run() {
    if(!ctr) return;

    qInfo() << this << " Starting";

    for (int i = 0; i < 100; i++ ) {

        QMutexLocker locker(mutex);
        ctr->increment();
        qInfo() << this << " count: " << ctr->count();
        ctr->decrement();
        qInfo() << this << " count: " << ctr->count();
    }

    qInfo() << this << " Finished";
}
