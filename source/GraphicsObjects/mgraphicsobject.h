#ifndef MGRAPHICSOBJECT_H
#define MGRAPHICSOBJECT_H

// The basic component of the all kinds of Graphic Components

#include <QGraphicsObject>

class MGraphicsObject : public QGraphicsObject
{
    Q_OBJECT

public:
    MGraphicsObject();
    virtual ~MGraphicsObject();

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = 0) override;

    virtual void setWidth(int width);
    virtual void setHeight(int height);

    QRectF boundingRect() const override;

protected:
    int graphicsWidth_;
    int graphicsHeight_;

    // We put graphics object here first, in the base class.
};

#endif // GRAPHICSOBJECT_H
