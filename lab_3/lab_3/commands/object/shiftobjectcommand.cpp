#include "shiftobjectcommand.h"

ShiftObjectCommand::ShiftObjectCommand(size_t id, double dx, double dy, double dz) : _id(id), _dx(dx), _dy(dy), _dz(dz) {}

void ShiftObjectCommand::execute() { _transform_mg->transferObject(_scene_mg->getObject(_id), _dx, _dy, _dz); }
