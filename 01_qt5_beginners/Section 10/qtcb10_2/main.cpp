#include <QCoreApplication>
#include <QDebug>

void display (QString* value) {
    qInfo() << "This pointer:" << value;
    qInfo() << "The object:" << &value << " a copy of the pointer";
    qInfo() << "The data:" << *value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name="ashwini";
    display(&name);

    QString* desc = new QString("hello, world!!!");
    display(desc);

    delete desc;

    return a.exec();
}
