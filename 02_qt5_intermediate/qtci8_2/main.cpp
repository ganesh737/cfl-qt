#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QDir>
#include <QFile>
#include "test.h"

bool saveFile(test* t, QString path) {
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open file for write";
        return false;
    }

    QDataStream ds(&file);
    ds.setVersion(QDataStream::Qt_5_15);
//    ds << t->name();
//    ds << t->map();

    ds << *t;

    file.close();
    return true;
}

bool loadFile(QString path) {
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open file for read";
        return false;
    }

    QDataStream ds(&file);
    test t;
    ds >> t;

    file.close();

    qInfo() << "Name:" << t.name();
    foreach(QString key, t.map().keys()) {
        qInfo() << key << "=" << t.map().value(key);
    }
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file = QDir::currentPath() + QDir::separator() + "test.txt";

    test t;
    t.fill();
    if(saveFile(&t, file)) {
        loadFile(file);
    }
    return a.exec();
}
