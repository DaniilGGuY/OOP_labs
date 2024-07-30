#ifndef TXTLOADCOMMANDDECORATOR_H
#define TXTLOADCOMMANDDECORATOR_H

#include "baseloadcommanddecorator.h"

class TxtLoadCommandDecorator : public BaseLoadCommandDecorator
{
public:
    TxtLoadCommandDecorator() = delete;
    TxtLoadCommandDecorator(BaseLoadCommand &command, const char *filename);
    ~TxtLoadCommandDecorator() = default;

    void execute() override;

private:
    const char *_filename;
};

#endif // TXTLOADCOMMANDDECORATOR_H
