#include <QCoreApplication>
#include <QDebug>
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "File:" << logger::filename;
    logger::attach();

    qInfo() << "Test";

    logger::logging = false;
    qInfo() << "dont log this";

    logger::logging = true;

    qInfo() << "Finished";

    return a.exec();
}
