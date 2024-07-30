#ifndef BASECARCASDIRECTOR_H
#define BASECARCASDIRECTOR_H

#include "basedirector.h"
#include "builders/basecarcasbuilder.h"
#include "readers/carcasreader.h"
#include "objects/strategy/basecentralstrategy.h"

class BaseCarcasDirector : public BaseDirector
{
public:
    BaseCarcasDirector(std::shared_ptr<CarcasReader> reader);
    virtual ~BaseCarcasDirector() = 0;

    virtual std::shared_ptr<Object> create();

protected:
    std::shared_ptr<BaseCarcasBuilder> _builder;
    std::shared_ptr<CarcasReader> _reader;
};

#endif // BASECARCASDIRECTOR_H
