#ifndef UPDATEMACHINE_H
#define UPDATEMACHINE_H

#include "ObjectsManager/objectsmanager.h"
#include "ObjectsManager/instancemanager.h"

class UpdateMachine
{
public:
    UpdateMachine();

    void updateWholeWorld();

private:

    void initialization();

    // To have all Objects inside, or let's say those need to be upated.
    // But, shall not differenient the objects need to be updated or not,
    // otherwise,is not good for the codes extention.

    // In trial version, just put the manager links here inside
    // It can be improved later, but now make the trial version work is the highest priority
    ObjectsManager * objectsManager_;

};

#endif // UPDATEMACHINE_H
