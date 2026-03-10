#include "basegraphiccomp.h"

// need a customized graphics object

BaseGraphicComponent::BaseGraphicComponent()
{

}


BaseGraphicComponent::~BaseGraphicComponent()
{

}


void BaseGraphicComponent::updateGraphics()
{

}

MGraphicsObject *BaseGraphicComponent::getGraphicsObject(void)
{
    return graphicsObject_;
}
