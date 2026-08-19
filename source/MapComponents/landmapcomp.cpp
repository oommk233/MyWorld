#include "landmapcomp.h"


LandMapComp::LandMapComp()
{

}

int LandMapComp::posX() const
{
    return posX_;
}

int LandMapComp::posY() const
{
    return posY_;
}

void LandMapComp::setPosX(int positionX)
{
    posX_ = positionX;
}

void LandMapComp::setPosY(int positionY)
{
    posY_ = positionY;
}

/* still not clear what to do */
void LandMapComp::updateComp()
{

}

