#ifndef BASECONTAINER_H
#define BASECONTAINER_H

#include <memory>

class BaseContainer
{
public:
    virtual ~BaseContainer() = 0;
    virtual bool empty() const;
    virtual size_t size() const;
protected:
    size_t len = 0;
};

#include "basecontainer.cpp"

#endif // BASECONTAINER_H
