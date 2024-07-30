#ifndef SHIFTOBJECTCOMMAND_H
#define SHIFTOBJECTCOMMAND_H

#include "baseobjectcommand.h"

class ShiftObjectCommand : public BaseObjectCommand
{
public:
    ShiftObjectCommand() = delete;
    ShiftObjectCommand(size_t id, double dx, double dy, double dz);
    ~ShiftObjectCommand() = default;

    void execute() override;

private:
    size_t _id;
    double _dx;
    double _dy;
    double _dz;
};

#endif // SHIFTOBJECTCOMMAND_H
