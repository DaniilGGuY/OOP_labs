#ifndef READERCREATOR_H
#define READERCREATOR_H

#include "basereadercreator.h"
#include "txtcarcasreader.h"

template <typename Base, typename Deriv, typename... Args>
class ReaderCreator : public BaseReaderCreatorTemplate<Base, Args...>
{
public:
    virtual ~ReaderCreator() = default;
    virtual std::shared_ptr<Base> create(Args&&... args);
};

using TxtCarcasReaderCreator = ReaderCreator<CarcasReader, TxtCarcasReader, const char *>;

#include "readercreator.hpp"

#endif // READERCREATOR_H
