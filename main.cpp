#include <QDebug>

#include "drone.h"
#include "area.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QTextStream qtin(stdin);

    quint32 xSizeArea = 0;
    quint32 ySizeArea = 0;
    quint32 droneCount = 0;

    // first gets the area size
    qDebug() << "Upper-right coordinates of the area (e.g., 5 5): ";
    qtin >> xSizeArea >> ySizeArea;
    // gets count of drones
    qDebug() << "Count of drones (e.g., 2): ";
    qtin >> droneCount;

    // declare area with its size paramaters
    Area area(xSizeArea, ySizeArea);

    for (uint i = 0; i < droneCount; i++)
    {
        quint32 droneXCoordinate = 0;
        quint32 droneYCoordinate = 0;
        QString droneDirection = "E";
        QString moves;

        // gets drone's initial coordinates and its direction
        qDebug() << i+1 << ". drone's initial position (e.g., 1 2 N): ";
        qtin >> droneXCoordinate >> droneYCoordinate >> droneDirection;
        // gets the movements
        qDebug() << i+1 << ". drone's movement series (e.g., LMLMLMLMM): ";
        qtin >> moves;

        Drone* drone = new Drone(area, droneXCoordinate, droneYCoordinate, droneDirection.at(0));

        for (auto directive : moves)
        {
            // make movements according to movemenet list
            drone->movement(directive);
        }

        // print the final position of the drone
        qDebug() << "\n----------------------------------------------";
        qDebug() << i+1 <<". drone's final position: ";
        drone->printStatics();
        qDebug() << "----------------------------------------------\n";

        delete drone;
    }

    return 0;
}
