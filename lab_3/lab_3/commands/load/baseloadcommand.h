#ifndef BASELOADCOMMAND_H
#define BASELOADCOMMAND_H

#include "commands/basecommand.h"

class BaseLoadCommand : public BaseCommand
{
public:
    BaseLoadCommand() = default;
    virtual ~BaseLoadCommand() = 0;

    size_t getDirectorId();
    size_t getReaderId();

protected:
    size_t _reader_id;
    size_t _director_id;
};

#endif // BASELOADCOMMAND_H
