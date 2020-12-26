#include <QCoreApplication>
#include <QDebug>
#include "test.h"

void pointerTest(QObject *o) {
    qInfo() << o;
}

void referenceTest(QObject &o) {
    qInfo() << &o;
}

void copyTest(QObject o) {
    qInfo() << &o;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test t;
    pointerTest(&t);
    referenceTest(t);
    // copy is not possible since the below macro doesn't allow copy with
    // Q_DISABLE_COPY
    copyTest(t);

    return a.exec();
}
