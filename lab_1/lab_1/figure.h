#ifndef FIGURE_H
#define FIGURE_H

#include "vertexarr.h"
#include "edgearr.h"
#include "processerror.h"

struct figure_t
{
    vertex_arr_t vertexes;
    edge_arr_t edges;
};

figure_t figure_init(void);

void copy_figure(figure_t &figure, figure_t tmp);

proc_err_t read_fields_figure(figure_t &tmp, FILE *f);

proc_err_t read_figure(figure_t &figure, const char *filename);

proc_err_t write_figure(figure_t &figure, const char *filename);

proc_err_t figure_transfer(figure_t &figure, const transfer_t transfer);

proc_err_t figure_scale(figure_t &figure, const scale_t scale);

proc_err_t figure_rotate(figure_t &figure, const rotate_t rotate);

proc_err_t check_figure(figure_t &figure);

void free_figure(figure_t &figure);

void free_vertexes(vertex_arr_t &vertexes);

void free_edges(edge_arr_t &edges);

#endif // FIGURE_H
