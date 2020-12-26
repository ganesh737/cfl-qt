#include <QCoreApplication>
#include <QGenericPlugin>
#include <QGenericPluginFactory>
#include <QDebug>
#include "../MyPlugin/itest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Loading MyPlugin!!!";

    QObject* plugin = QGenericPluginFactory::create("myplugin", "stuff here");
    qInfo() << plugin;

    if(plugin) {
        iTest* myplugin = qobject_cast<iTest*>(plugin);
        if(myplugin) {
            myplugin->test();
        }
        else {
            qInfo() << "Could not cast MyPlugin!!!";
        }
    }
    else {
        qInfo() << "Could not load plugin!!!";
    }

    return a.exec();
}
