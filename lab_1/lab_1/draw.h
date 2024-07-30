#ifndef DRAW_H
#define DRAW_H

#include "figure.h"
#include "graph.h"

proc_err_t draw_figure(figure_t figure, draw_t drawer);

proc_err_t draw_lines(vertex_arr_t vertexes, edge_arr_t edges, draw_t drawer);

proc_err_t get_vertexes_by_edge(vertex_t &v1, vertex_t &v2, vertex_t *vertexes, edge_t edge);

#endif // DRAW_H
