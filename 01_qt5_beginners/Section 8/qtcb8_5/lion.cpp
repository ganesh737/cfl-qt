#include "lion.h"

lion::lion(QObject *parent) : feline(parent)
{

}

void lion::speak()
{
    qInfo() << "roar";

    // call the function speak from feline
    feline::speak();
}
