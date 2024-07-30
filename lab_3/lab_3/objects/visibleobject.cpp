#include "visibleobject.h"

VisibleObject::VisibleObject() {}

VisibleObject::~VisibleObject() {}

bool VisibleObject::isComposite() const { return false; }

bool VisibleObject::isVisible() const { return true; }
