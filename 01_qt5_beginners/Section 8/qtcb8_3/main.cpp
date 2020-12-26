#include <QCoreApplication>

//#include "animal.h"
#include "feline.h"
#include "canine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    animal test;

    feline kitty;

    canine puppy;

    return a.exec();
}
