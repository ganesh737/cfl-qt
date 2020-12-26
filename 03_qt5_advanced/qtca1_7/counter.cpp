#include "counter.h"

Counter::Counter(QObject *parent) : QObject(parent)
{
    value = 0;
}

void Counter::increment()
{
    value++;
}

void Counter::decrement()
{
    value--;
}

int Counter::count()
{
    return value;
}
