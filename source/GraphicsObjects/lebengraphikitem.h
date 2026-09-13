#ifndef LEBENGRAPHIKITEM_H
#define LEBENGRAPHIKITEM_H

#include "GraphicsObjects/mgraphicsobject.h"

class LebenGraphikItem : public MGraphicsObject
{
    Q_OBJECT

public:
    LebenGraphikItem();
    virtual ~LebenGraphikItem();

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = 0) override;

    virtual void setWidth(int width) override;
    virtual void setHeight(int height) override;

    QRectF boundingRect() const override;

private:
};

#endif // LEBENGRAPHIKITEM_H
