#ifndef BASEDRAWERCREATOR_H
#define BASEDRAWERCREATOR_H

#include <memory>

#include "basedrawer.h"

class BaseDrawerCreator
{
public:
    BaseDrawerCreator() = default;
    virtual ~BaseDrawerCreator() = 0;

    virtual std::shared_ptr<BaseDrawer> create() = 0;
};

#endif // BASEDRAWERCREATOR_H
