#ifndef PLUGIN_H
#define PLUGIN_H

#include <QString>
#include <QDebug>

class Plugin
{
public:
    virtual ~Plugin() = 0;
    virtual void test(QString name) = 0;
};

// declare the interface
Q_DECLARE_INTERFACE(Plugin, "com.syncknowledge.plugin");

#endif // PLUGIN_H
