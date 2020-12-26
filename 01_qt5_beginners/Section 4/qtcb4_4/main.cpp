#include <QCoreApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // enums
//    int red = 0;
//    int blue = 2;
//    int green = 1;

//    enum Color {red, green, blue};
    enum Color {red = 1, green = 2, blue = 4};

    Color mycolor = Color::blue;
    qInfo() << "Color: " << mycolor;

    return a.exec();
}
