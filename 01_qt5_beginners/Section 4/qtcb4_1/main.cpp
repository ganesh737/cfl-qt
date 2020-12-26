#include <QCoreApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // variables - something that will change

    bool isOn = false; // can have true or false
    qInfo() << "it is on " << isOn ;
    isOn = true;
    qInfo() << "it is on " << isOn ;

    return a.exec();
}
