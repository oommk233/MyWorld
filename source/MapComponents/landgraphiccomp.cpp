#include "landgraphiccomp.h"
#include "GraphicsObjects/landqgraphicsitem.h"

LandGraphicComp::LandGraphicComp()
    : BaseGraphicComponent()
{
    graphicsObject_ = new LandQGraphicsItem();
}
