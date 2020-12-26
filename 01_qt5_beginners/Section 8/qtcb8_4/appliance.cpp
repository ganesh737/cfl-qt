#include "appliance.h"

appliance::appliance(QObject *parent) : QObject(parent)
{

}


bool appliance::grill()
{
    return true;
}

bool appliance::cook()
{
    return true;
}

bool appliance::freeze()
{
    return true;
}
