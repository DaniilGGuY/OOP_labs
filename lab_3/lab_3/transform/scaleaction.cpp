#include "scaleaction.h"
#include "transferaction.h"

ScaleAction::ScaleAction(double kx, double ky, double kz) : TransformAction()
{
    _transform_matrix[0][0] = kx;
    _transform_matrix[1][1] = ky;
    _transform_matrix[2][2] = kz;
}

ScaleAction::ScaleAction(double k) : TransformAction()
{
    _transform_matrix[0][0] = k;
    _transform_matrix[1][1] = k;
    _transform_matrix[2][2] = k;
}

ScaleAction::ScaleAction(const Point &point, double kx, double ky, double kz) : TransformAction()
{
    TransferAction center(-point.getX(), -point.getY(), -point.getZ());
    _transform_matrix *= center.getTransformMatrix();
    ScaleAction scale(kx, ky, kz);
    _transform_matrix *= scale.getTransformMatrix();
    TransferAction prev(point.getX(), point.getY(), point.getZ());
    _transform_matrix *= prev.getTransformMatrix();
}

ScaleAction::ScaleAction(const Point &point, double k) : TransformAction()
{
    TransferAction center(-point.getX(), -point.getY(), -point.getZ());
    _transform_matrix *= center.getTransformMatrix();
    ScaleAction scale(k);
    _transform_matrix *= scale.getTransformMatrix();
    TransferAction prev(point.getX(), point.getY(), point.getZ());
    _transform_matrix *= prev.getTransformMatrix();
}
