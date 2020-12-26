#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = "Hello World!! How are you?";
    QStringList lst = data.split(" ");

    qInfo() << lst;

    foreach(QString str, lst) {
        qInfo() << str;
    }

    lst.sort(Qt::CaseInsensitive);

    qInfo() << lst;

    QString myvar = "Hello";
    if(lst.contains(myvar)) {
        int index = lst.indexOf(myvar);
        qInfo() << lst.value(index);
    }


    return a.exec();
}
