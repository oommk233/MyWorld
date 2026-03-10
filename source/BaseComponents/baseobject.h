#ifndef BASEOBJECT_H
#define BASEOBJECT_H

// The basic class of all Objects
#include <QGraphicsObject>

class BaseObject
{

public:

    BaseObject();
    //BaseObject(const BaseObject&);
    //BaseObject(BaseObject&&);

    //BaseObject &operator=(const BaseObject&);
    //BaseObject &operator=(BaseObject&&);


    virtual ~BaseObject();

    // not pure virtual yet
    // base update function/method
    // shall be implemented by all inherited leaf classes
    virtual void updateWholeObject();
    virtual QGraphicsObject *getGraphicsItem();
};

#endif // BASEOBJECT_H
