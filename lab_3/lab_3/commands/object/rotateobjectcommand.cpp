#include "rotateobjectcommand.h"

RotateObjectCommand::RotateObjectCommand(size_t id, double x_angle, double y_angle, double z_angle)
    : _id(id), _x_angle(x_angle), _y_angle(y_angle), _z_angle(z_angle) {}

void RotateObjectCommand::execute() { _transform_mg->rotateObject(_scene_mg->getObject(_id), _x_angle, _y_angle, _z_angle); }
