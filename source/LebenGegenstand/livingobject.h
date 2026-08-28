#ifndef LIVINGOBJECT_H
#define LIVINGOBJECT_H

#include "BaseComponents/baseobject.h"

/* In trial version, using same structure as the MapComponents
 * 
 * Current structure, the MapCompoents has, has the problem.
 * If all components/Objects, following this, they will also have same three sub-classes,
 * which might be same or similar, and is not necessary for the implmentation.
 * 
 * In Trial version, try it, find its un-comfortable and its bad.
 * Then improve it.
 * 
 */

class LivingObject : public BaseObject
{
public:
    LivingObject();
    virtual ~LivingObject();

private:
};

#endif // LIVINGOBJECT_H
