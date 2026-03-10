#include <QPointF>
#include <QPalette>
#include <QColor>
#include "totemanimatingwidget.h"


TotemAnimatingWidget::TotemAnimatingWidget(QWidget *parent):
    QWidget(parent),
    m_generatingCount_(0),
    m_singleLineLength_(0),
    m_baseBranch_(nullptr),
    m_totemGraphicsScene_(nullptr),
    m_totemGraphicsView_(nullptr),
    m_selfGenrateBranches_()
{
    initialization();
}


TotemAnimatingWidget::~TotemAnimatingWidget()
{
    if(m_baseBranch_ != nullptr)
    {
        delete m_baseBranch_;
        m_baseBranch_ = nullptr;
    }

    if(m_totemGraphicsScene_ != nullptr)
    {
        delete m_totemGraphicsScene_;
        m_totemGraphicsScene_ = nullptr;
    }

    if(m_totemGraphicsView_ != nullptr)
    {
        delete m_totemGraphicsView_;
        m_totemGraphicsView_ = nullptr;
    }



    for (SelfGenerateBranch * branchIt : m_selfGenrateBranches_)
    {
        if(branchIt != nullptr)
        {
            delete branchIt;
            branchIt = nullptr;
        }
    }

    m_selfGenrateBranches_.clear();
}


void TotemAnimatingWidget::showWidget(void)
{
    this->show();
}


void TotemAnimatingWidget::initialization(void)
{
    m_generatingCount_ = 0;
    m_singleLineLength_ = 0;

    this->setAutoFillBackground(true);
    QPalette currentPalette = this->palette();
    currentPalette.setColor(QPalette::Window, Qt::lightGray);
    this->setPalette(currentPalette);

    m_totemGraphicsScene_ = new QGraphicsScene(this);

    m_totemGraphicsScene_->setSceneRect(QRect(0, 0, 1024, 768));

    m_totemGraphicsView_ = new QGraphicsView(this);
    m_totemGraphicsView_->setGeometry(0, 0, 1024, 768);
    m_totemGraphicsView_->setScene(m_totemGraphicsScene_);

    m_selfGenrateBranches_.clear();

    generateBaseView();
}


void TotemAnimatingWidget::startAnimation(void)
{
    QPointF startPos(512, 650);
    generateLoop(startPos);
}


void TotemAnimatingWidget::stopAnimation(void)
{

}


QPointF TotemAnimatingWidget::getMainBranchStartPos(void)
{
    return QPointF();
}


void TotemAnimatingWidget::setMainBranchStartPos(QPointF linePosStart)
{

}


void TotemAnimatingWidget::startGenerating(void)
{
    slotClearBranches();
    generateBaseView();
    QPointF startPos(512, 650);
    generateLoop(startPos);
}

void TotemAnimatingWidget::generateBaseView(void)
{
    m_baseBranch_ = new SelfGenerateBranch(m_totemGraphicsScene_);
    m_baseBranch_->setLinePosStart(QPointF(112, 650));
    m_baseBranch_->setLinePosEnd(QPointF(912, 650));

    m_totemGraphicsScene_->addItem(m_baseBranch_->getGraphicsItem());
}


void TotemAnimatingWidget::generateLoop(QPointF startPos)
{
    SelfGenerateBranch * branchTemp = new SelfGenerateBranch();

    // The angle here is minus and plus angle.
    // for example, base 0, minus -20, plus 20
    // means legel angle value is from -20 to 20
    branchTemp->setAngleParameters(0, -50, 50);

    branchTemp->setLength(30);
    branchTemp->setGeneratingCount(20);
    branchTemp->setNoGenerationCount(3);
    branchTemp->setIsRootBranch(true);
    branchTemp->setGraphicScene(m_totemGraphicsScene_);

    branchTemp->setLinePosStart(startPos);

    connect(branchTemp, SIGNAL(signalNewBranch(SelfGenerateBranch *)), this, SLOT(generateLeaves(SelfGenerateBranch *)));

    m_selfGenrateBranches_.push_back(branchTemp);
    branchTemp->startLineGenerating(startPos);


}


void TotemAnimatingWidget::generateLeaves(SelfGenerateBranch * leafBranch)
{
    connect(leafBranch, SIGNAL(signalNewBranch(SelfGenerateBranch *)), this, SLOT(generateLeaves(SelfGenerateBranch *)));

    m_selfGenrateBranches_.push_back(leafBranch);
    leafBranch->startLineGenerating(leafBranch->getLinePosStart());
}


void TotemAnimatingWidget::slotClearBranches(void)
{
    slotStopBranchGenerating();
    m_selfGenrateBranches_.clear();
    m_totemGraphicsScene_->clear();
}


void TotemAnimatingWidget::slotResumeBranchGenerating(void)
{

}


void TotemAnimatingWidget::slotStopBranchGenerating(void)
{
    for (SelfGenerateBranch* branchIt : m_selfGenrateBranches_)
    {
        branchIt->stopAnimation();
    }
}





