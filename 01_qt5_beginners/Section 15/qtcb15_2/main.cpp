#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // typedef - remake a type

    qint8 val8 = 0;
    qint16 val16 = 0;
    qint32 val32 = 0;
    qint64 val64 = 0;
    qintptr valPtr = 0;

    qInfo() << "qint8" << sizeof (val8);
    qInfo() << "qint16" << sizeof (val16);
    qInfo() << "qint32" << sizeof (val32);
    qInfo() << "qint64" << sizeof (val64);
    qInfo() << "qintptr" << sizeof (valPtr);

    return a.exec();
}
