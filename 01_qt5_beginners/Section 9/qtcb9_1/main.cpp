#include <QCoreApplication>
#include <QDebug>

void test(int number) {
//    int number  = 50;
    qInfo() << "2 Test number is at:"  << &number << " = " << number;
}

void testRef(int &number) {
//    int number  = 50;
    qInfo() << "2 Test number is at:"  << &number << " = " << number;

    int age = 30;
    qInfo() << "2 Test age is at:"  << &age << " = " << age;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number = 75;
    qInfo() << "1 Test number is at:"  << &number << " = " << number;

    test(number);
    testRef(number);

    bool ok = true;
    if (ok) {
        qInfo() << "3 Test number is at:"  << &number << " = " << number;

        // below will result in compilation error since age is not defined in this scope
//        qInfo() << "2 Test age is at:"  << &age << " = " << age;
    }

    return a.exec();
}
