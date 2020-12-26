#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>
#include <QDir>

// serialization

bool saveFile(QString path) {
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly)) {
        qWarning() << "File open failed!!!";
        return false;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);

    QString title = "The answer is 42";
    qint64 num = 42;

    out << title;
    out << num;

    file.flush();
    file.close();

    return true;
}

bool readFile(QString path) {
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "File open failed!!!";
        return false;
    }

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_5_15) {
        qCritical() << "Bad version!!!";
        file.close();
        return false;
    }

    QString title;
    qint64 num;

    in >> title;
    in >> num;

    qInfo() << title;
    qInfo() << num;

    file.close();
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString file = QDir::currentPath() + QDir::separator() + "test.txt";
    if(saveFile(file)) {
        qInfo() << "Saved!";

        // read the file
        readFile(file);
    }
    return a.exec();
}
