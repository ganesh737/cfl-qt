#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "animal.h"

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);
    ~test();
    animal* dog;

signals:

public slots:
};

#endif // TEST_H
