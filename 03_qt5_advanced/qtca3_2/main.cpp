#include <QCoreApplication>
#include "mylib_global.h"
#include "mylib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mylib test;
    test.test();

    return a.exec();
}
