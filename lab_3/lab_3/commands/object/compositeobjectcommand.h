#ifndef COMPOSITEOBJECTCOMMAND_H
#define COMPOSITEOBJECTCOMMAND_H

#include "baseobjectcommand.h"

class CompositeObjectCommand : public BaseObjectCommand
{
public:
    CompositeObjectCommand() = delete;
    CompositeObjectCommand(std::vector<size_t> ids);
    ~CompositeObjectCommand() = default;

    void execute() override;

private:
    std::vector<size_t> _ids;
};

#endif // COMPOSITEOBJECTCOMMAND_H
