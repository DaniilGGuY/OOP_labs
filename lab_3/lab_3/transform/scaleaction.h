#ifndef SCALEACTION_H
#define SCALEACTION_H

#include "transformaction.h"

class ScaleAction : public TransformAction
{
public:
    ScaleAction() = default;
    ScaleAction(double kx, double ky, double kz);
    ScaleAction(double k);
    ScaleAction(const Point &point, double kx, double ky, double kz);
    ScaleAction(const Point &point, double k);
    virtual ~ScaleAction() = default;
};

#endif // SCALEACTION_H
