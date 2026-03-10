#include "objectsmanager.h"
#include <QDebug>

ObjectsManager::ObjectsManager()
    : m_landObjectList_{}
{}

ObjectsManager::~ObjectsManager()
{
    m_landObjectList_.clear();
}

LandObject *ObjectsManager::createLandObject()
{
    LandObject * landObjectTemp = new LandObject();

    this->m_landObjectList_.push_back(landObjectTemp);

    return landObjectTemp;
}

void ObjectsManager::createTrialWorldLandObjects(void)
{
    // Target 0_0_0
    // Trial world
    // in this world, we use ObjectsManager as factory and maintainer

    // All are simple and easy implementation.
    // will be improved and refactored in the future.

    // We need a executable world first!

    // for Trial world
    // using simple vector with dual loop first
    // first create row item then next row

    // In trial we try index started with 1 instead of 0
    // for maintaining friendly

    int trialLandRow = 16;
    int trialLandColumn = 9;

    for (auto i = 1; i <= trialLandRow; i++) {
        for (auto j = 1; j <= trialLandColumn; j++) {
            LandObject * landObject = createLandObject();
            landObject->setPosition(i, j);
            landObject->setHeight(i);
            landObject->setWidth(i);
        }
    }

    return;
}

QList<LandObject *> ObjectsManager::getTrialWorldLandObjectList(void)
{
    return m_landObjectList_;
}
