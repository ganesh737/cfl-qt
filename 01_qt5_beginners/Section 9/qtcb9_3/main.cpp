#include <QCoreApplication>
#include <QDebug>

// global scope - BAD: DO NOT USE!!!
static QString name = "ganesh";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    name = "bob";
    qInfo() << name;

    bool test = true;
    if (test) {
        QString name = "ashwini";
        qInfo() << name;
    }

    qInfo() << name;

    return a.exec();
}
