#ifndef LISTCONCEPTS_HPP
#define LISTCONCEPTS_HPP

#include <iterator>
#include <concepts>

template <typename From, typename To>
concept Convertible = std::convertible_to<From, To>;

template <typename T>
concept Comparable = requires(T t, T u) {
    { t > u } -> std::same_as<bool>;
    { t < u } -> std::same_as<bool>;
    { t <= u } -> std::same_as<bool>;
    { t >= u } -> std::same_as<bool>;
    { t == u } -> std::same_as<bool>;
    { t != u }-> std::same_as<bool>;

    { u > t } -> std::same_as<bool>;
    { u < t } -> std::same_as<bool>;
    { u <= t } -> std::same_as<bool>;
    { u >= t } -> std::same_as<bool>;
    { u == t } -> std::same_as<bool>;
    { u != t }-> std::same_as<bool>;
};

template<typename T, typename U>
concept EquillityComparable = requires(T t, U u) {
    { t == u } -> std::same_as<bool>;
    { u == t } -> std::same_as<bool>;
    { t != u } -> std::same_as<bool>;
    { u != t } -> std::same_as<bool>;
};

template <typename T>
concept Assignable = requires(T & t, T & t2) { t = t2; };

template <typename T>
concept Copyable = requires(T & t) { T(t); };

template <typename T>
concept Moveable = requires(T && t) { T(t); };

template <typename T>
concept AssignCopyable = Assignable<T> && Copyable<T>;

template <typename T>
concept AssignCopyComparable = AssignCopyable<T> && Comparable<T> && Moveable<T>;

template <typename C>
concept Container = requires(C c)
{
    typename C::size_type;
    typename C::value_type;
    typename C::iterator;
    typename C::const_iterator;

    { c.begin() } noexcept -> std::same_as<typename C::iterator>;
    { c.end() } noexcept -> std::same_as<typename C::iterator>;
    { c.cbegin() } noexcept -> std::same_as<typename C::const_iterator>;
    { c.cend() } noexcept -> std::same_as<typename C::const_iterator>;
    { c.size() } noexcept -> std::same_as<typename C::size_type>;
};

template <typename C, typename T>
concept ConvertibleContainer = Container<C> && Convertible<typename C::value_type, T>;

template <typename I>
concept Iterator = requires()
{
    typename I::value_type;
    typename I::pointer;
    typename I::reference;
    typename I::difference_type;
};

template <typename T, typename U>
concept DerivedFrom = std::is_base_of<U, T>::value;

template<typename I>
concept InputIterator = Iterator<I> && requires() 
{ 
    typename I::iterator_category; 
} && EquillityComparable<I, I> && DerivedFrom<typename I::iterator_category, std::input_iterator_tag>;

template<typename I>
concept Incrementable = requires(I it) {
    { ++it } -> std::same_as<I&>;
    { it++ } -> std::same_as<I>;
};

template <typename I>
concept ForwardIterator = InputIterator<I> && Incrementable<I> && DerivedFrom<typename I::iterator_category, std::forward_iterator_tag>;

template <InputIterator I>
typename I::difference_type distance(const I& first, const I& last)
{
    typename I::difference_type count = 0;
    for (I cur = first; cur != last; ++cur, ++count);

    return count;
}

template <typename T>
concept IncrementableComparable = Incrementable<T> && Comparable<T>;

template <typename I, typename T>
concept ConvertibleForwardIterator = ForwardIterator<I> && Convertible<typename I::value_type, T>;

template <typename I, typename T>
concept ConvertibleInputIterator = InputIterator<I> && Convertible<typename I::value_type, T>;

#endif // LISTCONCEPTS_HPP
