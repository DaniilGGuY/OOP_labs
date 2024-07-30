#include "basecontainer.h"

BaseContainer::~BaseContainer() {}

bool BaseContainer::empty() const
{
    return len == 0;
}

size_t BaseContainer::size() const
{
    return len;
}
