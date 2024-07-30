#include "getobjectidsscenecommand.h"

GetObjectIdsSceneCommand::GetObjectIdsSceneCommand() : _ids(std::vector<size_t>()) {}

void GetObjectIdsSceneCommand::execute() { _ids = _scene_mg->getObjectIds(); }

std::vector<size_t> GetObjectIdsSceneCommand::getIds() const { return _ids; }
