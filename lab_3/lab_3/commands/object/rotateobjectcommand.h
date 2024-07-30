#ifndef ROTATEOBJECTCOMMAND_H
#define ROTATEOBJECTCOMMAND_H

#include "baseobjectcommand.h"

class RotateObjectCommand : public BaseObjectCommand
{
public:
    RotateObjectCommand() = delete;
    RotateObjectCommand(size_t id, double x_angle, double y_angle, double z_angle);
    ~RotateObjectCommand() = default;

    void execute() override;

private:
    size_t _id;
    double _x_angle;
    double _y_angle;
    double _z_angle;
};

#endif // ROTATEOBJECTCOMMAND_H
