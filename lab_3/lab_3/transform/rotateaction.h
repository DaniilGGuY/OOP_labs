#ifndef ROTATEACTION_H
#define ROTATEACTION_H

#include "transformaction.h"

class RotateAction : public TransformAction
{
public:
    RotateAction() = default;
    RotateAction(double x_angle, double y_angle, double z_angle);
    RotateAction(const Point &point, double x_angle, double y_angle, double z_angle);
    virtual ~RotateAction() = default;
};

#endif // ROTATEACTION_H
