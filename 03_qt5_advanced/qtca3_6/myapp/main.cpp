#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QPluginLoader>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include "../myplugin/plugin.h"

QStringList getPlugins(QString path) {
    QStringList filter;
    filter << "*.dll" << "*.so" << "*.dylib";

    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(filter);
    QStringList plugins;

    foreach(QFileInfo fi, list) {
        plugins.append(fi.filePath());
        // if(!fi.isSymLink()) plugins.append(fi.filePath());
    }

    return plugins;
}

void testPlugins(QStringList plugins)
{
    foreach (QString file,plugins)
    {
        qInfo() << "Loading: " << file;

        QPluginLoader loader(file);
        if(!loader.load())
        {
            qInfo() << "Error: " <<  loader.fileName() << " Error: " << loader.errorString();
            continue;
        }

        qInfo() << "Loaded: " << loader.fileName();
        Plugin* plugin = qobject_cast<Plugin*>(loader.instance());

        if(plugin)
        {
            plugin->test("Ashwini");
        }
        else
        {
            qInfo() << "Could not cast: " << loader.fileName();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir = QDir::current();
    dir.cdUp();
    dir.cd("myplugin"); // Plugins
    qInfo() << "Path: " << dir.path();

    QStringList plugins = getPlugins(dir.path());
    qInfo() << "Plugins: " << plugins;

    testPlugins(plugins);
    qInfo() << "Done!";

    return a.exec();
}
