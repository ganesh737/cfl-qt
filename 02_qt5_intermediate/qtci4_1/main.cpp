#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;

    if(buffer.open(QBuffer::ReadWrite)) {
        qInfo() << "buffer opened!!!";
        QByteArray data("hello world!!!");
        for(int i = 0; i < 5; i++) {
            buffer.write(data);
            buffer.write("\r\n");
        }
        // file and device data may need flush the data to the device
        // buffer.flush();

        // move to first position
        buffer.seek(0);

        // read entire buffer
        qInfo() << buffer.readAll();

        qInfo() << "closing the buffer";
        buffer.close();
    }
    else {
        qInfo() << "Could not open buffer!!!";
    }

    return a.exec();
}
