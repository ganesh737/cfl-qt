#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Unicode character string
    QString name = "Ashwini Malivu";

    qInfo() << name;
    qInfo() << name.mid(1,3);
    qInfo() << name.insert(0,"Mrs. ");
    qInfo() << name.split(" ");

    int index = name.indexOf(".");
    qInfo() << name.remove(0,index + 1).trimmed();

    QString title = "teacher";
    QString full = name.trimmed() + " " + title;
    qInfo() << full;

    qInfo() << full.toLatin1();

    return a.exec();
}
