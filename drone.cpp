#include "drone.h"

Drone::Drone(Area area, quint32 xCor, quint32 yCor, QChar direction)
    : area(area)
    , xCoordinate(xCor)
    , yCoordinate(yCor)
    , direction(direction)
{

}

void Drone::movement(QChar directive)
{
    if ((directive == 'L') || (directive == 'R'))
    {
        changeDirection(directive);
    }
    else if (directive == 'M')
    {
        makeMove();
    }
    else
    {
        qDebug() << "Undefined directive!";
    }
}

void Drone::changeDirection(QChar newDirection)
{
    QChar direction = this->getDirection();

    if (newDirection == 'L')
    {
        if (direction == 'E')
        {
            this->setDirection('N');
        }
        else if (direction == 'S')
        {
            this->setDirection('E');
        }
        else if (direction == 'W')
        {
            this->setDirection('S');
        }
        else if (direction == 'N')
        {
            this->setDirection('W');
        }
    }
    else if (newDirection == 'R')
    {
        if (direction == 'E')
        {
            this->setDirection('S');
        }
        else if (direction == 'S')
        {
            this->setDirection('W');
        }
        else if (direction == 'W')
        {
            this->setDirection('N');
        }
        else if (direction == 'N')
        {
            this->setDirection('E');
        }
    }
}

void Drone::makeMove()
{
    QChar direction = this->getDirection();

    if ((direction == 'E') && (this->getXCoordinate() < this->area.xSize))
    {
        this->setXCoordinate(this->getXCoordinate() + 1);
    }
    else if ((direction == 'S') && (this->getYCoordinate() > 0))
    {
        this->setYCoordinate(this->getYCoordinate() - 1);
    }
    else if ((direction == 'W') && (this->getXCoordinate() > 0))
    {
        this->setXCoordinate(this->getXCoordinate() - 1);
    }
    else if ((direction == 'N') && (this->getYCoordinate() < this->area.ySize))
    {
        this->setYCoordinate(this->getYCoordinate() + 1);
    }
}

void Drone::printStatics()
{
    qDebug() << this->getXCoordinate() << this->getYCoordinate() << this->getDirection().toLatin1();
}

quint32 Drone::getXCoordinate() const
{
    return xCoordinate;
}

void Drone::setXCoordinate(const quint32 &value)
{
    xCoordinate = value;
}

quint32 Drone::getYCoordinate() const
{
    return yCoordinate;
}

void Drone::setYCoordinate(const quint32 &value)
{
    yCoordinate = value;
}

QChar Drone::getDirection() const
{
    return direction;
}

void Drone::setDirection(const QChar &value)
{
    direction = value;
}
