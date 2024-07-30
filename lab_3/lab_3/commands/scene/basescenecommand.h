#ifndef BASESCENECOMMAND_H
#define BASESCENECOMMAND_H

#include "commands/basecommand.h"

class BaseSceneCommand : public BaseCommand
{
public:
    BaseSceneCommand() = default;
    virtual ~BaseSceneCommand() = 0;
};

#endif // BASESCENECOMMAND_H
