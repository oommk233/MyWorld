#include "mgraphicsobject.h"

MGraphicsObject::MGraphicsObject()
    : QGraphicsObject()
{}

MGraphicsObject::~MGraphicsObject() {}

void MGraphicsObject::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget)
{
    return;
}

void MGraphicsObject::setWidth(int width)
{
    graphicsWidth_ = width;
}

void MGraphicsObject::setHeight(int height)
{
    graphicsHeight_ = height;
}

QRectF MGraphicsObject::boundingRect() const
{
    return QRectF(this->x(), this->y(), graphicsWidth_, graphicsHeight_);
}
