#include <QCoreApplication>
#include <QDebug>
#include "widget_global.h"
#include "widget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget widget;
    widget.start();
    return a.exec();
}
