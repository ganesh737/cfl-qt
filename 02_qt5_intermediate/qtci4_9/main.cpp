#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QLockFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Attempting to lock a file";

    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    QFile file(path);

    QLockFile lock(file.fileName() + "l");
    lock.setStaleLockTime(30000);

    if(lock.tryLock()) {
        qInfo() << "Writing to file...";
        if(file.open(QIODevice::WriteOnly)) {
            QByteArray data;
            file.write(data);
            file.close();
            qInfo() << "Finished writing...";
        }
        qInfo() << "Unlocking file";
        lock.unlock();
    }
    else {
        qInfo() << "Could not lock file";
        qint64 pid;
        QString host;
        QString app;

        if(lock.getLockInfo(&pid, &host, &app)) {
            qInfo() << "The file is locked by";
            qInfo() << "pid:" << pid;
            qInfo() << "host:" << host;
            qInfo() << "app:" << app;
        }
        else {
            qInfo() << "Locked by unknown application";
        }
    }

    return a.exec();
}
