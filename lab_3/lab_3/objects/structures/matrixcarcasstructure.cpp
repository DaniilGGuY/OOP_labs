#include "matrixcarcasstructure.h"

MatrixCarcasStructure::MatrixCarcasStructure() : _center(Point()), _points(std::vector<Point>()), _edgesMat(SquareMatrix<bool>()){}

void MatrixCarcasStructure::transform(std::shared_ptr<TransformAction> action)
{
    for (auto &point : _points)
        action->transform(point);

    action->transform(_center);
}

std::shared_ptr<CarcasStructure> MatrixCarcasStructure::clone() const
{
    std::shared_ptr<MatrixCarcasStructure> clone_model = std::make_shared<MatrixCarcasStructure>();

    clone_model->setCenter(_center);
    for (auto &it : _points)
        clone_model->addPoint(it);

    clone_model->_edgesMat = _edgesMat;

    return clone_model;
}

void MatrixCarcasStructure::addPoint(const Point &point)
{
    _points.push_back(point);
    _edgesMat.resize(_points.size(), false);
}

void MatrixCarcasStructure::addEdge(const Edge &edge)
{
    size_t i = edge.getFirstVertex(), j = edge.getSecondVertex();
   _edgesMat[i][j] = true;
   _edgesMat[j][i] = true;
}

void MatrixCarcasStructure::setCenter(const Point &point) { _center = point; }

std::vector<Point> MatrixCarcasStructure::getPoints() const { return _points; }

std::vector<Edge> MatrixCarcasStructure::getEdges() const
{
    std::vector<Edge> edges;

    for (size_t i = 0; i < _edgesMat.getSize(); ++i)
        for (size_t j = 0; j < _edgesMat.getSize(); ++j)
            if (_edgesMat[i][j])
                edges.push_back(Edge(i, j));

    return edges;
}

Point MatrixCarcasStructure::getCenter() const
{
    Point copy(_center);
    return copy;
}
