#ifndef LOGOPAGE_H
#define LOGOPAGE_H

#include <QWidget>
#include <QGraphicsView>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QPointF>
#include <QList>
#include <QTimer>

#include "TotemBranches/totemanimatingwidget.h"

// This is a simple ugly Logo page
// Let's make it dummy
// I am sorry

class LogoPage : public QWidget
{
    Q_OBJECT

public:
    LogoPage(QWidget *parent = nullptr);
    virtual ~LogoPage();

    void showWidget(void);

signals:

    void signalLogoPageClosed(void);

private slots:

    void slotClosePage(void);

private:

    QTimer * m_animationTimer_p;

    TotemAnimatingWidget * m_totemWidget_p;
    QPushButton * m_animateActiveButton_p;

};
#endif // LOGOPAGE_H
