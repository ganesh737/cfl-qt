/*
 * basic imports
 */
#include <QCoreApplication>
#include <QDebug>

// main function

/**
 * @brief main Start of the program
 * @param argc The number of command line arguments
 * @param argv The command line arguments
 * @return
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // this prints info on the console
    qInfo() << "hello, world!!!";
    return a.exec();
}
