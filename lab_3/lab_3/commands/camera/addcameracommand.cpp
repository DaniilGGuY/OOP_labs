#include "addcameracommand.h"

AddCameraCommand::AddCameraCommand(const Point &pos) : _pos(pos) {}

void AddCameraCommand::execute() { _scene_mg->addCamera(_pos); }
