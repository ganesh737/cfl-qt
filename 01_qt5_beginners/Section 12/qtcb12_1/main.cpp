#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    double value = 43.88;
    qInfo() << "double:" << value;

    int age = value;
    qInfo() << "int:" << age; // implicit conversion; should not be trusted

    age = (int) value;  // casting old style
    qInfo() << "int:" << age; // explicit conversion; should be trusted

    return a.exec();
}
