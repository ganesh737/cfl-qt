#ifndef MYPLUGIN_H
#define MYPLUGIN_H

#include <QGenericPlugin>
#include <QDebug>
#include "itest.h"

class MyPlugin : public QGenericPlugin, iTest
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QGenericPluginFactoryInterface_iid FILE "MyPlugin.json")
    Q_INTERFACES(iTest)

public:
    explicit MyPlugin(QObject *parent = nullptr);

    // iTest interface
    void test() override;

private:
    QObject *create(const QString &name, const QString &spec) override;
};

#endif // MYPLUGIN_H
