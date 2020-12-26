#include <QCoreApplication>

#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "hello" << std::endl;
    qInfo() << "hello";

    int age = 30;
    std::cout << age;
    std::cout << std::endl;
    std::cout << std::flush;

    return a.exec();
}
