#include <stdlib.h>

#include "vertexarr.h"

vertex_arr_t vertex_arr_init(void)
{
    vertex_arr_t tmp;

    tmp.data = NULL;
    tmp.size = 0;

    return tmp;
}

void vertex_arr_copy(vertex_arr_t &vertex_arr, vertex_arr_t tmp)
{
    vertex_arr.size = tmp.size;
    vertex_arr.data = tmp.data;
}

proc_err_t read_vertex_count(int &size, FILE *f)
{
    proc_err_t rc = OK;

    if (fscanf(f, "%d", &size) != 1)
        rc = ERR_FILE;

    if (size <= 0)
        rc = ERR_FILE_READ;

    return rc;
}

proc_err_t allocate_vertex_arr(vertex_t *&vertex_arr, int size)
{
    vertex_t *buf = (vertex_t *)malloc(sizeof(vertex_t) * size);
    if (!buf)
        return ERR_MEM;

    vertex_arr = buf;

    return OK;
}

void free_vertex_arr(vertex_t *vertex_arr)
{
    if (vertex_arr)
        free(vertex_arr);
}

proc_err_t read_vertex_arr_elems(vertex_t *vertex_arr, int size, FILE *f)
{
    proc_err_t rc = OK;
    int i = 0;
    while (!rc && i < size)
    {
        rc = read_vertex(vertex_arr[i], f);
        ++i;
    }

    return rc;
}

proc_err_t read_vertex_arr(vertex_arr_t &vertex, FILE *f)
{
    if (!f)
        return ERR_FILE;

    proc_err_t rc = read_vertex_count(vertex.size, f);
    if (!rc)
    {
        rc = allocate_vertex_arr(vertex.data, vertex.size);

        if (!rc)
            rc = read_vertex_arr_elems(vertex.data, vertex.size, f);

        if (rc)
            free_vertex_arr(vertex.data);
    }

    return rc;
}

proc_err_t write_vertex_arr(vertex_arr_t &vertex, FILE *f)
{
    if (!f)
        return ERR_FILE;

    fprintf(f, "%d\n", vertex.size);
    for (int i = 0; i < vertex.size; ++i)
        (void)write_vertex(vertex.data[i], f);

    return OK;
}

proc_err_t transfer_vertex_arr(vertex_arr_t &vertex, const transfer_t transfer)
{
    if (!vertex.data || vertex.size == 0)
        return ERR_TRANSFER;

    for (int i = 0; i < vertex.size; ++i)
        transfer_vertex(vertex.data[i], transfer);

    return OK;
}

proc_err_t scale_vertex_arr(vertex_arr_t &vertex, const scale_t scale)
{
    if (!vertex.data || vertex.size == 0)
        return ERR_SCALE;

    for (int i = 0; i < vertex.size; ++i)
        scale_vertex(vertex.data[i], scale);

    return OK;
}

proc_err_t rotate_vertex_arr(vertex_arr_t &vertex, const rotate_t rotate)
{
    if (!vertex.data || vertex.size == 0)
        return ERR_ROTATE;

    for (int i = 0; i < vertex.size; ++i)
        rotate_vertex(vertex.data[i], rotate);

    return OK;
}
