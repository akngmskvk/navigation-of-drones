#ifndef AREA_H
#define AREA_H

#include <QObject>

class Area
{
public:
    Area(quint32 xSize, quint32 ySize);

    quint32 xSize;
    quint32 ySize;
};

#endif // AREA_H
