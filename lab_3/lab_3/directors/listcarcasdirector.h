#ifndef LISTCARCASDIRECTOR_H
#define LISTCARCASDIRECTOR_H

#include "basecarcasdirector.h"

class ListCarcasDirector : public BaseCarcasDirector
{
public:
    explicit ListCarcasDirector(std::shared_ptr<CarcasReader> reader);
    ~ListCarcasDirector() = default;
};

#endif // LISTCARCASDIRECTOR_H
