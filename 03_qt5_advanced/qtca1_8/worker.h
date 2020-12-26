#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QThreadPool>
#include <QRunnable>
#include <QSemaphore>

class worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr,
                    QStringList* data = nullptr,
                    QSemaphore* sem = nullptr,
                    int position = -1);

    void run();

signals:

private:
    QStringList* data;
    QSemaphore* sem;
    int position;
};

#endif // WORKER_H
