#include <QCoreApplication>
#include <QMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QMap<QString, int> ages;
    ages.insert("ashwini", 26);
    ages.insert("ganesh", 29);
    ages.insert("ashuu", 25);
    ages.insert("rango", 40);

    qInfo() << "Ashwini is " << ages["ashwini"] << "years old";
    qInfo() << "Keys: " << ages.keys();

    foreach(QString key, ages.keys()) {
        qInfo() << key << " = " << ages[key];
    }

    return a.exec();
}
