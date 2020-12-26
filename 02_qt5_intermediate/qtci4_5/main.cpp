#include <QCoreApplication>
#include <QIODevice>
#include <QDir>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>

bool put(QString path, QByteArray data, QIODevice::OpenMode mode) {
    QFile file(path);

    if(!file.open(mode)) {
        qWarning() << file.errorString();
        return false;
    }

    qint64 bytes = file.write(data);
    if(bytes == 0) {
        qWarning() << file.errorString();
    }
    else {
        qInfo() << "Wrote" << bytes << "bytes to file";
    }

    file.flush();
    file.close();

    return true;
}

void write(QString path, QByteArray data) {
    qInfo() << "Write to file";
    if(put(path, data, QIODevice::WriteOnly)) {
        qInfo() << "Data written to file";
    }
    else {
        qInfo() << "Failed to write to file";
    }
}

void append(QString path, QByteArray data) {
    qInfo() << "Append to file";
    if(put(path, data, QIODevice::Append)) {
        qInfo() << "Data written to file";
    }
    else {
        qInfo() << "Failed to write to file";
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    qInfo() << "path:" << path;

    QByteArray data("Hello World\r\n");

    for(int i = 0; i < 5; i++) {
        QString num = QString::number(i);
        num.append(" ");

        QByteArray line(num.toLatin1() + data);
        // write(path, line);
        append(path, line);
    }

    return a.exec();
}
