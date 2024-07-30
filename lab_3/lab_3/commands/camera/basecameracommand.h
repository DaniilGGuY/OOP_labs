#ifndef BASECAMERACOMMAND_H
#define BASECAMERACOMMAND_H

#include "commands/basecommand.h"

class BaseCameraCommand : public BaseCommand
{
public:
    BaseCameraCommand() = default;
    virtual ~BaseCameraCommand() = 0;
};

#endif // BASECAMERACOMMAND_H
