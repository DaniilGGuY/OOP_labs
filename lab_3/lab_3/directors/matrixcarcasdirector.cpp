#include "matrixcarcasdirector.h"
#include "builders/matrixcarcasbuilder.h"

MatrixCarcasDirector::MatrixCarcasDirector(std::shared_ptr<CarcasReader> reader) : BaseCarcasDirector(reader)
{
    _builder = std::make_shared<MatrixCarcasBuilder>(_reader);
}

