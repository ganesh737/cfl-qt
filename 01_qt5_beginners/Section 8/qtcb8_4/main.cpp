#include <QCoreApplication>
#include <QDebug>
#include "appliance.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    appliance kitchen5000;
    qInfo() << "Can it cook:" << kitchen5000.cook();
    qInfo() << "Can it grill:" << kitchen5000.grill();
    qInfo() << "Can it freeze:" << kitchen5000.freeze();

    return a.exec();
}
