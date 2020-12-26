#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

// Qt favors bool

bool doDivision(int max) {

    int value;
    qInfo() << "Enter a number";
    cin >> value;

    //if(value == 0) throw "Can not divide by zero!";
    //if(value > 5) throw 99;
    //if(value == 1) throw std::runtime_error("Should be greater than 1 !!!");

    if(value == 0 || value == NULL) {
        qWarning() << "Can not be zero";
        return false;
    }

    if(value > 5) {
        qWarning() << "Should be less than 5";
        return false;
    }

    if(value == 1) {
        qWarning() << "Should be greater than 1";
        return false;
    }

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
