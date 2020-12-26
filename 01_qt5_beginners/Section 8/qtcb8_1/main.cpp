#include <QCoreApplication>

#include "animal.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    animal cat;
    animal dog;
    animal mouse;

    cat.speak("meow");
    dog.speak("bark");
    mouse.speak("squeak");

    return a.exec();
}
