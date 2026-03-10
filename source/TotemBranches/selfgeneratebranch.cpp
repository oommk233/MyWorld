#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QtMath>
#include <QThread>
#include "selfgeneratebranch.h"

SelfGenerateBranch::SelfGenerateBranch(QObject * parent):
    QObject(parent),
    m_linePosStart_(),
    m_linePosEnd_(),
    m_singleLineDuration_(0),
    m_baseAngle_(0),
    m_angleMinus_(0),
    m_anglePlus_(0),
    m_length_(40),
    m_generationCount_(0),
    m_state_(GENERATION_STOPPED),
    m_currentGeneration_(0),
    m_noGenerationCount_(0),
    m_isRootBranch_(false),
    m_lastBranchAngle_(0),
    m_graphicsLineItem_(nullptr),
    m_selfGenerateAnimation_(nullptr),
    m_branchesScene_(nullptr),
    m_singleBranchList_()
{
    /* Each branch shall have its own Animation object */
    /* Each Animation object means one independent Animation generation */
    m_selfGenerateAnimation_ = new QPropertyAnimation(this);
    connect(m_selfGenerateAnimation_, SIGNAL(finished()), this, SLOT(singleGenerationStep()));

    m_graphicsLineItem_ = new QGraphicsLineItem(0, 0, 0, 0);
}


SelfGenerateBranch::~SelfGenerateBranch()
{

}


void SelfGenerateBranch::setGraphicsParent(QGraphicsItem * graphicsParent)
{
    this->m_graphicsLineItem_->setParentItem(graphicsParent);

    return;
}


QPointF SelfGenerateBranch::getLinePosStart(void)
{
    return m_linePosStart_;
}


void SelfGenerateBranch::setLinePosStart(QPointF linePosStart)
{
    m_linePosStart_ = linePosStart;
    refreshGraphicsLinePosition();
}


QPointF SelfGenerateBranch::getLinePosEnd(void)
{
    return m_linePosEnd_;
}


void SelfGenerateBranch::setLinePosEnd(QPointF linePosEnd)
{
    m_linePosEnd_ = linePosEnd;
    refreshGraphicsLinePosition();
}


void SelfGenerateBranch::refreshGraphicsLinePosition(void)
{
    m_graphicsLineItem_->setLine(m_linePosStart_.x(), m_linePosStart_.y(), m_linePosEnd_.x() ,m_linePosEnd_.y());
}


QGraphicsLineItem * SelfGenerateBranch::getGraphicsItem(void)
{
    return m_graphicsLineItem_;
}


void SelfGenerateBranch::setGraphicsLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    setLinePosStart(QPointF(x1, y1));
    setLinePosEnd(QPointF(x2, y2));

    refreshGraphicsLinePosition();
}


void SelfGenerateBranch::startLineGenerating(QPointF startPos)
{
    setLinePosStart(startPos);
    singleGenerationStep();
}


void SelfGenerateBranch::setSingleAnimationDuration(int durationTime)
{
    m_singleLineDuration_ = durationTime;
}


void SelfGenerateBranch::setAngleParameters(int baseAngle, int minusAngle, int plusAngle)
{
    m_baseAngle_ = baseAngle % 360;
    m_angleMinus_ = minusAngle % 360;
    m_anglePlus_ = plusAngle % 360;
}


void SelfGenerateBranch::setLength(double length)
{
    m_length_ = length;
}


void SelfGenerateBranch::setGeneratingCount(int count)
{
    m_generationCount_ = count;
    m_currentGeneration_ = 0;
}


void SelfGenerateBranch::setGraphicScene(QGraphicsScene * branchScene)
{
    m_branchesScene_ = branchScene;
}


int SelfGenerateBranch::getNoGenerationCount(void)
{
    return m_noGenerationCount_;
}


void SelfGenerateBranch::setNoGenerationCount(int count)
{
    m_noGenerationCount_ = count;
}


bool SelfGenerateBranch::isRootBranch(void)
{
    return m_isRootBranch_;
}


void SelfGenerateBranch::setIsRootBranch(bool isRoot)
{
    m_isRootBranch_ = isRoot;
}


double SelfGenerateBranch::getGenerationProcess(void)
{
    float currentProcess = 0.0;

    // Here is the int devide int, the result is int
    // But, both value shall not be the float or double
    // improve the algorithm, but not simply change from int to the double/float
    currentProcess = 1.0 - static_cast<float>(m_currentGeneration_) / m_generationCount_;

    return currentProcess;
}


double SelfGenerateBranch::getDynamicLength(void)
{
    // How to define the reasonable Leaf Length?
    // Shall consider the situations following:
    // 1.Root and Branch
    // 2.Leaf and endLeafPoint (might need )
    double getDynamicLength = 0.0;
    getDynamicLength = m_length_ * getGenerationProcess();

    return getDynamicLength;
}


void SelfGenerateBranch::setDynamicAngleParametersForLeaves(SingleSimpleBranch * singleBranchTemp)
{
    // Calculate the angleMinus and anglePlus base on the m_baseAngle
    // There shall be the main direction/shiftment towards the top of the screen

    // Current found no suitable method of the QRandomGenerator
    // The work around solution is to generate two numbers and have their average
    // to implement the shiftment of the random algorithm

    // 1. Der Kennzeichenwinkel(beide Richtung)...
    // 2. Der Ausgleichwinkel...
    // 3. Der Ausgleichwinkel ist das DNA alles Asts/Blatts...

    // targetAngle = randomGenerate(angle) + shiftmentCalculation(AngelShiftment)
    // currently do this inside this method, instead of create and call two methods

    // The algorithm, please check the file HandNote_20230307.jpg

    /* ------------------------------------------------------------------------- */
    // randomGenerate(angle)
    int angleMinusTemp = m_baseAngle_ + m_angleMinus_;
    int anglePlusTemp = m_baseAngle_ + m_anglePlus_;

    if (angleMinusTemp > anglePlusTemp)
    {
        angleMinusTemp = m_baseAngle_ + m_anglePlus_;
        anglePlusTemp = m_baseAngle_ + m_angleMinus_;;
    }

    int randomGenVar = 0;

    if ( (m_currentGeneration_ > m_noGenerationCount_) || !m_isRootBranch_ )
    {
        randomGenVar = QRandomGenerator::global()->bounded(angleMinusTemp, anglePlusTemp);
    }

    // shiftmentCalculation(baseShiftment)
    int shiftmentAngle = 0;
    int upPart = ( qAbs(m_angleMinus_) * qAbs(m_lastBranchAngle_) ) * 0.10;
    int bottomPart = 90 + qAbs(m_angleMinus_);

    if( bottomPart != 0)
    {
        shiftmentAngle = static_cast<double>(upPart) / bottomPart;
    }
    else
    {
        shiftmentAngle = 0;
    }

    int targetAngleVar = 0;

    if( randomGenVar != 0 )
    {
        targetAngleVar = randomGenVar + ( -randomGenVar / qAbs(randomGenVar) ) * shiftmentAngle;
    }
    singleBranchTemp->setAngle(targetAngleVar);

}


void SelfGenerateBranch::stopAnimation(void)
{
    this->m_selfGenerateAnimation_->stop();
}


void SelfGenerateBranch::singleGenerationStep(void)
{
    if (m_generationCount_ > m_currentGeneration_)
    {
        generatingBranches();
    }
}


// Add "connect" function here, to connect leaf generation.
void SelfGenerateBranch::generatingBranches(void)
{
    SingleSimpleBranch * singleTemp = new SingleSimpleBranch(this);


    // shall not set angel parameters
    // instead, call setDynamicAngle...., to calculate the target angle dynamicly
    //singleTemp->setAngleParameters(angleMinusTemp, anglePlusTemp);
    setDynamicAngleParametersForLeaves(singleTemp);
    m_lastBranchAngle_ = singleTemp->getSelectedAngle();

    singleTemp->setLength(getDynamicLength());
    singleTemp->startLineGenerating(m_linePosStart_);
    m_singleBranchList_.append(singleTemp);

    m_branchesScene_->addItem(singleTemp->getGraphicsItem());

    m_linePosStart_ = singleTemp->getLinePosEnd();

    m_currentGeneration_++;

    m_selfGenerateAnimation_->setTargetObject(singleTemp);
    m_selfGenerateAnimation_->setPropertyName(QByteArray("m_linePosEnd_"));
    m_selfGenerateAnimation_->setStartValue(singleTemp->getLinePosStart());
    m_selfGenerateAnimation_->setEndValue(singleTemp->getLinePosEnd());
    m_selfGenerateAnimation_->start();

    /* if generated new leaf then-> */
    if(m_currentGeneration_ > m_noGenerationCount_)
    {
        generateLeafBranch(m_linePosStart_, m_lastBranchAngle_, this);
    }

}


void SelfGenerateBranch::generateLeafBranch(QPointF startPos,  int parentSelectedAngle,
                                            SelfGenerateBranch * parentBranch)
{
    // This branch base Angle is depended on its parent "Single Branch selected Angle"
    // So that the parameter is from the SingleGenerateBranch
    // Instead of the SelfGenerateBranch

    SelfGenerateBranch * leafBranch = new SelfGenerateBranch();
    leafBranch->setAngleParameters(parentSelectedAngle, m_angleMinus_, m_anglePlus_);

    int leafGenerationCount = m_generationCount_ - m_currentGeneration_;
    leafBranch->setGeneratingCount(leafGenerationCount);
    leafBranch->setNoGenerationCount(2);
    leafBranch->setGraphicScene(m_branchesScene_);
    leafBranch->setLinePosStart(startPos);

    double leafLength = getDynamicLength() + 5;
    leafBranch->setLength(leafLength);

    emit signalNewBranch(leafBranch);


}
























