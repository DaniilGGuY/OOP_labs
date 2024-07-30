#include "transformaction.h"

TransformAction::TransformAction() : _transform_matrix(SquareMatrix<double>(4, 0))
{
    _transform_matrix[0][0] = 1;
    _transform_matrix[1][1] = 1;
    _transform_matrix[2][2] = 1;
    _transform_matrix[3][3] = 1;
}

SquareMatrix<double>& TransformAction::getTransformMatrix() { return _transform_matrix; }

const SquareMatrix<double>& TransformAction::getTransformMatrix() const { return _transform_matrix; }

Point &TransformAction::transform(Point &point) const
{
    std::vector<double> col{point.getX(), point.getY(), point.getZ(), 1};
    std::vector<double> res = _transform_matrix.multiplyRight(col);
    point.setX(res[0]);
    point.setY(res[1]);
    point.setZ(res[2]);
    return point;
}
