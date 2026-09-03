#include "livingobject.h"

LivingObject::LivingObject()
    : BaseObject()
    , livingGraphicComp_(nullptr)
    , livingMapComp_(nullptr)
    , LivingPropertyComp_(nullptr)
{
    initialization();
}

LivingObject::~LivingObject()
{
}

void LivingObject::initialization(void)
{
    livingGraphicComp_ = new LivingGraphicComp();
    livingMapComp_ = new LivingMapComp();
    livingPropertyComp_ = new LivingPropertyComp();
}