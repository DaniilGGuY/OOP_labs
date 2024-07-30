#ifndef GETOBJECTIDSSCENECOMMAND_H
#define GETOBJECTIDSSCENECOMMAND_H

#include "basescenecommand.h"

class GetObjectIdsSceneCommand : public BaseSceneCommand
{
public:
    GetObjectIdsSceneCommand();
    ~GetObjectIdsSceneCommand() = default;

    void execute() override;
    std::vector<size_t> getIds() const;

private:
    std::vector<size_t> _ids;
};

#endif // GETOBJECTIDSSCENECOMMAND_H
