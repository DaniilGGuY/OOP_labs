#ifndef EDGE_H
#define EDGE_H

#include <cstddef>

class Edge
{
public:
    Edge() = default;
    Edge(size_t first, size_t second);

    explicit Edge(const Edge &edge) = default;
    Edge &operator=(const Edge &edge) = default;

    Edge(Edge &&edge) = default;
    Edge &operator=(Edge &&edge) = default;

    void setFirstVertex(size_t first);
    void setSecondVertex(size_t second);
    void setEdge(size_t first, size_t second);
    void setEdge(const Edge &edge);

    size_t getFirstVertex() const;
    size_t getSecondVertex() const;

    bool operator==(const Edge &edge) const;
    bool operator!=(const Edge &edge) const;

private:
    size_t _first_vertex;
    size_t _second_vertex;
};

#endif // EDGE_H
