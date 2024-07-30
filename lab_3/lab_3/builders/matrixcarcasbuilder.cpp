#include "matrixcarcasbuilder.h"
#include "objects/structures/matrixcarcasstructure.h"

MatrixCarcasBuilder::MatrixCarcasBuilder(std::shared_ptr<CarcasReader> reader) : BaseCarcasBuilder(reader)
{
    _structure = std::make_shared<MatrixCarcasStructure>();
}
