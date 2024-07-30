#include "removecameracommand.h"

RemoveCameraCommand::RemoveCameraCommand(size_t id) : _id(id) {}

void RemoveCameraCommand::execute() { _scene_mg->removeCamera(_id); }
