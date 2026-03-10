#ifndef OBJECTSMANAGER_H
#define OBJECTSMANAGER_H

// Create the Objects/Components and the maintainer of these Objects/Components

// **************************************************************************
// We need a Factory for the creation
// This is the first time to use the Factory
// Let's do/test it ourselves and see what kind of problem/issue we will meet
// **************************************************************************

// We put the Object Factory here, in the first version of My World
// It is possible to move the Factory out, and simply.

// **************************************************************************
// How to manage the Objects, with different types?
// Version a:
// Let's first manage all Objects in this Class
// Then see what the issue/problem we might meet and find the solution
// **************************************************************************

// **************************************************************************
// First, have the container/objects boxes of different object types
//        all in this class
// And,   use C++ container instead of the Qt's
// I am not sure, the vector, list, array, which is more suitable for this case
// Let's try the vector first, and see the performance
// **************************************************************************

#include "BaseComponents/baseobject.h"
#include "MapComponents/landobject.h"

#include <QList>
#include <vector>
#include <QLabel>

class ObjectsManager
{

public:

    ObjectsManager();
    virtual ~ObjectsManager();

    // Here is the Trial world creation
    // We use this class as factory for trail version
    void createTrialWorldLandObjects(void);

    QList<LandObject *> getTrialWorldLandObjectList(void);

private:
    LandObject *createLandObject(void);

    // we use vector first here.
    // Pair is under consideration.
private:
    QList<LandObject *> m_landObjectList_;
};

#endif // OBJECTSMANAGER_H
