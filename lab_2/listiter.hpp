#ifndef LISTITER_HPP__
#define LISTITER_HPP__

#include "procerrors.h"
#include "listiter.h"

template<AssignCopyComparable T>
ListIterator<T>::ListIterator(const ListIterator<T> &iter) noexcept : ptr(iter.ptr.lock()) {}

template<AssignCopyComparable T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator<T>& iter) noexcept
{
    this->ptr = iter.ptr.lock();
    return *this;
}

template<AssignCopyComparable T>
ListIterator<T>::ListIterator(ListIterator<T>&& iter) noexcept : ptr(iter.ptr.lock()) { iter.ptr.reset(); }

template<AssignCopyComparable T>
ListIterator<T>& ListIterator<T>::operator=(ListIterator<T>&& iter) noexcept
{
    this->ptr = iter.ptr.lock();
    iter.ptr.reset();
    return *this;
}

template<AssignCopyComparable T>
ListIterator<T>::ListIterator(const std::shared_ptr<typename List<T>::Node> ptr) noexcept : ptr(ptr) {}

template<AssignCopyComparable T>
ListIterator<T>::reference ListIterator<T>::operator*()
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return this->ptr.lock()->get_val();
}

template<AssignCopyComparable T>
ListIterator<T>::pointer ListIterator<T>::operator->()
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return this->ptr.lock();
}

template<AssignCopyComparable T>
const typename ListIterator<T>::reference ListIterator<T>::operator*() const
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return this->ptr.lock()->get_val();
}

template<AssignCopyComparable T>
const typename ListIterator<T>::pointer ListIterator<T>::operator->() const
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return this->ptr.lock();
}

template<AssignCopyComparable T>
ListIterator<T> &ListIterator<T>::operator++()
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    this->ptr = this->ptr.lock()->get_next();
    return *this;
}

template<AssignCopyComparable T>
ListIterator<T> ListIterator<T>::operator++(int)
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    ListIterator<T> prev(*this);
    this->ptr = this->ptr.lock()->get_next();
    return prev;
}

#endif
