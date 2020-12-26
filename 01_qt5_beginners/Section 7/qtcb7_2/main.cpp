#include <QCoreApplication>

#include <QDebug>
#include <iostream>

int calc(int offset, int age) {
    return offset * age;
}

int catYears(int age) {
    return calc(9, age);
}

int dogYears(int age) {
    return calc(7, age);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age;
    qInfo() << "enter your age:";
    std::cin >> age;

    qInfo() << "cat years=" << catYears(age);
    qInfo() << "dog years=" << dogYears(age);

    return a.exec();
}
