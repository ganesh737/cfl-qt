#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include "test.h"
#include "converter.h"

void writeJson(QString path) {
    test t;
    t.fill();
    converter::writeJson(&t, path);
}

void readJson(QString path) {
    test *t;
    t = converter::readJson(path);

    if(!t) {
        qInfo() << "Object not loaded!";
        return;
    }

    qInfo() << "Name:" << t->name();
    foreach(QString key, t->map().keys()) {
        qInfo() << key << " : " << t->map().value(key);
    }
}

void writeXml(QString path) {
    test t;
    t.fill();
    converter::writeXml(&t, path);
}

void readXml(QString path) {
    test* t;
    t = converter::readXml(path);

    if(!t) {
        qInfo() << "Object not loaded";
        return;
    }

    qInfo() << "Name: " << t->name();
    foreach(QString key, t->map().keys()) {
        qInfo() << key << " : " << t->map().value(key);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString jsonpath = QDir::currentPath() + QDir::separator() + "test.json";
    QString xmlpath = QDir::currentPath() + QDir::separator() + "test.xml";

    writeJson(jsonpath);
    readJson(jsonpath);

    writeXml(xmlpath);
    readXml(xmlpath);

    return a.exec();
}
