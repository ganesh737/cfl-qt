#include <QCoreApplication>
#include <QSet>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;
    people << "Ashwini" << "Ganesh";
    people.insert("Rango");

    foreach(QString person, people) {
        qInfo() << person;
    }

    // very fast
    qInfo() << "Ashwini in collection" << people.contains("Ashwini");

    return a.exec();
}
