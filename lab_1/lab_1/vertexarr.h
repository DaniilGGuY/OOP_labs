#ifndef VERTEXARR_H
#define VERTEXARR_H

#include "vertex.h"

struct vertex_arr_t
{
    vertex_t *data;
    int size;
};

vertex_arr_t vertex_arr_init(void);

void vertex_arr_copy(vertex_arr_t &vertex_arr, vertex_arr_t tmp);

proc_err_t read_vertex_count(int &size, FILE *f);

proc_err_t allocate_vertex_arr(vertex_t *&vertex_arr, int size);

void free_vertex_arr(vertex_t *vertex_arr);

proc_err_t read_vertex_arr_elems(vertex_t *vertex_arr, int size, FILE *f);

proc_err_t read_vertex_arr(vertex_arr_t &vertex, FILE *f);

proc_err_t write_vertex_arr(vertex_arr_t &vertex, FILE *f);

proc_err_t transfer_vertex_arr(vertex_arr_t &vertex, const transfer_t transfer);

proc_err_t scale_vertex_arr(vertex_arr_t &vertex, const scale_t scale);

proc_err_t rotate_vertex_arr(vertex_arr_t &vertex, const rotate_t rotate);

#endif // VERTEXARR_H
