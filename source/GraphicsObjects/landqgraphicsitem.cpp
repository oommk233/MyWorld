#include "landqgraphicsitem.h"
#include <QPainter>

LandQGraphicsItem::LandQGraphicsItem(): displayText_() {}


// this is only for the trial version
void LandQGraphicsItem::setDisplayText(const QString& inputText)
{

}

void LandQGraphicsItem::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    painter->drawText(this->x(), this->y(), graphicsWidth_, graphicsHeight_, Qt::AlignCenter, displayText_);
}

QRectF LandQGraphicsItem::boundingRect() const
{
    return QRectF(this->x(), this->y(), graphicsWidth_, graphicsHeight_);
}
