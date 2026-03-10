#ifndef SelfGenerateBranch_H
#define SelfGenerateBranch_H

#include <QDebug>
#include <QObject>
#include <QPointF>
#include <QList>
#include <QGraphicsLineItem>
#include <QPropertyAnimation>

#include "singlesimplebranch.h"

// Task:
// 1. Finish the TBD and slots
// 2. Refactor

// TBD:
// 1. Create enum for the state of current generation
//    0 - stop, 1 - paused, 2 - active, 4 - reserved


class SelfGenerateBranch : public QObject
{
    Q_OBJECT

public:


    enum GENERATION_STATE
    {
        GENERATION_STOPPED = 0,
        GENERATION_PAUSED  = 1,
        GENERATION_ACTIVE  = 2,
        RESERVED
    };

    SelfGenerateBranch(QObject * parent = nullptr);
    virtual ~SelfGenerateBranch();

    void setGraphicsParent(QGraphicsItem * graphicsParent = nullptr);

    QPointF getLinePosStart(void);
    void setLinePosStart(QPointF linePosStart);
    QPointF getLinePosEnd(void);
    void setLinePosEnd(QPointF linePosEnd);

    void refreshGraphicsLinePosition(void);

    QGraphicsLineItem * getGraphicsItem(void);

    void setGraphicsLine(qreal x1, qreal y1, qreal x2, qreal y2);

    void startLineGenerating(QPointF startPos);

    void setSingleAnimationDuration(int durationTime);

    void setAngleParameters(int baseAngle, int startAngle, int endAngle);

    void setLength(double length);

    void setGeneratingCount(int count);

    void setGraphicScene(QGraphicsScene * branchScene);

    int getNoGenerationCount(void);
    void setNoGenerationCount(int count);

    bool isRootBranch(void);
    void setIsRootBranch(bool isRoot);

    // This return the current process of generation
    // the return is useful for when need calculation the value of parameter,
    // which will be passed to its leaves.
    // The return value is a double, tell the rest rate of the whole generation
    double getGenerationProcess(void);

    // Get calculated length for current generation of the branch
    double getDynamicLength(void);

    // TBD
    // To set the calculated angle paramaters, for the leaves
    void setDynamicAngleParametersForLeaves(SingleSimpleBranch *);

    // Temporary done method
    void stopAnimation(void);

signals:

    /* the life itself shall decide which direction for its own next generation! */
    /* at the mean time, the outside environment decide whether its generation grown. */
    /* the passing object is more like the seed */
    void signalNewBranch(SelfGenerateBranch *);

private slots:

    // To be improved, depends on the state of generation
    // Continue the generation or stop it
    // The "pause" and "resuem" will be on the backlog
    void singleGenerationStep(void);

    void generatingBranches(void);

    /* Using parameter instead of Object here */
    /* To indicate the properites of next generation */
    void generateLeafBranch(QPointF startPos,  int parentSelectedAngle,
                            SelfGenerateBranch * parentBranch);

private:

    QPointF m_linePosStart_;
    QPointF m_linePosEnd_;


    // unit = ms
    int m_singleLineDuration_;

    int m_baseAngle_;
    int m_angleMinus_;
    int m_anglePlus_;

    // each single branch length
    double m_length_;

    // indicate whole generation count
    int m_generationCount_;

    // indicate generating state
    // not used yet, but add this parameter first
    // for extending the functionality in the future
    GENERATION_STATE m_state_;

    // indicate current generation
    // start from 0
    // to the value of the m_generationCount_
    int m_currentGeneration_;

    // below which will not generate the leaves
    int m_noGenerationCount_;

    // no leaf branch gengration on root when below the m_noGenerationCount_
    bool m_isRootBranch_;

    // only for the method setDynamicAngleParametersForLeaves
    // To pass the calculatedAngle to the next generation
    // Currently, it is type - int
    int m_lastBranchAngle_;

    // Groß Parameter

    QGraphicsLineItem * m_graphicsLineItem_;

    QPropertyAnimation * m_selfGenerateAnimation_;

    QGraphicsScene * m_branchesScene_;

    QList<SingleSimpleBranch *> m_singleBranchList_;

};

#endif // SelfGenerateBranch_H
