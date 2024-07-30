#ifndef MATRIXCARCASDIRECTOR_H
#define MATRIXCARCASDIRECTOR_H

#include "basecarcasdirector.h"

class MatrixCarcasDirector : public BaseCarcasDirector
{
public:
    explicit MatrixCarcasDirector(std::shared_ptr<CarcasReader> reader);
    ~MatrixCarcasDirector() = default;
};

#endif // MATRIXCARCASDIRECTOR_H
