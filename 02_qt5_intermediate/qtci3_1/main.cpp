#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("syncknowlgedge");
    QCoreApplication::setOrganizationDomain("syncknowledge.com");
    QCoreApplication::setApplicationName("tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    // save a settings
    // settings.setValue("test", 123);

    // rad the setting back
    qInfo() << settings.value("test").toString();
    qInfo() << settings.value("test").toInt();

    return a.exec();
}
