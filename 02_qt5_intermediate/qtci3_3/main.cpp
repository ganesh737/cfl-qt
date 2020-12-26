#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QStringList>
#include <QRandomGenerator>

void saveAge(QSettings *settings, QString group, QString name, int age) {
    settings->beginGroup(group);
    settings->setValue(name, age);
    settings->endGroup();
}

int getAge(QSettings *settings, QString group, QString name) {
    settings->beginGroup(group);

    if(!settings->contains(name)) {
        qWarning() << "Does not contain " << name << " in " << group;
        settings->endGroup();
        return 0;
    }

    bool ok;
    int value = settings->value(name).toInt(&ok);
    settings->endGroup();

    if(!ok) {
        qWarning() << "Failed to convert to int";
        return 0;
    }

    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("syncknowlgedge");
    QCoreApplication::setOrganizationDomain("syncknowledge.com");
    QCoreApplication::setApplicationName("tester2");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    saveAge(&settings, "people", "Ashwini", 26);
    saveAge(&settings, "juice", "tropicana", 1);
    saveAge(&settings, "juice", "Ashwini", 2);

    QStringList people;
    people << "Ashwini" << "Ganesh" << "Rama" << "Bryan" << "Heather";

    foreach(QString person, people) {
        int value = QRandomGenerator::global()->bounded(100);
        saveAge(&settings, "test", person, value);
    }

    // ensure that it is saved
    settings.sync();

    qInfo() << settings.fileName();

    foreach(QString group, settings.childGroups()) {
        settings.beginGroup(group);
        qInfo() << "Group:" << group;
        foreach(QString key, settings.childKeys()) {
            qInfo() << "... key:" << key << " = " << settings.value(key).toString();
        }
        settings.endGroup();
    }
    return a.exec();
}
