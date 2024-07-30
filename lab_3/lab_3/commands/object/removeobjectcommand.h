#ifndef REMOVEOBJECTCOMMAND_H
#define REMOVEOBJECTCOMMAND_H

#include "baseobjectcommand.h"

class RemoveObjectCommand : public BaseObjectCommand
{
public:
    RemoveObjectCommand() = delete;
    RemoveObjectCommand(size_t id);
    ~RemoveObjectCommand() = default;

    void execute() override;

private:
    size_t _id;
};

#endif // REMOVEOBJECTCOMMAND_H
