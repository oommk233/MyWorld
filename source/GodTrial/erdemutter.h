#ifndef ERDEMUTTER_H
#define ERDEMUTTER_H

#include <QObject>

class ErdeMutter : public QObject
{
    Q_OBJECT
public:
    explicit ErdeMutter(QObject *parent = nullptr);

signals:
};

#endif // ERDEMUTTER_H
