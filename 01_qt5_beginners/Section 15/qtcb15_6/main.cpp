#include <QCoreApplication>
#include <QDebug>
#include <QVariant>

void test(QVariant val)
{
    qInfo() << "val=" << val;

    int test = 0;
    bool ok = false;

    test = val.toInt(&ok);
    if(ok) {
        qInfo() << "int =" << test;
    } else {
        qInfo() << "Not a number!";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariant val1 = 1;
    QVariant val2 = "hello, world!!!";

    test(val1);
    test(val2);

    return a.exec();
}
