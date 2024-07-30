#ifndef BASEDIRECTORCREATOR_H
#define BASEDIRECTORCREATOR_H

#include "basecarcasdirector.h"
#include "readers/basereader.h"

class BaseDirectorCreator
{
public:
    virtual ~BaseDirectorCreator() = default;
};

template <typename Director, typename... Args>
class BaseDirectorCreatorTemplate : public BaseDirectorCreator
{
public:
    virtual ~BaseDirectorCreatorTemplate() = default;
    virtual std::shared_ptr<Director> create(Args&&... args) = 0;
};

using CarcasDirectorCreator = BaseDirectorCreatorTemplate<BaseCarcasDirector, std::shared_ptr<CarcasReader>>;

#endif // BASEDIRECTORCREATOR_H
