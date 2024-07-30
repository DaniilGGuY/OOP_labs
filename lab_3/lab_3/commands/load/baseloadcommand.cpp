#include "baseloadcommand.h"

BaseLoadCommand::~BaseLoadCommand() {}

size_t BaseLoadCommand::getDirectorId() { return _director_id; }

size_t BaseLoadCommand::getReaderId() { return _reader_id; }
