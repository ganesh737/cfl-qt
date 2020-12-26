#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

// declare a category
Q_DECLARE_LOGGING_CATEGORY(network);
Q_LOGGING_CATEGORY(network, "networking");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo(network) << "test";

    // turn it off
    QLoggingCategory::setFilterRules("networking.debug=false");

    // will not log
    qDebug(network) << "kitty";

    if(!network().isDebugEnabled()) {
        QLoggingCategory::setFilterRules("networking.debug=true");
        qDebug() << "We turned it back on";
    }

    qDebug(network) << "yes!";

    return a.exec();
}
