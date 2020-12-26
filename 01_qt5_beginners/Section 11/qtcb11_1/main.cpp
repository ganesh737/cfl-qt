#include <QCoreApplication>
#include "source.h"
#include "destination.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    source objSrc;
    destination objDest;

    QObject::connect(&objSrc, &source::mySignal, &objDest, &destination::onMessage);

    objSrc.test();

    return a.exec();
}
