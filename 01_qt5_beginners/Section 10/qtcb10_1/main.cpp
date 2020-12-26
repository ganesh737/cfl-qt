#include <QCoreApplication>
#include <QDebug>

void test(QString name) {
    qInfo() << "Size=" << name.length();
}

void testPtr(QString *name) {
    qInfo() << "Size=" << name->length();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name = "ashwini";
    test(name);

    testPtr(&name);

    return a.exec();

    // destructors are called here
}
