#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    // port 80 is not encrypted ... it is normal http
    // client.connectToHost("httpbin.org", 80);

    // ssl is port 443
    client.connectToHost("httpbin.org", 443);
    return a.exec();
}
