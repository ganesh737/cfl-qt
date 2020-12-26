#include <QCoreApplication>
#include <QDebug>

template<typename type>
void print(type value)
{
    qInfo() << "value=" << value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int i = 10;
    double f = 12.102;
    QString msg = "hello";

    print(i);
    print(f);
    print(msg);

    print<int>(1);
    print<double>(126.007);
    print<QString>("Hello world!");

    return a.exec();
}
