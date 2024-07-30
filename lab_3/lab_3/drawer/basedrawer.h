#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include "objects/point.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = 0;

    virtual void drawLine(const Point &p1, const Point &p2) = 0;
    virtual void clear() = 0;
};

#endif // BASEDRAWER_H
