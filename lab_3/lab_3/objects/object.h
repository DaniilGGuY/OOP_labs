#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include <vector>

#include "point.h"

size_t getObjectId();

class Visitor;

class Object
{
public:
    using iterator = std::vector<std::shared_ptr<Object>>::iterator;

public:
    Object();
    virtual ~Object() = 0;

    virtual iterator begin();
    virtual iterator end();

    virtual void add(std::shared_ptr<Object> obj);
    virtual void remove(const iterator &it);

    virtual std::shared_ptr<Object> clone() const;
    virtual void accept(std::shared_ptr<Visitor> visitor);

    virtual size_t getId() const;

    virtual Point getCenter() const = 0;
    virtual bool isComposite() const = 0;
    virtual bool isVisible() const = 0;

protected:
    size_t _id = 0;
};

#endif // OBJECT_H
