#ifndef BASEGRAPHICCOMPONENT_H
#define BASEGRAPHICCOMPONENT_H

// The basic component of the all kinds of Graphic Components

#include <QGraphicsItem>
#include "GraphicsObjects/mgraphicsobject.h"

class BaseGraphicComponent
{

public:
    BaseGraphicComponent();
    virtual ~BaseGraphicComponent();

    virtual void updateGraphics();

    MGraphicsObject *getGraphicsObject(void);

    // We put graphics object here first, in the base class.

protected:
    // Todo, using MGraphicsObject here instead of the Qt one
    MGraphicsObject *graphicsObject_;
};

#endif // BASEGRAPHICCOMPONENT_H
