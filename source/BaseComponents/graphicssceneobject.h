#ifndef GRAPHICSSCENEOBJECT_H
#define GRAPHICSSCENEOBJECT_H


#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QObject>

// This is for QGraphicsScene container

class GraphicsSceneObject : public QObject
{
    Q_OBJECT

    friend class GraphicsViewObject;

public:
    explicit GraphicsSceneObject(QObject *parent = nullptr);

    void addItems(std::vector<QGraphicsItem *> graphicsItemList);
    void addItems(QGraphicsItem *graphicsItem);

    QGraphicsScene *getGraphicsScene(void);

signals:

private:
    QGraphicsScene *graphicsScene_;
};

#endif // GRAPHICSSCENEOBJECT_H
