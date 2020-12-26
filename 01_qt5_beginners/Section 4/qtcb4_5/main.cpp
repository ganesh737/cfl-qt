#include <QCoreApplication>
#include <QDebug>

enum Color {black, red, green, blue};

// Precursor to "classes"
struct product
{
    int weight;
    double value;
    Color color;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    product laptop; // no assignment
    qInfo() << "Size of product:" << sizeof (laptop);
    qInfo() << "Size of weight:" << sizeof (laptop.weight);
    qInfo() << "Size of value:" << sizeof (laptop.value);
    qInfo() << "Size of color:" << sizeof (laptop.color);

    laptop.color = Color::blue;
    laptop.value = 550.37;
    laptop.weight = 3;

    qInfo() << "weight: " << laptop.weight;
    qInfo() << "value: " << laptop.value;
    qInfo() << "color: " << laptop.color;
    // error
//    qInfo() << "latop:" << laptop;

    return a.exec();
}
