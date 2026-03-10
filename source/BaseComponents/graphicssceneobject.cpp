#include "graphicssceneobject.h"

GraphicsSceneObject::GraphicsSceneObject(QObject *parent)
    : QObject{parent}
    , graphicsScene_(nullptr)
{
    graphicsScene_ = new QGraphicsScene(this);
}

void GraphicsSceneObject::addItems(std::vector<QGraphicsItem *> graphicsItemList)
{
    for (auto ghItem : graphicsItemList) {
        graphicsScene_->addItem(ghItem);
    }
}

void GraphicsSceneObject::addItems(QGraphicsItem *graphicsItem)
{
    graphicsScene_->addItem(graphicsItem);
}

QGraphicsScene *GraphicsSceneObject::getGraphicsScene(void)
{
    return graphicsScene_;
}
