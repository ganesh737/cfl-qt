#include <QCoreApplication>

#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age;
    qInfo() << "Enter your age:";
    std::cin >> age;

    if (age > 17) {
        qInfo() << "You are over 17 years old!";
    }
    else if (age < 12) {
        qInfo() << "You are not a teenager yet";
    }
    else {
        qInfo() << "You are not over 17!";
    }

    return a.exec();
}
