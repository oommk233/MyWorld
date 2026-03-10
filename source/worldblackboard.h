#ifndef WORLDBLACKBOARD_H
#define WORLDBLACKBOARD_H

// This class is the main board of the whole world
// The owner of the UpdateMachine, EventManager, ObjectsManager
// To drive the update loop, catch the input event


// The Objects creation and maintaining - Object Manager
// All Objects related events capture and handling - Event Manager (currently only input event)
// Update Objects states - Update Machine
// Update and Repaint the Graphics Items - BG Window

// There shall have two different algorithm/mechanism to update the Objects and GUI
// The Update of the Objects and GUI shall have different time plan

// Take care the sequence of updating the Objects and GUI, and inside the GUI!

// **************************

// WE NEED COMMAND MANAGER!!!

// We need factories in Object Manager and GUI Manager
// We need entire system/mechinisym

// **************************


#include <QObject>
#include "updatemachine.h"
#include "EventManager/eventmanager.h"
#include "CommandPackage/commandmanager.h"
#include "logopage.h"
#include "GUIManager/worldbgwindow.h"

// to show logo page manually, is not a good idea

class WorldBlackBoard : public QObject
{
Q_OBJECT

public:

    WorldBlackBoard();
    virtual ~WorldBlackBoard();

    void simpleInitialization(void);
    void loadLogoWidget(void);

private slots:

    void slotLogoPageClosed(void);


// private method

private:
    // first try, to enter the world
    // with basic map components
    // new start!!!!
    // *********************************************************
    // to generate the map components, we shall use factory mode
    // *********************************************************

    // Need a private factory member?
    // So we need a big factory Class system.
    void loadBasicWorld(void);

private:

    // Use pointer here first
    // Later if necessary, could change to the objects

    // These shall be re-worked
    // 8/6/2024

    LogoPage * m_logoWidget_p;
    UpdateMachine * m_updateMachine_p;
    EventManager * m_eventManager_p;
    CommandManager * m_commandManager_p;

    WorldBGWindow * m_worldBGWindow_p;

};

#endif // WORLDBLACKBOARD_H
