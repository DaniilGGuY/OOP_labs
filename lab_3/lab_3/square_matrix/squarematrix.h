#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <vector>
#include <memory>

template <typename T>
class SquareMatrix
{
public:
    SquareMatrix();
    SquareMatrix(size_t size, T val = T());
    ~SquareMatrix() = default;

    size_t getSize() const;
    T& at(size_t row, size_t col);
    const T& at(size_t row, size_t col) const;

    void resize(size_t size, const T& val = T());

    std::vector<T>& operator[](size_t row);
    const std::vector<T>& operator[](size_t row) const;

    SquareMatrix<T> operator+(const SquareMatrix<T>& mat) const;
    SquareMatrix<T>& operator+=(const SquareMatrix<T>& mat);

    SquareMatrix<T> operator*(const SquareMatrix<T>& mat) const;
    SquareMatrix<T>& operator*=(const SquareMatrix<T>& mat);

    std::vector<T> multiplyLeft(const std::vector<T>& vec) const;
    std::vector<T> multiplyRight(const std::vector<T>& vec) const;

private:
    std::vector<std::vector<T>> _matrix;
    size_t _size;
};

#include "squarematrix.hpp"

#endif // SQUAREMATRIX_H
