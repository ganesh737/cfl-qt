#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

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

    // save a settings
    // settings.setValue("test", 123);

    // read the setting back
    // qInfo() << settings.value("test").toString();
    // qInfo() << settings.value("test").toInt();

    saveAge(&settings, "people", "Ashwini", 26);
    saveAge(&settings, "juice", "tropicana", 1);
    saveAge(&settings, "juice", "Ashwini", 2);


    qInfo() << "Tropicana" << getAge(&settings, "juice", "tropicana");
    qInfo() << "Ashwini (people)" << getAge(&settings, "people", "Ashwini");
    qInfo() << "Ashwini (juice)" << getAge(&settings, "juice", "Ashwini");

    return a.exec();
}
