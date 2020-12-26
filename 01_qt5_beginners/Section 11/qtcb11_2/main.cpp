#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>

#include "radio.h"
#include "station.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    radio boombox;
    station* channels[3];

    //create some stations
    channels[0] = new station(&boombox, 94, "Rock and Roll");
    channels[1] = new station(&boombox, 101, "hip hop");
    channels[2] = new station(&boombox, 85, "News");

    // Qt::QueuedConnection = used when you work with threads
    boombox.connect(&boombox, &radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    do {
        qInfo() << "Enter on, off, test or quit";
        QTextStream qin(stdin);
        QString line = qin.readLine().trimmed().toUpper();

        if (line == "ON") {
            qInfo() << "Turning the radio ON";
            for (int i = 0; i < 3; i++) {
                station* channel = channels[i];
                boombox.connect(channel, &station::send, &boombox, &radio::listen);
            }
            qInfo() << "Radio is ON";
        }
        else if (line == "OFF") {
            qInfo() << "Turning the radio OFF";
            for (int i = 0; i < 3; i++) {
                station* channel = channels[i];
                boombox.disconnect(channel, &station::send, &boombox, &radio::listen);
            }
            qInfo() << "Radio is OFF";
        }
        else if (line == "TEST") {
            qInfo() << "Testing";
            for (int i = 0; i < 3; i++) {
                station* channel = channels[i];
                channel->broadcast("Broadcasting Live");
            }
            qInfo() << "Testing complete";
        }
        else if (line == "QUIT") {
            qInfo() << "Quitting";
            emit boombox.quit();
            break;
        }

    } while (true);

    return a.exec();
}
