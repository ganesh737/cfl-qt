#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>

QString makedata() {
    QString data;

    data.append("Unicode test\r\n");
    for (int i = 0; i< 10 ;i++ ) {
        int number = QRandomGenerator::global()->bounded(1112064);
        data.append(number);
    }

    data.append("\r\n");
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makedata();
    QString path = QDir::currentPath() + QDir::separator() + "test.txt";

    QFile file(path);
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);

        stream.setCodec("UTF-8");
        stream << data;
        stream.flush();

        file.close();
    }

    qInfo() << "Done";
    qInfo() << "Unicode" << data;
    qInfo("");
    qInfo() << "ASCII: " << data.toLatin1();
    return a.exec();
}
