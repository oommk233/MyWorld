#ifndef LIVINGOBJECT_H
#define LIVINGOBJECT_H

#include "BaseComponents/baseobject.h"
#include "LebenGegenstand/livinggraphiccomp.h"
#include "LebenGegenstand/livingmapcomp.h"
#include "LebenGegenstand/livingpropertycomp.h"

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
    void initialization(void);

    LivingGraphicComp *livingGraphicComp_;
    LivingMapComp *livingMapComp_;
    LivingPropertyComp *livingPropertyComp_;
};

#endif // LIVINGOBJECT_H
