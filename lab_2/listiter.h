#ifndef LISTITER_H
#define LISTITER_H

#include <cstdlib>
#include <iterator>
#include <memory>

#include "baseiterator.h"
#include "listconcepts.h"

template <AssignCopyComparable T>
class List;

template <AssignCopyComparable T>
class ConstListIterator;

template<AssignCopyComparable T>
class ListIterator : public BaseIterator<T>
{
public:
    using value_type = T;
    using reference = T&;
    using pointer = std::shared_ptr<T>;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

    explicit ListIterator(const ListIterator<T>& iter) noexcept;
    ListIterator<T>& operator=(const ListIterator<T>& iter) noexcept;

    ListIterator(ListIterator<T>&& iter) noexcept;
    ListIterator<T>& operator=(ListIterator<T>&& iter) noexcept;

    ListIterator(const std::shared_ptr<typename List<T>::Node> ptr) noexcept;

    ~ListIterator() = default;

    reference operator*();
    const reference operator*() const;
    pointer operator->();
    const pointer operator->() const;

    ListIterator<T> &operator++();
    ListIterator<T> operator++(int);
        
protected:
    std::weak_ptr<typename List<T>::Node> ptr;
};

#include "listiter.hpp"

#endif // LISTITER_H
