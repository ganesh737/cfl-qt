#include <QCoreApplication>
#include <QDebug>

void test(QString* value)
{
    qInfo() << "test:" << value;
    qInfo() << "test data:" << *value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString* data = new QString("lonahdahsgfhdsgfjsakjfh");

    qInfo() << "Actual size:" << data->length();
    qInfo() << "Pointer size:" << sizeof (data);
    qInfo() << "Data:" << *data;
    qInfo() << "Size of Data:" << sizeof (*data);

    test(data);

    delete data;

    return a.exec();
}
