#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QDebug>
#include <QDataStream>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    void fill();
    QString name();
    void setName(QString value);
    QMap<QString, QString> map();

    friend QDataStream& operator <<(QDataStream &stream, const test &t) {
        qInfo() << "Operload <<";
        stream << t.m_name;
        stream << t.m_map;
        return stream;
    }

    friend QDataStream& operator >> (QDataStream &stream, test &t) {
        qInfo() << "Overloaded operator >>";
        stream >> t.m_name;
        stream >> t.m_map;
        return stream;
    }

signals:

private:
    QString m_name;
    QMap<QString, QString> m_map;

};

#endif // TEST_H
