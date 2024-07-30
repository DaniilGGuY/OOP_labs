#ifndef GETCAMERAIDSSCENECOMMAND_H
#define GETCAMERAIDSSCENECOMMAND_H

#include "basescenecommand.h"

class GetCameraIdsSceneCommand : public BaseSceneCommand
{
public:
    GetCameraIdsSceneCommand();
    ~GetCameraIdsSceneCommand() = default;

    void execute() override;
    std::vector<size_t> getIds() const;

private:
    std::vector<size_t> _ids;
};

#endif // GETCAMERAIDSSCENECOMMAND_H
