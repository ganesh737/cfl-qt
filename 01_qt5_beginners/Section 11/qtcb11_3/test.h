#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class test : public QObject
{
    Q_OBJECT

    QString m_message;
public:
    explicit test(QObject *parent = nullptr);

    Q_PROPERTY(QString message
               READ getM_message
               WRITE setM_message
               NOTIFY messageChanged)

    QString getM_message() const;
    void setM_message(const QString &value);

signals:
    void messageChanged(QString message);

public slots:
};

#endif // TEST_H
