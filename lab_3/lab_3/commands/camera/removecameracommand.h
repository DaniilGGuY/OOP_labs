#ifndef REMOVECAMERACOMMAND_H
#define REMOVECAMERACOMMAND_H

#include "basecameracommand.h"

class RemoveCameraCommand : public BaseCameraCommand
{
public:
    RemoveCameraCommand() = delete;
    RemoveCameraCommand(size_t id);
    ~RemoveCameraCommand() = default;

    void execute() override;

private:
    size_t _id;
};

#endif // REMOVECAMERACOMMAND_H
