#include <QCoreApplication>
#include <QDebug>

// pass by value
void testVal(int x) {
    x = x * 10;
    qInfo() << "testVal:i=" << x;
}

// pass by reference
void testRef(int &x) {
    x = x * 10;
    qInfo() << "testVal:i=" << x;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x = 3;
    qInfo() << "testVal:x=" << x;
    testVal(x);
    qInfo() << "testVal:x=" << x;
    testRef(x);
    qInfo() << "testVal:x=" << x;

    return a.exec();
}
