#include <QCoreApplication>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age;

    qInfo() << "Enter your age:";
    std::cin >> age;
    qInfo() << "you are" << age << "years old";

    qInfo() << "Info";
    qDebug() << "Debug";
    qCritical() << "Critical";

    qFatal("Test Crashed!!!");

    return a.exec();
}
