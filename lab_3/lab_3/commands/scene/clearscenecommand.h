#ifndef CLEARSCENECOMMAND_H
#define CLEARSCENECOMMAND_H

#include "basescenecommand.h"

class ClearSceneCommand : public BaseSceneCommand
{
public:
    ClearSceneCommand() = default;
    ~ClearSceneCommand() = default;

    void execute() override;
};

#endif // CLEARSCENECOMMAND_H
