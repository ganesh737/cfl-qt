#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include "worker.h"

//QNetworkAccessManager - FTP Example

void upload(Worker* worker)
{
    QString location = "ftp://speedtest.tele2.net/upload/VoidRealms-" + QString::number(QDateTime::currentSecsSinceEpoch()) + ".bin";
    QString path = "/home/ganesh/ws/test.bin"; //Replace this with your file
    worker->upload(location,path);

}

void download(Worker* worker)
{
    QString location = "ftp://speedtest.tele2.net/512KB.zip";
    QString path = "/home/ganesh/ws/test512KB.bin"; //Replace this with your file
    worker->download(location,path);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Worker worker;

    // upload and download does not work together in this code
    // due to synchronization issue for file closure
    //upload(&worker);
    download(&worker);

    return a.exec();
}
