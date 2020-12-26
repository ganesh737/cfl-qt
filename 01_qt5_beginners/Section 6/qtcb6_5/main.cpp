#include <QCoreApplication>

#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int start = 0;
    int max = 10;

    int i = start;
    while (i < max) {
        qInfo() << "WHILE=" << i;
        i++;
    }

    qInfo("");
    i = start;
    do {
        qInfo() << "DO=" << i;
        i++;
    } while (i < max);

    qInfo("Finished");

    return a.exec();
}
