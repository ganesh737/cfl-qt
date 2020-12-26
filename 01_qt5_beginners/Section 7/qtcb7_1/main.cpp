#include <QCoreApplication>

#include <QDebug>

void test () {
    qInfo() << "test";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();

    return a.exec();
}
