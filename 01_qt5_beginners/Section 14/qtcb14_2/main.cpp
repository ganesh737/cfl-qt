#include <QCoreApplication>
#include <QDebug>

template<class T, class F>
T add(T valuet, F valuef)
{
    return (valuet + valuef);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << add<int, double>(1,4.6); // Always give it a template
    qInfo() << add(1.09,4); // C++ is guessing
    qInfo() << add(55,true); // C++ is guessing
    //qInfo() << add(55, "hello world"); // this will fail!!!

    return a.exec();
}
