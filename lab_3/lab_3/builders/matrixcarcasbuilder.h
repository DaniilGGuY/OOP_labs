#ifndef MATRIXCARCASBUILDER_H
#define MATRIXCARCASBUILDER_H

#include "basecarcasbuilder.h"

class MatrixCarcasBuilder : public BaseCarcasBuilder
{
public:
    explicit MatrixCarcasBuilder(std::shared_ptr<CarcasReader> reader);
    ~MatrixCarcasBuilder() = default;
};

#endif // MATRIXCARCASBUILDER_H
