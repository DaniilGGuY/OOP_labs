#include "graph.h"

proc_err_t draw_line(vertex_t vertex1, vertex_t vertex2, draw_t drawer)
{
    if (!drawer.painter)
        return ERR_DRAW;

    drawer.painter->drawLine(vertex1.x, vertex1.y, vertex2.x, vertex2.y);

    return OK;
}
