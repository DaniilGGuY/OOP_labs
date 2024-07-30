#include "setcameracommand.h"

SetCameraCommand::SetCameraCommand(size_t id) : _id(id) {}

void SetCameraCommand::execute() { _scene_mg->setCamera(_id); }
