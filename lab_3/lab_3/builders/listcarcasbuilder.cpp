#include "listcarcasbuilder.h"
#include "objects/structures/listcarcasstructure.h"

ListCarcasBuilder::ListCarcasBuilder(std::shared_ptr<CarcasReader> reader) : BaseCarcasBuilder(reader)
{
    _structure = std::make_shared<ListCarcasStructure>();
}
