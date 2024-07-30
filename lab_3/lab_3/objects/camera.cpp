#include "camera.h"

Camera::Camera() : _self(Point()), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

Camera::Camera(double x, double y, double z) : _self(Point(x, y, z)), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

Camera::Camera(const Point &point) : _self(point), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

Camera::Camera(const Camera &camera) : _self(camera._self), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

void Camera::accept(std::shared_ptr<Visitor> visitor) { visitor->visit(*this); }

Point Camera::getCenter() const
{
    Point copy(_self);
    return copy;
}

bool Camera::isComposite() const { return false; }
