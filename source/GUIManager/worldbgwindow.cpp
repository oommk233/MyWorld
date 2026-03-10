#include "worldbgwindow.h"
#include "MapComponents/landobject.h"

WorldBGWindow::WorldBGWindow(QObject *parent)
    : QMainWindow{}
    , sceneObject_(nullptr)
    , viewObject_(nullptr)
    , instanceManager_(nullptr)
    , objectsManager_(nullptr)
    , testLabel_(nullptr)
{}

void WorldBGWindow::createAndShowTrialWorld(void)
{
    trialWorldInitialization();
}

void WorldBGWindow::trialWorldInitialization(void)
{
    this->setGeometry(0,0,1024,768);

    this->setAutoFillBackground(true);
    this->setBackgroundColor(QColor::fromRgb(255,255,255));

    sceneObject_ = new GraphicsSceneObject(this);
    viewObject_ = new GraphicsViewObject(this, sceneObject_);

    viewObject_->getGraphicsView()->setParent(this);
    viewObject_->getGraphicsView()->setGeometry(0,0,1024,768);

    instanceManager_ = InstanceManager::getInstanceManager();
    objectsManager_ = instanceManager_->getObjectsManager();

    createTrialWorldObjects();

    createTrialGraphicsWorld();

    viewObject_->getGraphicsView()->show();

    showTheTrialWorld();

    return;
}

void WorldBGWindow::createTrialWorldObjects(void)
{
    objectsManager_->createTrialWorldLandObjects();

}

void WorldBGWindow::createTrialGraphicsWorld(void)
{
    // We create GraphicsScene and View by hard code in Trial World
    // And should be improved during development of Trial World

    // Set Scene and View Rectangle and Geometry

    // Set Scene Retangle by default first, in trial version
    // sceneObject_->setSceneRectangle(0, 0, 0, 0);
    // And same for the Graphics View
    // viewObject->setSceneRect(0, 0, 0, 0);

    // okay, how is the proper way to add graphicsItem?

    // lets say in trial first version, we use static_cast for temporary solution

    auto itemList = objectsManager_->getTrialWorldLandObjectList();

    for (auto itemIt : itemList) {
        auto graphicsItem = itemIt->getGraphicsItem();
        sceneObject_->addItems(graphicsItem);
    }

    return;
}


void WorldBGWindow::showTheTrialWorld(void){
    this->show();
}


void WorldBGWindow::setBackgroundColor(QColor color)
{
    QPalette thisPalette = this->palette();
    thisPalette.setBrush(QPalette::Window, QBrush(Qt::white));
    this->setPalette(thisPalette);


}


