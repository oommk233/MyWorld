cmake_minimum_required(VERSION 3.5)

project(TheMyWorld LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Core Gui Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Gui Network REQUIRED)


set(DUMMY_DIR ${PROJECT_SOURCE_DIR}/source)
set(EVENT_MANAGER_DIR ${DUMMY_DIR}/EventManager)
set(TOTEM_BRANCH_DIR ${DUMMY_DIR}/TotemBranches)
set(BASE_COMPONENT_DIR ${DUMMY_DIR}/BaseComponents)
set(COMMAND_PACKAGE_DIR ${DUMMY_DIR}/CommandPackage)
set(MAP_COMPONENT_DIR ${DUMMY_DIR}/MapComponents)
set(GRAPHIC_OBJECT_DIR ${DUMMY_DIR}/GraphicsObjects)
set(OBJECT_MANAGER_DIR ${DUMMY_DIR}/ObjectsManager)
set(GUI_MANAGER_DIR ${DUMMY_DIR}/GUIManager)
set(GOD_TRIAL_DIR ${DUMMY_DIR}/GodTrial)

set(DUMMY_SOURCE 
        ${DUMMY_DIR}/main.cpp
        ${DUMMY_DIR}/logopage.h
        ${DUMMY_DIR}/logopage.cpp
        ${DUMMY_DIR}/updatemachine.h
        ${DUMMY_DIR}/updatemachine.cpp
        ${DUMMY_DIR}/worldblackboard.h
        ${DUMMY_DIR}/worldblackboard.cpp)
        
set(EVENT_MANAGER_SOURCE 
        ${EVENT_MANAGER_DIR}/eventmanager.h
        ${EVENT_MANAGER_DIR}/eventmanager.cpp)
        
set(TOTEM_BRANCH_SOURCE 
        ${TOTEM_BRANCH_DIR}/selfgeneratebranch.h
        ${TOTEM_BRANCH_DIR}/selfgeneratebranch.cpp
        ${TOTEM_BRANCH_DIR}/singlesimplebranch.h
        ${TOTEM_BRANCH_DIR}/singlesimplebranch.cpp
        ${TOTEM_BRANCH_DIR}/totemanimatingwidget.h
        ${TOTEM_BRANCH_DIR}/totemanimatingwidget.cpp)

set(BASE_COMPONENT_SOURCE
        ${BASE_COMPONENT_DIR}/basegraphiccomp.h
        ${BASE_COMPONENT_DIR}/basegraphiccomp.cpp
        ${BASE_COMPONENT_DIR}/basemapcomp.h
        ${BASE_COMPONENT_DIR}/basemapcomp.cpp
        ${BASE_COMPONENT_DIR}/baseobject.h
        ${BASE_COMPONENT_DIR}/baseobject.cpp
        ${BASE_COMPONENT_DIR}/basepropertycomp.h
        ${BASE_COMPONENT_DIR}/basepropertycomp.cpp
        ${BASE_COMPONENT_DIR}/graphicssceneobject.h
        ${BASE_COMPONENT_DIR}/graphicssceneobject.cpp
        ${BASE_COMPONENT_DIR}/graphicsviewobject.h
        ${BASE_COMPONENT_DIR}/graphicsviewobject.cpp)

set(COMMAND_PACKAGE_SOURCE
        ${COMMAND_PACKAGE_DIR}/basecommand.h
        ${COMMAND_PACKAGE_DIR}/basecommand.cpp
        ${COMMAND_PACKAGE_DIR}/commandmanager.h
        ${COMMAND_PACKAGE_DIR}/commandmanager.cpp)

set(MAP_COMPONENT_SOURCE 
        ${MAP_COMPONENT_DIR}/landgraphiccomp.h
        ${MAP_COMPONENT_DIR}/landgraphiccomp.cpp
        ${MAP_COMPONENT_DIR}/landmapcomp.h
        ${MAP_COMPONENT_DIR}/landmapcomp.cpp
        ${MAP_COMPONENT_DIR}/landobject.h
        ${MAP_COMPONENT_DIR}/landobject.cpp
        ${MAP_COMPONENT_DIR}/landpropertycomp.h
        ${MAP_COMPONENT_DIR}/landpropertycomp.cpp)
        
set(GRAPHIC_OBJECT_SOURCE 
        ${GRAPHIC_OBJECT_DIR}/landqgraphicsitem.h
        ${GRAPHIC_OBJECT_DIR}/landqgraphicsitem.cpp
        ${GRAPHIC_OBJECT_DIR}/mgraphicsobject.h
        ${GRAPHIC_OBJECT_DIR}/mgraphicsobject.cpp)
        
set(OBJECT_MANAGER_SOURCE 
        ${OBJECT_MANAGER_DIR}/instancemanager.h
        ${OBJECT_MANAGER_DIR}/instancemanager.cpp
        ${OBJECT_MANAGER_DIR}/objectsmanager.h
        ${OBJECT_MANAGER_DIR}/objectsmanager.cpp)
        
set(GUI_MANAGER_SOURCE 
        ${GUI_MANAGER_DIR}/worldbgwindow.h
        ${GUI_MANAGER_DIR}/worldbgwindow.cpp)
        
set(GOD_TRIAL_SOURCE 
        ${GOD_TRIAL_DIR}/erdemutter.h
        ${GOD_TRIAL_DIR}/erdemutter.cpp
        ${GOD_TRIAL_DIR}/lebensmutter.h
        ${GOD_TRIAL_DIR}/lebensmutter.cpp)

message("DUMMY_DIRis ${DUMMY_DIR} | GOD source is ${GOD_TRIAL_SOURCE}")



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    add_executable(TheMyWorld
        ${DUMMY_SOURCE}
        ${EVENT_MANAGER_SOURCE}
        ${TOTEM_BRANCH_SOURCE}
        ${BASE_COMPONENT_SOURCE}
        ${COMMAND_PACKAGE_SOURCE}
        ${MAP_COMPONENT_SOURCE}
        ${GRAPHIC_OBJECT_SOURCE}
        ${OBJECT_MANAGER_SOURCE}
        ${GUI_MANAGER_SOURCE}
        ${GOD_TRIAL_SOURCE}
    )
else()
    if(ANDROID)
        add_library(TheMyWorld SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(TheMyWorld
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(TheMyWorld PRIVATE
  ${DUMMY_DIR}
)
target_link_libraries(TheMyWorld PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Network)
