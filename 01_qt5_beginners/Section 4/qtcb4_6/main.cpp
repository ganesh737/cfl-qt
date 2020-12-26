#include <QCoreApplication>
#include <QDebug>

#include <array>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Arrays
    int ages[4] = {23, 7, 15, 11};

    qInfo() << ages;
    ages[99] = 123;
    qInfo() << ages[0];
    qInfo() << ages[1];
    qInfo() << ages[2];
    qInfo() << ages[3];
    qInfo() << ages[99]; // this works since that memory is not used by others

    // std::array
    array<int, 4> cars;
    cars[0] = 88;
    cars[1] = 8;
    cars[2] = 123;
    cars[3] = 77;
    cars[99] = 312;

    qInfo() << cars[0];
    qInfo() << cars[1];
    qInfo() << cars[2];
    qInfo() << cars[3];
    qInfo() << cars[99];

    // size vs sizeof
    qInfo() << "Size: " << cars.size();
    qInfo() << "Sizeof: " << sizeof (cars);
    qInfo() << "Last: " << cars[cars.size() - 1];

    return a.exec();
}
