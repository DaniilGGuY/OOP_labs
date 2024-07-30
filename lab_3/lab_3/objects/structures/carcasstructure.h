#ifndef CARCASSTRUCTURE_H
#define CARCASSTRUCTURE_H

#include <vector>
#include <memory>

#include "transform/transformaction.h"
#include "objects/point.h"
#include "objects/edge.h"

class CarcasStructure
{
public:
    CarcasStructure() = default;
    CarcasStructure(const CarcasStructure &carcas) = delete;
    CarcasStructure(CarcasStructure &&carcas) = delete;
    virtual ~CarcasStructure() = 0;

    virtual void transform(std::shared_ptr<TransformAction> action) = 0;
    virtual std::shared_ptr<CarcasStructure> clone() const = 0;

    virtual void addPoint(const Point &point) = 0;
    virtual void addEdge(const Edge &edge) = 0;
    virtual void setCenter(const Point &point) = 0;

    virtual std::vector<Point> getPoints() const = 0;
    virtual std::vector<Edge> getEdges() const = 0;
    virtual Point getCenter() const = 0;
};

#endif // CARCASSTRUCTURE_H
