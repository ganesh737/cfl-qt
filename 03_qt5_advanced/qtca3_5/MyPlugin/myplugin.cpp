#include "myplugin.h"

MyPlugin::MyPlugin(QObject *parent)
    : QGenericPlugin(parent)
{
}

void MyPlugin::test()
{
    qInfo() << "This is a test inside of our plugin!";
}

QObject *MyPlugin::create(const QString &name, const QString &spec)
{
    Q_UNUSED(name);
    Q_UNUSED(spec);
    return new MyPlugin;
}
