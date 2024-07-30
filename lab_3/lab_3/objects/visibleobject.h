#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "object.h"

class VisibleObject : public Object
{
public:
    VisibleObject();
    virtual ~VisibleObject() = 0;

    virtual bool isComposite() const;
    virtual bool isVisible() const;
};

#endif // VISIBLEOBJECT_H
