#ifndef SQUAREMATRIX_HPP
#define SQUAREMATRIX_HPP

#include "squarematrix.h"

template<typename T>
SquareMatrix<T>::SquareMatrix() : _size(0) {}

template<typename T>
SquareMatrix<T>::SquareMatrix(size_t n, T val) : _size(n) { _matrix.resize(n, std::vector<T>(n, val)); }

template<typename T>
size_t SquareMatrix<T>::getSize() const { return _size; }

template<typename T>
T& SquareMatrix<T>::at(size_t row, size_t col) { return _matrix[row][col]; }

template<typename T>
const T& SquareMatrix<T>::at(size_t row, size_t col) const { return _matrix[row][col]; }

template<typename T>
void SquareMatrix<T>::resize(size_t size, const T& val)
{
    if (size == _size)
        return;

    std::vector<std::vector<T>> new_matrix(size, std::vector<T>(size, val));

    for (size_t i = 0; i < std::min(size, _size); ++i)
        for (size_t j = 0; j < std::min(size, _size); ++j)
            new_matrix[i][j] = _matrix[i][j];

    _size = size;
    _matrix = std::move(new_matrix);
}

template<typename T>
std::vector<T>& SquareMatrix<T>::operator[](size_t row) { return _matrix[row]; }

template<typename T>
const std::vector<T>& SquareMatrix<T>::operator[](size_t row) const { return _matrix[row]; }

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator+(const SquareMatrix<T>& mat) const
{
    SquareMatrix<T> ret(_size);

    for (size_t i = 0; i < _size; ++i)
        for (size_t j = 0; j < _size; ++j)
            ret[i][j] = _matrix[i][j] + mat[i][j];

    return ret;
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator+=(const SquareMatrix<T>& mat)
{
    for (size_t i = 0; i < _size; ++i)
        for (size_t j = 0; j < _size; ++j)
            _matrix[i][j] += mat[i][j];

    return *this;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(const SquareMatrix<T>& mat) const
{
    SquareMatrix<T> ret(_size);

    for (size_t i = 0; i < _size; ++i)
        for (size_t j = 0; j < _size; ++j)
            for (size_t k = 0; k < _size; ++k)
                ret[i][j] += _matrix[i][k] * mat[k][j];

    return ret;
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator*=(const SquareMatrix<T>& mat)
{
    *this = *this * mat;
    return *this;
}

template<typename T>
std::vector<T> SquareMatrix<T>::multiplyLeft(const std::vector<T>& vec) const
{
    std::vector<T> ret(_size, T());

    for (size_t i = 0; i < _size; ++i)
        for (size_t j = 0; j < _size; ++j)
            ret[i] += _matrix[i][j] * vec[j];

    return ret;
}

template<typename T>
std::vector<T> SquareMatrix<T>::multiplyRight(const std::vector<T>& vec) const
{
    std::vector<T> ret(_size, T());

    for (size_t i = 0; i < _size; ++i)
        for (size_t j = 0; j < _size; ++j)
            ret[j] += _matrix[i][j] * vec[i];

    return ret;
}

#endif // SQUAREMATRIX_HPP
