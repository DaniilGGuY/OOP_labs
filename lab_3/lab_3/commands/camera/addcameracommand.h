#ifndef ADDCAMERACOMMAND_H
#define ADDCAMERACOMMAND_H

#include "basecameracommand.h"

class AddCameraCommand : public BaseCameraCommand
{
public:
    AddCameraCommand() = delete;
    AddCameraCommand(const Point &pos);
    ~AddCameraCommand() = default;

    void execute() override;

private:
    Point _pos;
};

#endif // ADDCAMERACOMMAND_H
