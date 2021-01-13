#ifndef DRONE_H
#define DRONE_H

#include <QObject>
#include <QDebug>

#include "area.h"

class Drone
{
public:
    Drone(Area area, quint32 xCor, quint32 yCor, QChar direction);

    quint32 getXCoordinate() const;
    void setXCoordinate(const quint32 &value);

    quint32 getYCoordinate() const;
    void setYCoordinate(const quint32 &value);

    QChar getDirection() const;
    void setDirection(const QChar &value);

    void movement(QChar directive);
    void printStatics();

private:
    Area area;
    quint32 xCoordinate;
    quint32 yCoordinate;
    QChar direction; // E, W, N, S

    void changeDirection(QChar newDirection);
    void makeMove();
};

#endif // DRONE_H
