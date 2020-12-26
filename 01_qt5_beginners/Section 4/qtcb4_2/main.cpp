#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // https://www.geeksforgeeks.org/c-data-types/

    int age = 44;
    double height = 6.01;

    qInfo() << "age: " << age;
    qInfo() << "height: " << height;

    // creates a warning
    age = 46.7;
    qInfo() << "age: " << age;

    signed int dogs = -1;
    qInfo() << "dogs: " << dogs;
    dogs = 15;
    qInfo() << "dogs: " << dogs;

    // creates a warning
    unsigned int cats = -1;
    qInfo() << "cats: " << cats;
    cats = 15;
    qInfo() << "cats: " << cats;

    qInfo() << sizeof(dogs);
    qInfo() << sizeof(cats);
    qInfo() << sizeof(height);

    return a.exec();
}
