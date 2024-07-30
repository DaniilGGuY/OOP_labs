#ifndef BASELOADCOMMANDDECORATOR_H
#define BASELOADCOMMANDDECORATOR_H

#include "baseloadcommand.h"

class BaseLoadCommandDecorator : public BaseLoadCommand
{
public:
    BaseLoadCommandDecorator(BaseLoadCommand &command);
    virtual ~BaseLoadCommandDecorator() = 0;

protected:
    BaseLoadCommand& _command;
};

#endif // BASELOADCOMMANDDECORATOR_H
