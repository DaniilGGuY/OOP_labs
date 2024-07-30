#include "scaleobjectcommand.h"

ScaleObjectCommand::ScaleObjectCommand(size_t id, double kx, double ky, double kz) : _id(id), _kx(kx), _ky(ky), _kz(kz) {}

void ScaleObjectCommand::execute() { _transform_mg->scaleObject(_scene_mg->getObject(_id), _kx, _ky, _kz); }
