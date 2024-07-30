#include "txtloadcommanddecorator.h"

TxtLoadCommandDecorator::TxtLoadCommandDecorator(BaseLoadCommand &command, const char *filename)
    : BaseLoadCommandDecorator(command), _filename(filename)
{
    _command = command;
    _reader_id = TXT_FILE_READER_ID;
}

void TxtLoadCommandDecorator::execute()
{
    _command.execute();
    _director_id = _command.getDirectorId();
    _scene_mg->addObject(_load_mg->loadCarcas(_director_id, _reader_id, _filename));
}
