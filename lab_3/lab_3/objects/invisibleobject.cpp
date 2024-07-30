#include "invisibleobject.h"

InvisibleObject::InvisibleObject() {}

InvisibleObject::~InvisibleObject() {}

bool InvisibleObject::isComposite() const { return false; }

bool InvisibleObject::isVisible() const { return false; }
