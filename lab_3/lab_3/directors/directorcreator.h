#ifndef DIRECTORCREATOR_H
#define DIRECTORCREATOR_H

#include "basedirectorcreator.h"
#include "listcarcasdirector.h"
#include "matrixcarcasdirector.h"

template <typename Base, typename Deriv, typename... Args>
class DirectorCreator : public BaseDirectorCreatorTemplate<Base, Args...>
{
public:
    virtual ~DirectorCreator() = default;
    virtual std::shared_ptr<Base> create(Args&&... args);
};

using ListCarcasDirectorCreator = DirectorCreator<BaseCarcasDirector, ListCarcasDirector, std::shared_ptr<CarcasReader>>;
using MatrixCarcasDirectorCreator = DirectorCreator<BaseCarcasDirector, MatrixCarcasDirector, std::shared_ptr<CarcasReader>>;

#include "directorcreator.hpp"

#endif // DIRECTORCREATOR_H
