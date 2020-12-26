#include <QCoreApplication>

#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age;

    qInfo() << "Please enter your age:";
    std::cin >> age;
    qInfo() << "You entered:" << age;

    return a.exec();
}
