#ifndef CONSTLISTITER_HPP__
#define CONSTLISTITER_HPP__

#include "procerrors.h"
#include "constlistiter.h"

template<AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(const ConstListIterator<T>& iter) noexcept : ptr(iter.ptr.lock()) {}

template<AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(const ListIterator<T>& iter) noexcept : ptr(iter.ptr.lock()) {}

template<AssignCopyComparable T>
ConstListIterator<T>& ConstListIterator<T>::operator=(const ConstListIterator<T>& iter) noexcept
{
    this->ptr = iter.ptr.lock();
    return *this;
}

template<AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(ConstListIterator<T>&& iter) noexcept : ptr(iter.ptr.lock()) { iter.ptr.reset(); }

template<AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(ListIterator<T>&& iter) noexcept : ptr(iter.ptr.lock()) { iter.ptr.reset(); }

template<AssignCopyComparable T>
ConstListIterator<T>& ConstListIterator<T>::operator=(ConstListIterator<T>&& iter) noexcept
{
    this->ptr = iter.ptr.lock();
    iter.ptr.reset();
    return *this;
}

template<AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(const std::shared_ptr<typename List<T>::Node> &ptr) noexcept : ptr(ptr) {}

template<AssignCopyComparable T>
typename ConstListIterator<T>::reference ConstListIterator<T>::operator*() const
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return this->ptr.lock()->get_val();
}

template<AssignCopyComparable T>
const typename ConstListIterator<T>::pointer ConstListIterator<T>::operator->() const
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return this->ptr.lock();
}

template<AssignCopyComparable T>
ConstListIterator<T> &ConstListIterator<T>::operator++()
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    this->ptr = this->ptr.lock()->get_next();
    return *this;
}

template<AssignCopyComparable T>
ConstListIterator<T> ConstListIterator<T>::operator++(int)
{
    if (!this) {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    ConstListIterator<T> prev(*this);
    this->ptr = this->ptr.lock()->get_next();
    return prev;
}

#endif
