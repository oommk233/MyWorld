#include "updatemachine.h"

UpdateMachine::UpdateMachine():
    objectsManager_(nullptr)
{
    initialization();
}

void UpdateMachine::updateWholeWorld()
{

}


void UpdateMachine::initialization()
{
    ObjectsManager * obj = InstanceManager::getInstanceManager()->getObjectsManager();

    if (obj != nullptr)
    {
        objectsManager_ = obj;
    }
}
