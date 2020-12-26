#include <QCoreApplication>
#include <QDebug>
#include <iostream>

// Errors vs Exception

//An Error "indicates serious problems that a reasonable application should not try to catch."  - bad bad things
//An Exception "indicates conditions that a reasonable application might want to catch." - most things

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    do {

        int max  = 44;
        int div = 0;

        qInfo() << "Enter a number to divide by (Or zero for an issue!)";

        std::cin >> div;
        int answer = max / div; // Exception - we want to catch!!!
        qInfo() << answer;

        break;

    }while(true);


    return a.exec();
}
