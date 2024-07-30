#ifndef LIST_HPP__
#define LIST_HPP__

#include <chrono>

#include "list.h"
#include "procerrors.h"

#pragma region Constructors
template<AssignCopyComparable T>
List<T>::List() noexcept
{
    clear();
}

template<AssignCopyComparable T>
List<T>::List(const List<T>& list)
{
    clear();
    for (auto& val : list)
        push_back(val);
}

template<AssignCopyComparable T>
List<T>& List<T>::operator=(const List<T>& list)
{
    clear();
    for (auto& val : list)
        push_back(val);
    return *this;
}

template<AssignCopyComparable T>
List<T>::List(List<T>&& list) noexcept
{
    head = list.head;
    tail = list.tail;
    len = list.len;
    list.clear();
}

template<AssignCopyComparable T>
List<T>& List<T>::operator=(List<T>&& list) noexcept
{
    head = list.head;
    tail = list.tail;
    len = list.len;
    list.clear();
    return *this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T>::List(size_t size, const U& data)
{
    clear();
    for (size_t i = 0; i < size; ++i)
        push_back(data);
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T>::List(std::initializer_list<U> list)
{
    clear();
    for (auto& val : list)
        push_back(val);
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T>& List<T>::operator=(std::initializer_list<U> list)
{
    clear();
    for (auto& val : list)
        push_back(val);
    return *this;
}

template<AssignCopyComparable T>
template<ConvertibleContainer<T> C>
List<T>::List(const C& cont)
{
    clear();
    for (auto& val : cont)
        push_back(val);
}

template<AssignCopyComparable T>
template<ConvertibleContainer<T> C>
List<T>& List<T>::operator=(const C& cont)
{
    clear();
    for (auto& val : cont)
        push_back(val);
    return *this;
}

template<AssignCopyComparable T>
template<ConvertibleInputIterator<T> I>
List<T>::List(const I& beg, const I& end)
{
    clear();
    for (auto it = beg; it != end; ++it)
        push_back(*it);
}
#pragma endregion

#pragma region BaseMethods
template<AssignCopyComparable T>
bool List<T>::empty() const
{
    return len == 0;
}

template<AssignCopyComparable T>
size_t List<T>::size() const
{
    return len;
}

template<AssignCopyComparable T>
void List<T>::clear() noexcept
{
    head = nullptr;
    tail = nullptr;
    len = 0;
}

template<AssignCopyComparable T>
void List<T>::reverse() noexcept
{
    if (empty()) { return; }

    auto cur = head;
    auto prev_head = head;
    std::shared_ptr<List<T>::Node> prev = nullptr;

    while (cur) {
        auto next = cur->get_next();
        cur->set_next(prev);
        prev = cur;
        cur = next;
    }

    head = prev;
    tail = prev_head;

}

template<AssignCopyComparable T>
T& List<T>::front()
{
    check_list();
    return head->get_val();
}

template<AssignCopyComparable T>
T& List<T>::back()
{
    check_list();
    return tail->get_val();
}
#pragma endregion

#pragma region Iters
template<AssignCopyComparable T>
List<T>::iterator List<T>::begin() noexcept
{
    return ListIterator<T>(head);
}

template<AssignCopyComparable T>
List<T>::iterator List<T>::end() noexcept
{
    if (!head) { return ListIterator<T>(head); }
    ListIterator<T> it(tail);
    ++it;
    return it;
}

template<AssignCopyComparable T>
List<T>::const_iterator List<T>::begin() const noexcept
{
    return ConstListIterator<T>(head);
}

template<AssignCopyComparable T>
List<T>::const_iterator List<T>::end() const noexcept
{
    if (!head) { return ConstListIterator<T>(head); }
    ConstListIterator<T> it(tail);
    ++it;
    return it;
}

template<AssignCopyComparable T>
List<T>::const_iterator List<T>::cbegin() const noexcept
{
    return ConstListIterator<T>(head);
}

template<AssignCopyComparable T>
List<T>::const_iterator List<T>::cend() const noexcept
{
    if (!head) { return ConstListIterator<T>(head); }
    ConstListIterator<T> it(tail);
    ++it;
    return it;
}
#pragma endregion

#pragma region Appending
template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::push_back(const U& el)
{
    auto node = node_alloc(el);
    if (head)
    {
        tail->set_next(node);
        tail = node;
    }
    else
    {
        head = node;
        tail = node;
    }
    ++len;

    return this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::push_front(const U& el)
{
    auto node = node_alloc(el);
    if (head)
    {
        node->set_next(head);
        head = node;
    }
    else
    {
        head = node;
        tail = node;
    }
    ++len;

    return this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T>& List<T>::operator+=(const U& el)
{
    push_back(el);
    return *this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::operator+(const U& el) const
{
    List<T> tmp(*this);
    tmp.push_back(el);
    return tmp;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::push_back(U&& el)
{
    auto node = node_alloc(el);
    if (head)
    {
        tail->set_next(node);
        tail = node;
    }
    else
    {
        head = node;
        tail = node;
    }
    ++len;

    return this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::push_front(U&& el)
{
    auto node = node_alloc(el);
    if (head)
    {
        node->set_next(head);
        head = node;
    }
    else
    {
        head = node;
        tail = node;
    }
    ++len;

    return this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T>& List<T>::operator+=(U&& el)
{
    push_back(el);
    return *this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::operator+(U&& el) const
{
    List<T> tmp(*this);
    tmp.push_back(el);
    return tmp;
}

template<AssignCopyComparable T>
template<ConvertibleContainer<T> C>
List<T> List<T>::push_back(const C& cont)
{
    for (auto& val : cont)
        push_back(val);

    return this;
}

template<AssignCopyComparable T>
template<ConvertibleContainer<T> C>
List<T> List<T>::push_front(const C& cont)
{
    List<T> tmp(cont);
    tmp.push_back(std::move(*this));
    *this = std::move(tmp);

    return this;
}

template<AssignCopyComparable T>
template<ConvertibleContainer<T> C>
List<T>& List<T>::operator+=(const C& cont)
{
    push_back(cont);
    return *this;
}

template<AssignCopyComparable T>
template<ConvertibleContainer<T> C>
List<T> List<T>::operator+(const C& cont) const
{
    List<T> tmp(*this);
    tmp.push_back(cont);
    return tmp;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::push_back(List<U>&& list) noexcept
{
    tail->set_next(list.head);
    tail = list.tail;
    len += list.len;
    list.clear();

    return this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::push_front(List<U>&& list) noexcept
{
    list.tail->set_next(head);
    head = list.head;
    len += list.len;
    list.clear();

    return this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T>& List<T>::operator+=(List<U>&& list) noexcept
{
    push_back(list);
    return *this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::operator+(List<U>&& list) const
{
    List<T> tmp(*this);
    tmp.push_back(list);
    return tmp;
}
#pragma endregion

#pragma region Inserts
template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::insert(const ListIterator<T>& it, const U& el)
{
    if (!it)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    if (it + 1 == end())
    {
        push_back(el);
    }
    else
    {
        auto node = node_alloc(el);
        node->set_next(it->get_next());
        it->set_next(node);
        ++len;
    }

    return this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::insert(const ListIterator<T>& it, U&& el)
{
    if (!it)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    if (it + 1 == end())
    {
        push_back(el);
    }
    else
    {
        auto node = node_alloc(el);
        node->set_next(it->get_next());
        it->set_next(node);
        ++len;
    }

    return this;
}

template<AssignCopyComparable T>
template<ConvertibleContainer<T> C>
List<T> List<T>::insert(const ListIterator<T>& it, const C& cont)
{
    for (auto& i : cont)
    {
        insert(it, i);
        ++it;
    }

    return this;
}

template<AssignCopyComparable T>
template<Convertible<T> U>
List<T> List<T>::insert(const ListIterator<T>& it, List<U>&& list)
{
    if (!it)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    if (it + 1 == end())
    {
        push_back(list);
    }
    else
    {
        list.tail->set_next(it->get_next());
        it->set_next(list.head);
        len += list.len;
    }

    return this;
}
#pragma endregion

#pragma region Cutting
template<AssignCopyComparable T>
T List<T>::pop_back()
{
    check_list();

    T ret;
    if (len == 1) 
    {
        ret = head->get_val();
        clear();
    }
    else 
    {
        auto cur = head;
        for (; cur->get_next() != tail; cur = cur->get_next());

        ret = cur->get_next()->get_val();
        cur->set_next_null();
        tail = cur;
        --len;
    }

    return ret;
}

template<AssignCopyComparable T>
T List<T>::pop_front()
{
    check_list();

    T ret = head->get_val();
    if (len == 1)
    {
        clear();
    }
    else
    {
        --len;
        head = head->get_next();
    }

    return ret;
}

template<AssignCopyComparable T>
List<T> List<T>::remove(const ListIterator<T>& it)
{
    if (!it)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    if (it == begin())
    {
        pop_front();
        return;
    }
    
    auto i = begin(), j = begin();
    ++j;
    for (; i != end() && j != it; ++i, ++j);
    if (j == end())
    {
        pop_back();
        return;
    }
    --len;
    i->set_next(i->get_next()->get_next());

    return this;
}

template<AssignCopyComparable T>
List<T> List<T>::remove(const ListIterator<T>& beg, const ListIterator<T>& end)
{
    if (!beg || !end)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    size_t count = distance(begin, end) + 1;

    if (begin() == beg)
    {
        head = end->get_next();
    }
    else 
    {
        auto i = begin(), j = begin();
        ++j;
        for (; j != beg; ++i);
        if (ListIterator<T>(tail) == end) 
        {
            tail = i->get_next();
            tail->set_next_null();
        }
        else
        {
            i->set_next(end->get_next());
        }
    }

    end->set_next(nullptr);
    len -= count;

    return this;
}

template<AssignCopyComparable T>
List<T> List<T>::remove(const ListIterator<T>& beg, size_t size)
{
    if (!beg)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    ListIterator<T>& end = beg;
    for (size_t i = 0; i < size; ++i, ++end);
    remove(beg, end);

    return this;
}

template<AssignCopyComparable T>
List<T> List<T>::remove(const ConstListIterator<T>& it)
{
    if (!it)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    if (it == begin())
    {
        pop_front();
        return;
    }

    auto i = begin(), j = begin();
    ++j;
    for (; i != end() && j != it; ++i, ++j);
    if (j == end())
    {
        pop_back();
        return;
    }
    --len;
    i->set_next(i->get_next()->get_next());

    return this;
}

template<AssignCopyComparable T>
List<T> List<T>::remove(const ConstListIterator<T>& beg, const ConstListIterator<T>& end)
{
    if (!beg || !end)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    size_t count = distance(begin, end) + 1;

    if (begin() == beg)
    {
        head = end->get_next();
    }
    else
    {
        auto i = begin(), j = begin();
        ++j;
        for (; j != beg; ++i);
        if (ListIterator<T>(tail) == end)
        {
            tail = i->get_next();
            tail->set_next_null();
        }
        else
        {
            i->set_next(end->get_next());
        }
    }

    end->set_next(nullptr);
    len -= count;

    return this;
}

template<AssignCopyComparable T>
List<T> List<T>::remove(const ConstListIterator<T>& beg, size_t size)
{
    if (!beg)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    ConstListIterator<T>& end = beg;
    for (size_t i = 0; i < size; ++i, ++end);
    remove(beg, end);

    return this;
}

template<AssignCopyComparable T>
List<T> List<T>::sub_list(const ListIterator<T>& beg, const ListIterator<T>& end)
{
    return List<T>(beg, end);
}

template<AssignCopyComparable T>
List<T> List<T>::sub_list(const ListIterator<T>& beg, size_t size)
{
    if (!beg)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    ListIterator<T>& end = beg;
    for (size_t i = 0; i < size; ++i, ++end);
    return List<T>(beg, end);
}

template<AssignCopyComparable T>
List<T> List<T>::sub_list(const ConstListIterator<T>& beg, const ConstListIterator<T>& end) const
{
    return List<T>(beg, end);
}

template<AssignCopyComparable T>
List<T> List<T>::sub_list(const ConstListIterator<T>& beg, size_t size) const
{
    if (!beg)
    {
        time_t cur_time = time(NULL);
        throw IteratorErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    ConstListIterator<T>& end = beg;
    for (size_t i = 0; i < size; ++i, ++end);
    return List<T>(beg, end);
}
#pragma endregion

#pragma region Compare
template<AssignCopyComparable T>
bool List<T>::operator==(const List<T>& list) const
{
    return listcmp(list) == 0;
}

template<AssignCopyComparable T>
bool List<T>::operator!=(const List<T>& list) const
{
    return listcmp(list) != 0;
}
#pragma endregion

template<AssignCopyComparable T>
void List<T>::check_list()
{
    if (len == 0)
    {
        time_t cur = time(NULL);
        throw ListErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

template<AssignCopyComparable T>
int List<T>::listcmp(const List<T>& list) const
{
    check_list();

    if (this->len != list.len)
    {
        return this->len - list.len;
    }

    for (auto it1 = this->cbegin(), it2 = list.cbegin(); it1 != this->cend() && it2 != list.cend(); ++it1, ++it2)
    {
        if (*it1 < *it2)
            return -1;
        else if (*it1 > *it2)
            return 1;
    }

    return 0;
}

template<AssignCopyComparable T>
std::shared_ptr<typename List<T>::Node> List<T>::node_alloc(const T& val)
{
    std::shared_ptr<List<T>::Node> new_node = nullptr;

    time_t cur = time(NULL);
    try 
    {
        new_node = std::make_shared<List<T>::Node>(val);
    }
    catch (std::bad_alloc) 
    {
        throw MemoryErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return new_node;
}

template<AssignCopyComparable T>
std::shared_ptr<typename List<T>::Node> List<T>::node_alloc(T&& val)
{
    std::shared_ptr<List<T>::Node> new_node = nullptr;

    time_t cur = time(NULL);
    try
    {
        new_node = std::make_shared<List<T>::Node>(val);
    }
    catch (std::bad_alloc)
    {
        throw MemoryErr("0", __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return new_node;
}

template<AssignCopyComparable T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    os << "{";

    auto it = list.cbegin();
    if (it != list.cend()) 
    {
        os << *it;
        ++it;
    }
    for (; it != list.cend(); ++it) 
    {
        os << ", " << *it;
    }

    os << "}";
    os << "(" << list.size() << ")";

    return os;
}

#endif
