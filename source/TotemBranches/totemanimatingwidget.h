#ifndef TOTEMANIMATINGWIDGET_H
#define TOTEMANIMATINGWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <QPropertyAnimation>

#include "selfgeneratebranch.h"

// Task：
// 1. Finish the TBD slots
// 2. Refactor

class TotemAnimatingWidget : public QWidget
{
    Q_OBJECT
public:
    TotemAnimatingWidget(QWidget *parent = nullptr);
    virtual ~TotemAnimatingWidget();

    void showWidget(void);
    void initialization(void);
    void startAnimation(void);
    void stopAnimation(void);

    QPointF getMainBranchStartPos(void);
    void setMainBranchStartPos(QPointF linePosStart);

signals:

public slots:

    void startGenerating(void);

    void generateLeaves(SelfGenerateBranch *);

    void slotClearBranches(void);

private slots:

    // TBD slots
    void slotResumeBranchGenerating(void);


    void slotStopBranchGenerating(void);

private:

    void generateBaseView(void);

    /* This is for the root */
    void generateLoop(QPointF startPos);

    int m_generatingCount_;

    int m_singleLineLength_;

    // this is the ground/grand line
    SelfGenerateBranch * m_baseBranch_;

    QGraphicsScene * m_totemGraphicsScene_;
    QGraphicsView * m_totemGraphicsView_;

    QList<SelfGenerateBranch*> m_selfGenrateBranches_;



};

#endif // TOTEMANIMATINGWIDGET_H
