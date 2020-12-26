#include <QCoreApplication>

#include <iostream>
#include <QDebug>
#include <array>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int max = 0;
    qInfo() << "Enter a max";
    std::cin >> max;

    if (max <= 0)
        qFatal("Please enter a valid number");

    for (int i = 0; i < max; i++) {
        qInfo() << "FOR=" << i;
    }

    std::array<int, 4> ages = {10, 22, 13, 7};
    for (int i = 0; i < ages.size(); i++) {
        qInfo() << "ages[" << i << "]=" << ages.at(i);
    }

    qInfo() << "Finished";

    return a.exec();
}
