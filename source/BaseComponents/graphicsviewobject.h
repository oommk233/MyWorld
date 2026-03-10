#ifndef GRAPHICSVIEWOBJECT_H
#define GRAPHICSVIEWOBJECT_H

#include <QGraphicsView>
#include <QObject>
#include <QColor>

#include "BaseComponents/graphicssceneobject.h"

// This is for QGraphicsView container

class GraphicsViewObject : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsViewObject(QObject *parent = nullptr,
                                GraphicsSceneObject *sceneObject = nullptr);

    void setGraphicsSceneObject(GraphicsSceneObject *sceneObject);

    QGraphicsView *getGraphicsView(void);

    void setBackgroundColor(QColor backgroundColor);

signals:

private:
    // Will not return/expose QGraphicsView to the outside
    // So, return QGraphicsView is forbidden here

    void initialization(void);

    GraphicsSceneObject *graphicsSceneObject_;
    QGraphicsView *graphicsView_;
};

#endif // GRAPHICSVIEWOBJECT_H
