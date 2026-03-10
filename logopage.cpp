#include <QtMath>
#include "logopage.h"


LogoPage::LogoPage(QWidget *parent):
    QWidget(parent),
    m_animationTimer_p(nullptr),
    m_totemWidget_p(nullptr),
    m_animateActiveButton_p(nullptr)
{
    this->setGeometry(0, 0, 1800, 900);

    m_animationTimer_p = new QTimer();

    m_totemWidget_p = new TotemAnimatingWidget(this);
    m_totemWidget_p->setGeometry(388, 20, 1024, 768);
    m_totemWidget_p->showWidget();

    m_animateActiveButton_p = new QPushButton(this);
    m_animateActiveButton_p->setGeometry(800, 800, 200, 80);

    connect(m_animationTimer_p, SIGNAL(timeout()), m_totemWidget_p, SLOT(startGenerating()));
    connect(m_animateActiveButton_p, SIGNAL(clicked()), this, SLOT(slotClosePage()));

}


LogoPage::~LogoPage()
{
    if(m_animationTimer_p != nullptr)
    {
        delete m_animationTimer_p;
        m_animationTimer_p = nullptr;
    }

    if(m_totemWidget_p != nullptr)
    {
        delete m_totemWidget_p;
        m_totemWidget_p = nullptr;
    }

    if(m_animateActiveButton_p != nullptr)
    {
        delete m_animateActiveButton_p;
        m_animateActiveButton_p = nullptr;
    }
}


void LogoPage::showWidget(void)
{
    m_animationTimer_p->start(5000);
    this->show();
}


void LogoPage::slotClosePage(void)
{
    m_animationTimer_p->stop();
    this->hide();
    emit signalLogoPageClosed();
}

