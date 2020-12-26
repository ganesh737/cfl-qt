#include "animal.h"

animal::animal(QObject *parent) : QObject(parent)
{

}

void animal::speak(QString message)
{
    qDebug() << message;
}
