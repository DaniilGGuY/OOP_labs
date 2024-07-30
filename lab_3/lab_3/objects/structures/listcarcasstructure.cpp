#include "listcarcasstructure.h"

ListCarcasStructure::ListCarcasStructure() : _center(Point()), _points(std::vector<Point>()), _edges(std::vector<Edge>()) {}

void ListCarcasStructure::transform(std::shared_ptr<TransformAction> action)
{
    for (auto &point : _points)
        action->transform(point);

    action->transform(_center);
}

std::shared_ptr<CarcasStructure> ListCarcasStructure::clone() const
{
    std::shared_ptr<ListCarcasStructure> clone_model = std::make_shared<ListCarcasStructure>();

    clone_model->setCenter(_center);
    for (auto &it : _points)
        clone_model->addPoint(it);

    for (auto &it : _edges)
        clone_model->addEdge(it);

    return clone_model;
}

void ListCarcasStructure::addPoint(const Point &point) { _points.push_back(point); }

void ListCarcasStructure::addEdge(const Edge &edge) { _edges.push_back(edge); }

void ListCarcasStructure::setCenter(const Point &point) { _center = point; }

std::vector<Point> ListCarcasStructure::getPoints() const { return _points; }

std::vector<Edge> ListCarcasStructure::getEdges() const { return _edges; }

Point ListCarcasStructure::getCenter() const
{
    Point copy(_center);
    return copy;
}
