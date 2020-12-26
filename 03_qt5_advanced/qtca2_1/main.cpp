#include <QCoreApplication>
#include <QDebug>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QAbstractSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    foreach(QHostAddress address, list) {
        qInfo() << address.toString();

        // never leaves the machine
        qInfo() << "loopback:" << address.isLoopback();

        // send to many
        qInfo() << "multicast:" << address.isMulticast();

        switch (address.protocol()) {
        case QAbstractSocket::UnknownNetworkLayerProtocol:
            qInfo() << "Protocol: Unknown";
            break;
        case QAbstractSocket::AnyIPProtocol:
            qInfo() << "Protocol: Any";
            break;
        case QAbstractSocket::IPv4Protocol:
            qInfo() << "Protocol: IPv4";
            break;
        case QAbstractSocket::IPv6Protocol:
            qInfo() << "Protocol: IPv6";
            break;
        }
    }

    return a.exec();
}
