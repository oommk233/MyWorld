#include "landmapcomp.h"


LandMapComp::LandMapComp()
{

}

int LandMapComp::posX() const
{
    return posX_;
}

int LandMapComp::poxY() const
{
    return posY_;
}

void LandMapComp::setPosX(int positionX)
{
    posX_ = positionX;
}

void LandMapComp::setPoxY(int positionY)
{
    posY_ = positionY;
}

/* still not clear what to do */
void LandMapComp::updateComp()
{

}

