#include <QCoreApplication>

#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age;
    qInfo() << "Please enter your age:";
    std::cin >> age;

    switch (age) {
    case 0: // if (age == 0)
        qFatal("You did not enter a age");
        break;
    case 16:
        qInfo("You can drive now");
        break;
    case 18:
        qInfo("You can vote now");
        break;
    case 21:
        qInfo("You can drink now");
        break;
    case 67:
        qInfo("You are retiring");
        break;
    default:
        qInfo("Nothing special this year");
        break;
    }

    qInfo("Finished");

    return a.exec();
}
