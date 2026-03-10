#ifndef SINGLESIMPLEBRANCH_H
#define SINGLESIMPLEBRANCH_H

#include <QObject>
#include <QObject>
#include <QPointF>
#include <QGraphicsLineItem>
#include <QPropertyAnimation>

// Task
// 1. Refactor

class SingleSimpleBranch : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QPointF m_linePosStart_ READ getLinePosStart WRITE setLinePosStart)
    Q_PROPERTY(QPointF m_linePosEnd_ READ getLinePosEnd WRITE setLinePosEnd)

public:
    explicit SingleSimpleBranch(QObject *parent = nullptr);
    virtual ~SingleSimpleBranch();

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

    // this will not be used for now
    void setAngleParameters(int startAngle, int endAngle);

    void setAngle(int angle);
    int getSelectedAngle(void);

    void setLength(double length);

private:

    void generateEndPos(void);
    double generateEndPosX(int Angle);
    double generateEndPosY(int Angle);

    QPointF m_linePosStart_;
    QPointF m_linePosEnd_;
    QGraphicsLineItem * m_graphicsLineItem_;

    // unit = ms
    int m_singleLineDuration_;

    int m_AngleBegin_;
    int m_AngleEnd_;

    int m_selectedAngle_;

    double m_length_;

signals:

};

#endif // SINGLESIMPLEBRANCH_H
