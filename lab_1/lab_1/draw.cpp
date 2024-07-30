#include "draw.h"

proc_err_t draw_figure(figure_t figure, draw_t drawer)
{
    if (!drawer.painter)
        return ERR_DRAW;

    proc_err_t rc = draw_lines(figure.vertexes, figure.edges, drawer);

    return rc;
}

proc_err_t get_vertexes_by_edge(vertex_t &v1, vertex_t &v2, vertex_t *vertexes, int size, edge_t edge)
{
    if (!vertexes)
        return ERR_MEM;

    if (edge.vertex1 >= size || edge.vertex2 >= size)
        return ERR_EDGE;

    v1 = vertexes[edge.vertex1];
    v2 = vertexes[edge.vertex2];

    return OK;
}

proc_err_t draw_lines(vertex_arr_t vertexes, edge_arr_t edges, draw_t drawer)
{
    if (!vertexes.data || !edges.data)
        return ERR_MEM;

    if (!drawer.painter)
        return ERR_DRAW;

    proc_err_t rc = OK;
    for (int i = 0; !rc && i < edges.size; ++i)
    {
        vertex_t v1, v2;
        rc = get_vertexes_by_edge(v1, v2, vertexes.data, vertexes.size, edges.data[i]);
        if (!rc)
            rc = draw_line(v1, v2, drawer);
    }

    return rc;
}

