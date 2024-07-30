#include "composite.h"
#include "strategy/basecentralstrategy.h"

Composite::Composite(std::vector<std::shared_ptr<Object>> objects) : _objects(objects) {}

Composite::iterator Composite::begin()
{
    return _objects.begin();
}

Composite::iterator Composite::end()
{
    return _objects.end();
}

void Composite::add(const std::shared_ptr<Object> obj)
{
    _objects.push_back(obj);
}

void Composite::remove(const Composite::iterator &it)
{
    _objects.erase(it);
}

std::shared_ptr<Object> Composite::clone() const
{
    std::shared_ptr<Composite> clone_composite = std::make_shared<Composite>();
    for (auto &it : _objects)
        clone_composite->add(it->clone());

    return clone_composite;
}

void Composite::accept(std::shared_ptr<Visitor> visitor)
{
    for (auto &it : _objects)
        it->accept(visitor);
}

Point Composite::getCenter() const
{
    std::vector<Point> centers;
    for (auto &it : _objects)
        centers.push_back(it->getCenter());

    CenterStrategy alg;
    return alg.calcCenter(centers);
}

bool Composite::isComposite() const
{
    return true;
}

bool Composite::isVisible() const
{
    return true;
}
