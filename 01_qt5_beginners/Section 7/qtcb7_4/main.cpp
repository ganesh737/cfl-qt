#include <QCoreApplication>

#include <QDebug>

void test(int age = 0) {
    qInfo() << "age=" << age;
}

void test(bool isActive) {
    qInfo() << "testing";

    if(isActive) {
        qInfo() << "Active";
    }
    else {
        qInfo() << "Inactive";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test(10);
    test(true);
    test(false);
    test();

    return a.exec();
}
