#ifndef BASECARCASBUILDER_H
#define BASECARCASBUILDER_H

#include "objects/carcasmodel.h"
#include "objects/structures/carcasstructure.h"
#include "readers/carcasreader.h"

class BaseCarcasBuilder
{
public:
    BaseCarcasBuilder() = default;
    explicit BaseCarcasBuilder(std::shared_ptr<CarcasReader> reader);
    virtual ~BaseCarcasBuilder();

    virtual std::shared_ptr<CarcasModel> getModel();

    virtual void buildPoints();
    virtual void buildEdges();
    virtual void buildCenter();

    virtual bool isbuilt();

protected:
    std::shared_ptr<CarcasStructure> _structure;
    std::shared_ptr<CarcasReader> _reader;
};

#endif // BASECARCASBUILDER_H
