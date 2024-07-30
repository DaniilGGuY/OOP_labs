#ifndef BASEREADERCREATOR_H
#define BASEREADERCREATOR_H

#include <memory>

#include "carcasreader.h"

class BaseReaderCreator
{
public:
    virtual ~BaseReaderCreator() = default;
};

template <typename Reader, typename... Args>
class BaseReaderCreatorTemplate : public BaseReaderCreator
{
public:
    virtual ~BaseReaderCreatorTemplate() = default;
    virtual std::shared_ptr<Reader> create(Args&&... args) = 0;
};

using CarcasReaderCreator = BaseReaderCreatorTemplate<CarcasReader, const char*>;

#endif // BASEREADERCREATOR_H
