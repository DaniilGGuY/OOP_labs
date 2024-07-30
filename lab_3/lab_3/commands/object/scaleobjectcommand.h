#ifndef SCALEOBJECTCOMMAND_H
#define SCALEOBJECTCOMMAND_H

#include "baseobjectcommand.h"

class ScaleObjectCommand : public BaseObjectCommand
{
public:
    ScaleObjectCommand() = delete;
    ScaleObjectCommand(size_t id, double kx, double ky, double kz);
    ~ScaleObjectCommand() = default;

    void execute() override;

private:
    size_t _id;
    double _kx;
    double _ky;
    double _kz;
};

#endif // SCALEOBJECTCOMMAND_H
