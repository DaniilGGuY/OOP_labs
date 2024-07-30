#include "basecarcasbuilder.h"

BaseCarcasBuilder::BaseCarcasBuilder(std::shared_ptr<CarcasReader> reader) : _reader(reader) { _reader->open(); }

BaseCarcasBuilder::~BaseCarcasBuilder()
{
    if (_reader && _reader->isOpen())
        _reader->close();
}

std::shared_ptr<CarcasModel> BaseCarcasBuilder::getModel() { return std::make_shared<CarcasModel>(_structure); }

void BaseCarcasBuilder::buildPoints()
{
    if (_reader)
    {
        auto points = _reader->readPoints();
        for (auto &p : points)
            _structure->addPoint(p);
    }
}

void BaseCarcasBuilder::buildEdges()
{
    if (_reader)
    {
        auto edges = _reader->readEdges();
        for (auto &e : edges)
            _structure->addEdge(e);
    }
}

void BaseCarcasBuilder::buildCenter()
{
    if (_reader)
        _structure->setCenter(_reader->readCenter());
}

bool BaseCarcasBuilder::isbuilt() { return _structure->getPoints().size() != 0; }
