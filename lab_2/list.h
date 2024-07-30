#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory>
#include <initializer_list>

#include "basecontainer.h"
#include "listiter.h"
#include "constlistiter.h"
#include "listconcepts.h"

template<AssignCopyComparable T>
class List : public BaseContainer
{
public:
#pragma region Friends
    friend class BaseIterator<T>;
    friend class ListIterator<T>;
    friend class ConstListIterator<T>;
#pragma endregion

#pragma region Aliases
    using size_type = size_t;
    using value_type = T;
    using iterator = ListIterator<T>;
    using const_iterator = ConstListIterator<T>;
#pragma endregion

#pragma region Constructs
    List() noexcept;

    explicit List(const List<T>& list);
    List<T>& operator=(const List<T>& list);

    List(List<T>&& list) noexcept;
    List<T>& operator=(List<T>&& list) noexcept;

    template <Convertible<T> U>
    List(size_t size, const U& data);

    template <Convertible<T> U>
    explicit List(const std::initializer_list<U>& list);
    template <Convertible<T> U>
    List<T>& operator=(const std::initializer_list<U>& list);

    template <ConvertibleContainer<T> C>
    explicit List(const C& cont);
    template <ConvertibleContainer<T> C>
    List<T>& operator=(const C& cont);

    template <ConvertibleInputIterator<T> I>
    List(const I& beg, const I& end);

    ~List() = default;
#pragma endregion

#pragma region BaseMethods
    bool empty() const override;
    size_t size() const override;
    void clear() noexcept;
    void reverse() noexcept;

    T& front();
    T& back();
#pragma endregion

#pragma region Iters
    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
#pragma endregion

// по ссылке
#pragma region Appending
    template <Convertible<T> U>
    List<T> push_back(const U& el);
    template <Convertible<T> U>
    List<T> push_front(const U& el);
    template <Convertible<T> U>
    List<T>& operator+=(const U& el);
    template <Convertible<T> U>
    List<T> operator+(const U& el) const;

    template <Convertible<T> U>
    List<T> push_back(U&& el);
    template <Convertible<T> U>
    List<T> push_front(U&& el);
    template <Convertible<T> U>
    List<T>& operator+=(U&& el);
    template <Convertible<T> U>
    List<T> operator+(U&& el) const;

    template <ConvertibleContainer<T> C>
    List<T> push_back(const C& cont);
    template <ConvertibleContainer<T> C>
    List<T> push_front(const C& cont);
    template <ConvertibleContainer<T> C>
    List<T>& operator+=(const C& cont);
    template <ConvertibleContainer<T> C>
    List<T> operator+(const C& cont) const;

    template<Convertible<T> U>
    List<T> push_back(List<U>&& list) noexcept;
    template<Convertible<T> U>
    List<T> push_front(List<U>&& list) noexcept;
    template<Convertible<T> U>
    List<T>& operator+=(List<U>&& list) noexcept;
    template<Convertible<T> U>
    List<T> operator+(List<U>&& list) const;
#pragma endregion
    
#pragma region Inserts
    template <Convertible<T> U>
    List<T> insert(const ListIterator<T>& it, const U& el);
    template<Convertible<T> U>
    List<T> insert(const ListIterator<T>& it, U&& el);
    template <ConvertibleContainer<T> C>
    List<T> insert(const ListIterator<T>& it, const C& cont);
    template<Convertible<T> U>
    List<T> insert(const ListIterator<T>& it, List<U>&& list);
#pragma endregion

#pragma region Cutting
    T pop_front();
    T pop_back();

    List<T> remove(const ListIterator<T>& it);
    List<T> remove(const ListIterator<T>& beg, const ListIterator<T>& end);
    List<T> remove(const ListIterator<T>& beg, size_t size);
    List<T> remove(const ConstListIterator<T>& it);
    List<T> remove(const ConstListIterator<T>& beg, const ConstListIterator<T>& end);
    List<T> remove(const ConstListIterator<T>& beg, size_t size);

    List<T> sub_list(const ListIterator<T>& beg, const ListIterator<T>& end);
    List<T> sub_list(const ListIterator<T>& beg, size_t size);
    List<T> sub_list(const ConstListIterator<T>& beg, const ConstListIterator<T>& end) const;
    List<T> sub_list(const ConstListIterator<T>& beg, size_t size) const;
#pragma endregion

#pragma region Compare
    bool operator==(const List<T>& list) const;
    bool operator!=(const List<T>& list) const;
#pragma endregion

protected:
    class Node
    {
    public:
        Node();
        Node(const T &val);
        Node(T&& val);
        Node(const Node& node);
        Node(Node &&node);
        ~Node() = default;

        T &get_val();
        std::shared_ptr<Node> get_next();

        void set_val(const T &val);
        void set_next(std::shared_ptr<Node> &next);
        void set_next_null();

        bool operator==(const Node &node) const;
        bool operator!=(const Node &node) const;

    private:
        T val;
        std::shared_ptr<Node> next;
    };

protected:
    void check_list();
    int listcmp(const List<T>& list) const;
    std::shared_ptr<Node> node_alloc(const T& vals);
    std::shared_ptr<Node> node_alloc(T&& vals);

private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
};

template<typename T>
std::ostream& operator<<(std::ostream &os, const List<T> &list);

#include "node.hpp"
#include "list.hpp"

#endif // LIST_H
