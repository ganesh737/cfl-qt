#include "worker.h"

worker::worker(QObject *parent, QStringList *data, QSemaphore *sem, int position) : QObject(parent)
{
    this->data = data;
    this->sem = sem;
    this->position = position;
}

void worker::run()
{
    if(!data || !sem) {
        qInfo() << "Missing pointers!";
        return;
    }

    QString t;
    t.sprintf("%08p", QThread::currentThread());
    sem->acquire(1);
    data->replace(position, QString::number(position) + "-" + t);
    sem->release();

    qInfo() << t << " Finished " << position;
}
