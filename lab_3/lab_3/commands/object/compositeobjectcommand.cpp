#include "compositeobjectcommand.h"

CompositeObjectCommand::CompositeObjectCommand(std::vector<size_t> ids) : _ids(ids) {}

void CompositeObjectCommand::execute() { _scene_mg->makeComposite(_ids); }
