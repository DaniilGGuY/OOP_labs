#ifndef TRANSFORMACTION_H
#define TRANSFORMACTION_H

#include "square_matrix/squarematrix.h"
#include "objects/point.h"

class TransformAction
{
public:
    TransformAction();
    virtual ~TransformAction() = default;

    SquareMatrix<double>& getTransformMatrix();
    const SquareMatrix<double>& getTransformMatrix() const;
    Point &transform(Point &point) const;

protected:
    SquareMatrix<double> _transform_matrix;
};

#endif // TRANSFORMACTION_H
