#include "basecarcasdirector.h"

BaseCarcasDirector::BaseCarcasDirector(std::shared_ptr<CarcasReader> reader)
    : _reader(reader) {}

BaseCarcasDirector::~BaseCarcasDirector() {}

std::shared_ptr<Object> BaseCarcasDirector::create()
{
    if (_reader)
    {
        _builder->buildPoints();
        _builder->buildEdges();
        _builder->buildCenter();
        return _builder->getModel();
    }

    return std::shared_ptr<Object>();
}
