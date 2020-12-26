#include <QCoreApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "std out" << std::endl;
    std::cerr << "error out" << std::endl;

    return a.exec();
}
