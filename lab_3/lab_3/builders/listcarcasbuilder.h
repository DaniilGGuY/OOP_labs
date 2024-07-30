#ifndef LISTCARCASBUILDER_H
#define LISTCARCASBUILDER_H

#include "basecarcasbuilder.h"

class ListCarcasBuilder : public BaseCarcasBuilder
{
public:
    explicit ListCarcasBuilder(std::shared_ptr<CarcasReader> reader);
    ~ListCarcasBuilder() = default;
};

#endif // LISTCARCASBUILDER_H
