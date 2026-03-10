#ifndef INSTANCEMANAGER_H
#define INSTANCEMANAGER_H

// **************************************************************************
// This is a only one or two instance(s) in the MyWorld,
// to hold those need to be instances objects.
// **************************************************************************

#include "source/ObjectsManager/objectsmanager.h"
#include <memory>

class InstanceManager
{
public:
    virtual ~InstanceManager();

    static InstanceManager *getInstanceManager(void);
    ObjectsManager* getObjectsManager();

private:
    InstanceManager();
    InstanceManager(InstanceManager &);

private:
    ObjectsManager *objectsManager_;
    static InstanceManager *instanceManager_;
};

#endif // INSTANCEMANAGER_H
