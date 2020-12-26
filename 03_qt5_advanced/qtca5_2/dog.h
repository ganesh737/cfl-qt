#ifndef DOG_H
#define DOG_H

#include <QObject>
#include <QDebug>

class Dog : public QObject
{
    Q_OBJECT
public:
    explicit Dog(QObject *parent = nullptr);

signals:

private slots:
    // called before first test
    void initTestCase();

    // called before each test
    void init();

    // called after the last test
    void cleanupTestCase();

    // called after each test
    void cleanup();

    // our custom slot to be tested
    void bark();

    void roll();
};

#endif // DOG_H
