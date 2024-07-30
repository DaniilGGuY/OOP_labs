#ifndef GRAPH_H
#define GRAPH_H

#include <QPainter>

#include "processerror.h"
#include "vertex.h"

struct draw_t
{
    QPainter *painter;
};

proc_err_t draw_line(vertex_t vertex1, vertex_t vertex2, draw_t drawer);

#endif // GRAPH_H
