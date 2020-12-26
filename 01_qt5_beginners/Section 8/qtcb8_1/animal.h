// pre processor directive so that this header is included only once
#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDebug>

// blueprint
class animal : public QObject
{
    Q_OBJECT
public:
    explicit animal(QObject *parent = nullptr);

    void speak(QString message);

signals:

public slots:
};

#endif // ANIMAL_H
