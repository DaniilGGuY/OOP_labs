#include <cmath>

#include "rotateaction.h"
#include "transferaction.h"

RotateAction::RotateAction(double x_angle, double y_angle, double z_angle) : TransformAction()
{
    SquareMatrix<double> x_turn(4, 0), y_turn(4, 0), z_turn(4, 0);
    x_turn[0][0] = 1;
    x_turn[1][1] = cos(x_angle);
    x_turn[1][2] = sin(x_angle);
    x_turn[2][1] = -sin(x_angle);
    x_turn[2][2] = cos(x_angle);
    x_turn[3][3] = 1;

    y_turn[0][0] = cos(y_angle);
    y_turn[0][2] = -sin(y_angle);
    y_turn[1][1] = 1;
    y_turn[2][0] = sin(y_angle);
    y_turn[2][2] = cos(y_angle);
    y_turn[3][3] = 1;

    z_turn[0][0] = cos(z_angle);
    z_turn[0][1] = sin(z_angle);
    z_turn[1][0] = -sin(z_angle);
    z_turn[1][1] = cos(z_angle);
    z_turn[2][2] = 1;
    z_turn[3][3] = 1;

    _transform_matrix *= x_turn * y_turn * z_turn;
}

RotateAction::RotateAction(const Point &point, double x_angle, double y_angle, double z_angle) : TransformAction()
{
    TransferAction center(-point.getX(), -point.getY(), -point.getZ());
    _transform_matrix *= center.getTransformMatrix();
    RotateAction rotate(x_angle, y_angle, z_angle);
    _transform_matrix *= rotate.getTransformMatrix();
    TransferAction prev(point.getX(), point.getY(), point.getZ());
    _transform_matrix *= prev.getTransformMatrix();
}
