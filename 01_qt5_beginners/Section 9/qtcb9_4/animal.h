#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDebug>

class animal : public QObject
{
    Q_OBJECT
public:
    explicit animal(QObject *parent = nullptr, QString name = "");

    // static = shared variable
    static QString name;

signals:

public slots:
};

#endif // ANIMAL_H
