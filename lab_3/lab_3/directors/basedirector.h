#ifndef BASEDIRECTOR_H
#define BASEDIRECTOR_H

#include "objects/object.h"

class BaseDirector
{
public:
    BaseDirector() = default;
    virtual ~BaseDirector() = 0;

    virtual std::shared_ptr<Object> create() = 0;
};

#endif // BASEDIRECTOR_H
