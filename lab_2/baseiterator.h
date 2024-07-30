#ifndef BASEITERATOR_H
#define BASEITERATOR_H

#include <memory>

#include "listconcepts.h"

template<AssignCopyComparable T>
class List;

template<AssignCopyComparable T>
class BaseIterator
{
public:
    BaseIterator() = delete;
    BaseIterator(const  BaseIterator<T>& it) = delete;
    BaseIterator(BaseIterator<T>&& it) = delete;

    operator bool() const noexcept;
    bool operator==(const BaseIterator<T> &iter) const noexcept;
    bool operator!=(const BaseIterator<T> &iter) const noexcept;

protected:
    std::weak_ptr<typename List<T>::Node> ptr;
};

#include "baseiterator.hpp"

#endif // BASEITERATOR_H
