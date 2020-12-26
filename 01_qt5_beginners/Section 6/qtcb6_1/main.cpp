#include <QCoreApplication>
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age = 0;

    qInfo() << "Enter your age:";
    std::cin >> age;

    if (age == 0) {
        qFatal("You did not enter a valid int");
    }

    qInfo() << "You entered:" << age;

    if (age < 18) {
        qInfo() << "You are under age!";
        qInfo() << "Please come back when you are old enough.";
    }

    if ((age < 21) && (age >= 18)) {
        qInfo() << "You are not really an adult yet!";
    }

    if (age >=22) {
        qInfo() << "You are an adult";
    }

    if (age > 128) {
        qCritical() << "You can't be that old!!!";
    }

    qInfo() << "Finished!!!";
    return a.exec();
}
