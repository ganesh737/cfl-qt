#include <QCoreApplication>
#include <QHash>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<QString, int> ages;
    ages.insert("Ashwini", 26);
    ages.insert("Ganesh", 29);
    ages.insert("Tommy", 33);
    ages.insert("Ashuuu", 23);
    ages.insert("Agasthya", 12);

    qInfo() << "Ashiwni is " << ages["Ashwini"] << " years old";
    qInfo() << "Keys: " << ages.keys();
    qInfo() << "Size: " << ages.size();

    foreach(QString key, ages.keys()) {
        qInfo() << key << " = " << ages[key];
    }

    return a.exec();
}
