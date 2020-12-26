#include "test.h"

QString test::getM_message() const
{
    return m_message;
}

void test::setM_message(const QString &value)
{
    m_message = value;
    emit messageChanged(m_message);
}

test::test(QObject *parent) : QObject(parent)
{

}
