#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age = 44; // can change
    const int id = 215; // cannot change

    // error since value of id cannot be changed
    id = 1122;
    qInf() << "id:" << id;

    return a.exec();
}
