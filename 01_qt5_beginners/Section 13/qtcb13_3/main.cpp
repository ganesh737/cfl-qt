#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

// Try / catch

bool doDivision(int max) {
    try {
        int value;
        qInfo() << "Enter a number";
        cin >> value;

        if(value == 0) throw "Can not divide by zero!";
        if(value > 5) throw 99;
        if(value == 1) throw std::runtime_error("Should be greater than 1 !!!");

        int result = max / value;
        qInfo() << "Result = " << result;


    } catch(std::exception const& e) {
        qWarning() << "We caught the STD way: " << e.what();
        return false;
    } catch(int e) {
        qWarning() << "We caught a number" << e;
        return false;
    } catch (char* e){
        qWarning() << "We caught a pointer to char* " << e;
        return false;
    } catch (...) {
        //Catch all = BAD BAD BAD
        qWarning() << "We know something went wrong, but we dont know what.";
       return false;
    }

    // NO Finally!!!!

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
