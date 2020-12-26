#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class counter : public QObject
{
    Q_OBJECT
public:
    explicit counter(QObject *parent = nullptr);

signals:

public slots:
    void start();

};

#endif // COUNTER_H
