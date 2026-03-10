#ifndef BASEMAPCOMPONENT_H
#define BASEMAPCOMPONENT_H

// Basic map component, all others map shall inherit this one
// and implement the update function/method

class BaseMapCompoment
{

public:
    BaseMapCompoment();
    virtual ~BaseMapCompoment();

    // same as the "update" of the BaseComponent
    // not pure virtual yet
    virtual void updateMapComponent();

};

#endif // BASEMAPCOMPONENT_H
