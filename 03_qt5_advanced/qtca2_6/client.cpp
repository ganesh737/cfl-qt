#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    connect(&socket, &QTcpSocket::connected, this, &Client::connected);
    connect(&socket, &QTcpSocket::disconnected, this, &Client::disconnected);

    connect(&socket, &QTcpSocket::stateChanged, this, &Client::stateChanged);
    connect(&socket, &QTcpSocket::readyRead, this, &Client::readyRead);
    connect(&socket, &QTcpSocket::errorOccurred, this, &Client::errorOccurred);

    // Ssl
    connect(&socket, &QSslSocket::encrypted, this, &Client::encrypted);
    connect(&socket, &QSslSocket::encryptedBytesWritten, this, &Client::encryptedBytesWritten);
    connect(&socket, &QSslSocket::modeChanged, this, &Client::modeChanged);
    connect(&socket, &QSslSocket::peerVerifyError, this, &Client::peerVerifyError);
    connect(&socket, &QSslSocket::preSharedKeyAuthenticationRequired, this, &Client::preSharedKeyAuthenticationRequired);
    connect(&socket, QOverload<const QList<QSslError> &>::of(&QSslSocket::sslErrors), this, &Client::sslErrors);

    QString server = "186.251.225.228";
    quint16 port = 3128;
    qInfo() << "Using proxy server:" << server << ":" << port;
    QNetworkProxy proxy(QNetworkProxy::HttpProxy, server, port);
    // set authenticators
    // proxy.setUser("username");
    // proxy.setPassword("password");

    // per application
    // QNetworkProxy::setApplicationProxy(proxy);

    // per socket
    socket.setProxy(proxy);
}

void Client::connectToHost(QString host, quint16 port)
{
    if(socket.isOpen()) disconnect();
    qInfo() << "Connecting to: " << host << " on port " << port;

    // Normal TCP
    //socket.connectToHost(host, port);

    socket.ignoreSslErrors();
    socket.setProtocol(QSsl::AnyProtocol);
    socket.connectToHostEncrypted(host, port);
}

void Client::disconnect()
{
    socket.close();
}

void Client::connected()
{
    qInfo() << "Connected ...";

    qInfo() << "Sending";
    // socket.write("Hello\r\n");

    QByteArray data;
    data.append("GET /get HTTP/1.1\r\n");
    data.append("User-Agent: Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.0; Trident/4.0)\r\n");
    data.append("Host: local\r\n");
    data.append("Connection: Close\r\n");
    data.append("\r\n");
    socket.write(data);

    socket.waitForBytesWritten();
}

void Client::disconnected()
{
    qInfo() << "Disconnected ...";
    disconnect();
}

void Client::errorOccurred(QAbstractSocket::SocketError socketError)
{
    qInfo() << "Error: " << socketError << " " << socket.errorString();
}

void Client::stateChanged(QAbstractSocket::SocketState socketState)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    qInfo() << "State: " << metaEnum.valueToKey(socketState);
}

void Client::readyRead()
{
    qInfo() << "Data from " << sender() << " bytes: " << socket.bytesAvailable();
    qInfo() << "Data:" << socket.readAll();
}

void Client::encrypted()
{
    qInfo() << "Encrypted";
}

void Client::encryptedBytesWritten(qint64 written)
{
    qInfo() << "encryptedBytesWritten: " << written;
}

void Client::modeChanged(QSslSocket::SslMode mode)
{
    //Qt does not support this!!!
    //QMetaEnum metaEnum = QMetaEnum::fromType<QSslSocket::SslMode>();
    //qDebug() << "SSL Mode: " << metaEnum.valueToKey(mode);
    qInfo() << "SslMode: " << mode;
}

void Client::peerVerifyError(const QSslError &error)
{
    qInfo() << "peerVerifyError: " << error.errorString();
}

void Client::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator)
{
    qInfo() << "Preshared key required!";
    //QSslPreSharedKeyAuthenticator lookup if needed
}

void Client::sslErrors(const QList<QSslError> &errors)
{
    qInfo() << "SSL Errors!";
    foreach(QSslError e, errors)
    {
        qInfo() << e.errorString();
    }
}
