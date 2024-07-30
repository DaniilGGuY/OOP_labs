#include "edge.h"

Edge::Edge(size_t first, size_t second) : _first_vertex(first), _second_vertex(second) {}

void Edge::setFirstVertex(size_t first) { _first_vertex = first; }

void Edge::setSecondVertex(size_t second) { _second_vertex = second; }

void Edge::setEdge(size_t first, size_t second)
{
    _first_vertex = first;
    _second_vertex = second;
}

void Edge::setEdge(const Edge &edge)
{
    _first_vertex = edge._first_vertex;
    _second_vertex = edge._second_vertex;
}

size_t Edge::getFirstVertex() const { return _first_vertex; }

size_t Edge::getSecondVertex() const { return _second_vertex; }

bool Edge::operator==(const Edge &edge) const
{
    return (_first_vertex == edge._first_vertex && _second_vertex == edge._second_vertex) ||
           (_second_vertex == edge._first_vertex && _first_vertex == edge._second_vertex);
}

bool Edge::operator!=(const Edge &edge) const
{
    return (_first_vertex != edge._first_vertex && _first_vertex != edge._second_vertex) ||
           (_second_vertex != edge._first_vertex && _second_vertex != edge._second_vertex);
}
