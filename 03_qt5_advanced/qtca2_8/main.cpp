#include <QCoreApplication>
#include <QDebug>
#include <QUdpSocket>
#include <QDateTime>
#include <QNetworkDatagram>

bool bind(QUdpSocket* socket, quint16 port) {
    // the below lines will not allow for same port
    // to be connected for broadcaster and client
    // if(socket->bind(port))
    // if(socket->bind(port, QUdpSocket::DontShareAddress))
    if(socket->bind(port, QUdpSocket::ShareAddress))
        return true;

    qWarning() << socket->errorString();
    return false;
}

void send(QUdpSocket* socket, quint16 port) {
    QString date = QDateTime::currentDateTime().toString();
    QByteArray data = date.toLatin1();

    QNetworkDatagram datagram(data, QHostAddress::Broadcast, port);

    if(socket->writeDatagram(datagram) <= 0) {
        qWarning() << socket->errorString();
    }
}

void read(QUdpSocket* socket) {
    qInfo() << "Reading...";
    socket->waitForReadyRead(60000);
    while(socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = socket->receiveDatagram();
        qInfo() << datagram.data();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QUdpSocket broadcaster;
    QUdpSocket client;
    quint16 port = 2020;

    qInfo() << "Binding ...";
    if(bind(&broadcaster, port) && bind(&client, port)) {
        qInfo() << "Sending...";
        send(&broadcaster, port);
        read(&client);
    }
    else {
        qWarning() << "Could not bind!!!";
    }

    return a.exec();
}
