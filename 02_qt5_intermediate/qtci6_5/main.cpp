#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>

QString makedata() {
    QString data;
    for(int i=0;i<10;i++) {
        data.append("Hello\r\n");
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makedata();
    QTextCodec *codec = QTextCodec::codecForName("UTF-16");
    if(!codec) {
        qFatal("No codec found");
    }

    QByteArray bytes = codec->fromUnicode(data);
    qInfo() << "Bytes:" << bytes;
    qInfo("");

    QString string = codec->toUnicode(bytes);
    qInfo() << "String:" << string;

    return a.exec();
}
