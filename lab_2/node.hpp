#ifndef NODE_HPP__
#define NODE_HPP__

#include "list.h"

template<AssignCopyComparable T>
List<T>::Node::Node() : val(T()), next(nullptr) {}

template<AssignCopyComparable T>
List<T>::Node::Node(const T &val) : val(val), next(nullptr) {}

template<AssignCopyComparable T>
List<T>::Node::Node(T&& val) : val(val), next(nullptr) {}

template<AssignCopyComparable T>
List<T>::Node::Node(const Node &node) : val(node.val), next(node.next) {}

template<AssignCopyComparable T>
List<T>::Node::Node(Node&& node) : val(node.val), next(node.next) {}

template<AssignCopyComparable T>
T &List<T>::Node::get_val()
{
    return this->val;
}

template<AssignCopyComparable T>
std::shared_ptr<typename List<T>::Node> List<T>::Node::get_next()
{
    return this->next;
}

template<AssignCopyComparable T>
void List<T>::Node::set_val(const T &val)
{
    this->val = val;
}

template<AssignCopyComparable T>
void List<T>::Node::set_next(std::shared_ptr<Node> &next)
{
    this->next = next;
}

template<AssignCopyComparable T>
void List<T>::Node::set_next_null()
{
    this->next = nullptr;
}

template<AssignCopyComparable T>
bool List<T>::Node::operator==(const Node &node) const
{
    return this->val == node.val && this->next == node.next;
}

template<AssignCopyComparable T>
bool List<T>::Node::operator!=(const Node &node) const
{
    return this->val != node.val || this->next != node.next;
}

#endif
