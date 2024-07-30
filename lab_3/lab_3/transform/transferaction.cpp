#include "transferaction.h"

TransferAction::TransferAction(double dx, double dy, double dz) : TransformAction()
{
    _transform_matrix[3][0] = dx;
    _transform_matrix[3][1] = dy;
    _transform_matrix[3][2] = dz;
}
