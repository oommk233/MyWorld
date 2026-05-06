#include "worldblackboard.h"

#include <QApplication>
#include <QDebug>
#include <QList>
#include <QPushButton>

// logo page demo done


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WorldBlackBoard w;
    w.loadLogoWidget();
    return a.exec();
}
