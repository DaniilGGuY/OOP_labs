#ifndef BASEITERATOR_HPP__
#define BASEITERATOR_HPP__

#include "baseiterator.h"

template<AssignCopyComparable T>
BaseIterator<T>::operator bool() const noexcept
{
    return ptr.lock() && !ptr.expired();
}

template<AssignCopyComparable T>
bool BaseIterator<T>::operator==(const BaseIterator<T> &iter) const noexcept
{
    return this->ptr.lock() == iter.ptr.lock();
}

template<AssignCopyComparable T>
bool BaseIterator<T>::operator!=(const BaseIterator<T> &iter) const noexcept
{
    return this->ptr.lock() != iter.ptr.lock();
}

#endif