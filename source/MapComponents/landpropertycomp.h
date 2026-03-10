#ifndef LANDPROPERTYCOMP_H
#define LANDPROPERTYCOMP_H

#include "source/BaseComponents/basepropertycomp.h"

// Think about namespace, enum definication place

class LandPropertyComp : public BasePropertyComp
{
public:
    LandPropertyComp();
    /*
    LandPropertyComp(const LandPropertyComp &);
    LandPropertyComp(LandPropertyComp &&);

    LandPropertyComp &operator=(const LandPropertyComp &);
    LandPropertyComp &operator=(LandPropertyComp &&);*/

    void setDefaultHeight(void);
    void setDefaultWidth(void);

    int getWidth(void) const;
    int getHeight(void) const;
    void setWidth(int width);
    void setHeight(int height);

private:
    // has house, has characters, empty and so on
    // data type not-decided
    int statusOnObject_;

    // nothing inside, character inside, green inside, curse inside and so on
    // take care of the curse, which is not proper place for it.
    int statusInsideObject_;

    // like has shadow, no shadow, has charecter, and so on
    int statusBelowObject_;

    // no example
    int statusAroundObject_;

    // like, alive, dead, no life and so on
    int state_;
};

#endif // LANDPROPERTYCOMP_H
