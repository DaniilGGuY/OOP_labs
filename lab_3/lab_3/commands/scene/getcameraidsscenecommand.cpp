#include "getcameraidsscenecommand.h"

GetCameraIdsSceneCommand::GetCameraIdsSceneCommand() : _ids(std::vector<size_t>()) {}

void GetCameraIdsSceneCommand::execute() { _ids = _scene_mg->getCameraIds(); }

std::vector<size_t> GetCameraIdsSceneCommand::getIds() const { return _ids; }
