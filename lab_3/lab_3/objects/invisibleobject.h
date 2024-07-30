#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "object.h"

class InvisibleObject : public Object
{
public:
    InvisibleObject();
    virtual ~InvisibleObject() = 0;

    virtual bool isComposite() const;
    virtual bool isVisible() const;
};

#endif // INVISIBLEOBJECT_H
