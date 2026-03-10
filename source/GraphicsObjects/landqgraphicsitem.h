#ifndef LANDQGRAPHICSITEM_H
#define LANDQGRAPHICSITEM_H

#include "source/GraphicsObjects/mgraphicsobject.h"

class LandQGraphicsItem : public MGraphicsObject
{
public:
    LandQGraphicsItem();

    // this is only for the trial version
    void setDisplayText(const QString& inputText);

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = 0) override;

    QRectF boundingRect() const override;

private:
    QString displayText_;
};

#endif // LANDQGRAPHICSITEM_H
