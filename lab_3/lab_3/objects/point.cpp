#include "point.h"

Point::Point(double x, double y, double z) : _x(x), _y(y), _z(z) {}

void Point::setX(double x) { _x = x; }

void Point::setY(double y) { _y = y; }

void Point::setZ(double z) { _z = z; }

void Point::setPoint(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

void Point::setPoint(const Point &point)
{
    _x = point._x;
    _y = point._y;
    _z = point._z;
}

double Point::getX() const { return _x; }

double Point::getY() const { return _y; }

double Point::getZ() const { return _z; }

bool Point::operator==(const Point &point) const
{
    return (_x == point._x && _y == point._y && _z == point._z);
}

bool Point::operator!=(const Point &point) const
{
    return (_x != point._x || _y != point._y || _z != point._z);
}
