#ifndef BASEOBJECTCOMMAND_H
#define BASEOBJECTCOMMAND_H

#include "commands/basecommand.h"

class BaseObjectCommand : public BaseCommand
{
public:
    BaseObjectCommand() = default;
    virtual ~BaseObjectCommand() = 0;
};

#endif // BASEOBJECTCOMMAND_H
