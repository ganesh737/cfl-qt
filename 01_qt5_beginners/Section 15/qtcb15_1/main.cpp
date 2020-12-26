#include <QCoreApplication>
#include <QDebug>
#include "cat.h"
#include "dog.h"

void test(QObject* obj)
{
    qInfo() << obj;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cat kitty;
    dog fido;

    kitty.setObjectName("Fluffy!");
    fido.setObjectName("Doggy");

    test(&kitty);
    test(&fido);

    return a.exec();
}
