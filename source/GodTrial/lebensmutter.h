#ifndef LEBENSMUTTER_H
#define LEBENSMUTTER_H

#include <QObject>

class LebensMutter : public QObject
{
    Q_OBJECT
public:
    explicit LebensMutter(QObject *parent = nullptr);

signals:
};

#endif // LEBENSMUTTER_H
