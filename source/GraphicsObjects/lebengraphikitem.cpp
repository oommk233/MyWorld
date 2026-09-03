#include "lebengraphikitem.h"

LebenGraphikItem::LebenGraphikItem()
    : MGraphicsObject()
{}

LebenGraphikItem::~LebenGraphikItem() {}

void LebenGraphikItem::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget)
{
    return;
}

void LebenGraphikItem::setWidth(int width)
{
    graphicsWidth_ = width;
}

void LebenGraphikItem::setHeight(int height)
{
    graphicsHeight_ = height;
}

QRectF LebenGraphikItem::boundingRect() const
{
    return QRectF(this->x(), this->y(), graphicsWidth_, graphicsHeight_);
}