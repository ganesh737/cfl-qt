#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include <QThread>

// add QT += concurrent in the project file

int do_map(int value)
{
    qInfo() << "Do stuff: " << value << QThread::currentThread();
    int num = value * 10;
    return num;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> values;
    for (int i = 0;i < 9; i++)
    {
        values << i;
    }

    qInfo() << "Starting blocked";
    QList<int> updated = QtConcurrent::blockingMapped(values,&do_map);

    qInfo() << updated;
    qInfo() << "Finished";

    return a.exec();
}
