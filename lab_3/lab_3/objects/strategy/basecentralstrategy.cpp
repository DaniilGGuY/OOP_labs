#include "basecentralstrategy.h"

BaseCentralStrategy::~BaseCentralStrategy() {}

Point CenterStrategy::calcCenter(std::vector<Point> points) const
{
    if (points.empty())
        return Point();

    double minX = points[0].getX(), minY = points[0].getY(), minZ = points[0].getZ();
    double maxX = minX, maxY = minY, maxZ = minZ;

    for (auto &it : points)
    {
        if (minX > it.getX())
            minX = it.getX();
        if (minY > it.getY())
            minY = it.getY();
        if (minZ > it.getZ())
            minZ = it.getZ();
        if (maxX < it.getX())
            maxX = it.getX();
        if (maxY < it.getY())
            maxY = it.getY();
        if (maxZ < it.getZ())
            maxZ = it.getZ();
    }

    return Point((minX + maxX) / 2, (minY + maxY) / 2, (maxZ + minZ) / 2);
}
