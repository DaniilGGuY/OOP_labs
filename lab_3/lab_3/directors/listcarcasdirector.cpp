#include "listcarcasdirector.h"
#include "builders/listcarcasbuilder.h"

ListCarcasDirector::ListCarcasDirector(std::shared_ptr<CarcasReader> reader) : BaseCarcasDirector(reader)
{
    _builder = std::make_shared<ListCarcasBuilder>(_reader);
}
