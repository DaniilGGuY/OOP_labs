#ifndef LISTLOADCOMMAND_H
#define LISTLOADCOMMAND_H

#include "baseloadcommand.h"

class ListLoadCommand : public BaseLoadCommand
{
public:
    ListLoadCommand();
    virtual ~ListLoadCommand() = default;
    void execute() override;
};

#endif // LISTLOADCOMMAND_H
