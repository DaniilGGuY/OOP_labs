#ifndef CONSTLISTITER_H
#define CONSTLISTITER_H

#include <cstdlib>
#include <memory>
#include <iterator>

#include "baseiterator.h"
#include "listconcepts.h"

template <AssignCopyComparable T>
class List;

template <AssignCopyComparable T>
class ListIterator;

template<AssignCopyComparable T>
class ConstListIterator : public BaseIterator<T>
{
public:
    using value_type = T;
    using reference = const T&;
    using pointer = const std::shared_ptr<T>;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

    explicit ConstListIterator(const ConstListIterator<T> &iter) noexcept;
    explicit ConstListIterator(const ListIterator<T> &iter) noexcept;
    ConstListIterator<T> &operator=(const ConstListIterator<T>& iter) noexcept;

    ConstListIterator(ConstListIterator<T> &&iter) noexcept;
    ConstListIterator(ListIterator<T> &&iter) noexcept;
    ConstListIterator<T> &operator=(ConstListIterator<T>&& iter) noexcept;

    ConstListIterator(const std::shared_ptr<typename List<T>::Node>& ptr) noexcept;

    ~ConstListIterator() = default;

    reference operator*() const;
    pointer operator->() const;

    ConstListIterator<T> &operator++();
    ConstListIterator<T> operator++(int);

protected:
    std::weak_ptr<typename List<T>::Node> ptr;
};

#include "constlistiter.hpp"

#endif // CONSTLISTITER_H
