#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

// throwing

bool doDivision(int max) {
    int value;
    qInfo() << "Enter a number";
    cin >> value;

    if(value == 0) throw "Can not divide by zero!";

    int result = max / value;
    qInfo() << "Result = " << result;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int max = 44;
    do {
        // Do something here
    } while(doDivision(max));

    return a.exec();
}
