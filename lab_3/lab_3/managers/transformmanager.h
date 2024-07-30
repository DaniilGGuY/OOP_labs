#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "transform/transformaction.h"
#include "objects/object.h"

class TransformManager
{
public:
    TransformManager() = default;
    ~TransformManager() = default;

    void transferObject(std::shared_ptr<Object> object, double dx, double dy, double dz);
    void scaleObject(std::shared_ptr<Object> object, double kx, double ky, double kz);
    void rotateObject(std::shared_ptr<Object> object, double x_angle, double y_angle, double z_angle);

    void transformObject(std::shared_ptr<Object> object, std::shared_ptr<TransformAction> action);
};

#endif // TRANSFORMMANAGER_H
