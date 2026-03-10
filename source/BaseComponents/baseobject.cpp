#include <QDebug>

#include "baseobject.h"


BaseObject::BaseObject()
{
}

/*
BaseObject::BaseObject(const BaseObject& inputObject)
{
    qDebug() << "Here is in the BaseObject Copy Constructor" << Qt::endl;

}


BaseObject::BaseObject(BaseObject&& inputObject)
{
    qDebug() << "Here is in the BaseObject right value Constructor" << Qt::endl;
}
*/
/*
BaseObject& BaseObject::operator=(const BaseObject& inputObject)
{
    qDebug() << "Here is the operator =, reload function..." << Qt::endl;

    return *this;
}


BaseObject& BaseObject::operator=(BaseObject&& inputObject)
{
    qDebug() << "Here is the operator =, RIGHT Value, reload function..." << Qt::endl;

    return *this;
}*/



BaseObject::~BaseObject()
{

}


void BaseObject::updateWholeObject()
{

}

QGraphicsObject *BaseObject::getGraphicsItem()
{
    return nullptr;
}
