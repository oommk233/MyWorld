#include "worldblackboard.h"

#include "MapComponents/landobject.h"

WorldBlackBoard::WorldBlackBoard():
    QObject(),
    m_logoWidget_p(nullptr),
    m_updateMachine_p(nullptr),
    m_eventManager_p(nullptr),
    m_worldBGWindow_p(nullptr)
{
    // initialize the pointer
    simpleInitialization();

}


WorldBlackBoard::~WorldBlackBoard(){

    if ( nullptr != m_logoWidget_p ){
        delete m_logoWidget_p;
        m_logoWidget_p = nullptr;
    }

    if ( nullptr != m_updateMachine_p ){
        delete m_updateMachine_p;
        m_updateMachine_p = nullptr;
    }

    if ( nullptr != m_eventManager_p ){
        delete m_eventManager_p;
        m_eventManager_p = nullptr;
    }

    if ( nullptr != m_worldBGWindow_p ){
        delete m_worldBGWindow_p;
        m_worldBGWindow_p = nullptr;
    }

}


void WorldBlackBoard::simpleInitialization(void){

    m_logoWidget_p = new LogoPage();


    m_updateMachine_p = new UpdateMachine();


    m_eventManager_p = new EventManager();


    m_worldBGWindow_p = new WorldBGWindow();

}


void WorldBlackBoard::loadLogoWidget(void){

    if ( m_logoWidget_p ){
        m_logoWidget_p->showWidget();
        connect(m_logoWidget_p, SIGNAL(signalLogoPageClosed()), this, SLOT(slotLogoPageClosed()), Qt::UniqueConnection);
    }

}


void WorldBlackBoard::slotLogoPageClosed(void)
{
    // Here will initialize the Main Page
    // First version is the Land page
    loadBasicWorld();
}


void WorldBlackBoard::loadBasicWorld(void)
{
    // **************************************************
    // Second phrase
    // **************************************************

    // Try, to call Object Manager, to create land object
    // Inside Object Manager, there shall be a factory, and a maintainer
    // for the objects creation and stored
    // No update machine and mechanism is necessary for this phrase
    // Ah, please update the github related plan!!!

    m_worldBGWindow_p->createAndShowTrialWorld();

    // MainWindow->showLand() or MainWidget->showLand() ?
    // We also need graphic scene and graphic view here for land display/showing.
    // Then which shall take graphic view and which with graphic scene?
}
