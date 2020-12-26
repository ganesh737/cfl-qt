#include "test.h"

test::test(QObject *parent) : QThread(parent)
{

}

void test::quit()
{
    ok = false;
    QThread::quit();
}

void test::run()
{
    ok = true;
    for(int i = 0; i < 1000; i++) {
        qInfo() << i;
        this->sleep(1);

        if(!ok)
            break;
    }

    qInfo() << "finished";
}
