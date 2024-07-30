#ifndef MATRIXCARCASSTRUCTURE_H
#define MATRIXCARCASSTRUCTURE_H

#include "carcasstructure.h"

class MatrixCarcasStructure : public CarcasStructure
{
public:
    MatrixCarcasStructure();
    ~MatrixCarcasStructure() = default;

    void transform(std::shared_ptr<TransformAction> action) override;
    std::shared_ptr<CarcasStructure> clone() const override;

    void addPoint(const Point &point) override;
    void addEdge(const Edge &edge) override;
    void setCenter(const Point &point) override;

    std::vector<Point> getPoints() const override;
    std::vector<Edge> getEdges() const override;
    Point getCenter() const override;

private:
    Point _center;
    std::vector<Point> _points;
    SquareMatrix<bool> _edgesMat;
};

#endif // MATRIXCARCASSTRUCTURE_H
