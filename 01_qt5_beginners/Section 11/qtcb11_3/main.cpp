#include <QCoreApplication>
#include <QDebug>

#include "test.h"
#include "watcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test tester;
    watcher dest;

    QObject::connect(&tester, &test::messageChanged, &dest, &watcher::messageChanged);

    tester.setProperty("message", "hello, world!!!");
//    tester.setM_message("testing");

    return a.exec();
}
