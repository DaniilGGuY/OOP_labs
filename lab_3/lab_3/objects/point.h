#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point() = default;
    Point(double x, double y, double z);

    explicit Point(const Point &point) = default;
    Point &operator=(const Point &point) = default;

    Point(Point &&point) = default;
    Point &operator=(Point &&point) = default;

    ~Point() = default;

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setPoint(double x, double y, double z);
    void setPoint(const Point &point);

    double getX() const;
    double getY() const;
    double getZ() const;

    bool operator==(const Point &point) const;
    bool operator!=(const Point &point) const;

private:
    double _x;
    double _y;
    double _z;
};

#endif // POINT_H
