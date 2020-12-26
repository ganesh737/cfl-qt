#include <QCoreApplication>
#include <QDir>
#include <QString>
#include <QFileInfo>
#include <QDebug>

bool createDir(QString path) {
    QDir dir(path);

    if(dir.exists()) {
        qInfo() << "Directory already exists";
        return true;
    }

    if(dir.mkpath(path)) {
        qInfo() << "Created dir";
        return true;
    }
    else {
        qInfo() << "Could not create!!!";
        return false;
    }
}

bool rename(QString path, QString name) {
    QDir dir(path);

    if(!dir.exists()) {
        qInfo() << "Path does not exist";
        return false;
    }

    /* Seperator -
    Linux - /
    Windows - \\ */
    int pos = path.lastIndexOf(QDir::separator());
    QString parent = path.mid(0, pos);
    QString newpath = parent + QDir::separator() + name;

    qInfo() << "Absolute:" << dir.absolutePath();
    qInfo() << "Parent:" << parent;
    qInfo() << "Now:" << newpath;

    return dir.rename(path, newpath);
}

bool delDir(QString path) {
    qInfo() << "Removing:" << path;
    QDir dir(path);
    if(!dir.exists()) {
        qInfo() << "Path does not exist";
        return false;
    }

    return dir.removeRecursively();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath();
    QString test = path + QDir::separator() + "test";
    QString tmp = "tmp";

    QDir current(QDir::currentPath());
    if(current.exists()) {
        foreach(QFileInfo fi, current.entryInfoList()) {
            qInfo() << fi.fileName();
        }
    }

    if(createDir(test)) {
        qInfo() << "Created test";
        if(rename(test, tmp)) {
            qInfo() << "Renamed test to tmp";
            if(delDir(path + QDir::separator() + tmp)) {
                qInfo() << "Removed";
            }
            else {
                qInfo() << "Could not remove";
            }
        }
    }

    return a.exec();
}
