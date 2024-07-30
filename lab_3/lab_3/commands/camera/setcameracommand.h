#ifndef SETCAMERACOMMAND_H
#define SETCAMERACOMMAND_H

#include "basecameracommand.h"

class SetCameraCommand : public BaseCameraCommand
{
public:
    SetCameraCommand() = delete;
    SetCameraCommand(size_t id);
    ~SetCameraCommand() = default;

    void execute() override;

private:
    size_t _id;
};

#endif // SETCAMERACOMMAND_H
