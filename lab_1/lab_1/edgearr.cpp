#include <stdlib.h>

#include "edgearr.h"

edge_arr_t edge_arr_init(void)
{
    edge_arr_t tmp;

    tmp.data = NULL;
    tmp.size = 0;

    return tmp;
}

void edge_arr_copy(edge_arr_t &edge_arr, edge_arr_t tmp)
{
    edge_arr.size = tmp.size;
    edge_arr.data = tmp.data;
}

proc_err_t read_edge_count(int &size, FILE *f)
{
    proc_err_t rc = OK;

    if (fscanf(f, "%d", &size) != 1)
        rc = ERR_FILE;

    if (size <= 0)
        rc = ERR_FILE_READ;

    return rc;
}

proc_err_t allocate_edge_arr(edge_t *&edge, int size)
{
    edge_t *buf = (edge_t *)malloc(sizeof(edge_t) * size);
    if (!buf)
        return ERR_MEM;

    edge = buf;

    return OK;
}

void free_edge_arr(edge_t *edge)
{
    if (edge)
        free(edge);
}

proc_err_t read_edge_arr_elems(edge_t *edges_arr, int size, FILE *f)
{
    proc_err_t rc = OK;
    int i = 0;
    while (!rc && i < size)
    {
        rc = read_edge(edges_arr[i], f);
        ++i;
    }

    return rc;
}

proc_err_t read_edge_arr(edge_arr_t &edge, FILE *f)
{
    if (!f)
        return ERR_FILE;

    proc_err_t rc = read_edge_count(edge.size, f);
    if (!rc)
    {
        rc = allocate_edge_arr(edge.data, edge.size);

        if (!rc)
            rc = read_edge_arr_elems(edge.data, edge.size, f);

        if (rc)
            free_edge_arr(edge.data);
    }

    return rc;
}

proc_err_t write_edge_arr(edge_arr_t &edge, FILE *f)
{
    if (!f)
        return ERR_FILE;

    fprintf(f, "%d\n", edge.size);
    for (int i = 0; i < edge.size; ++i)
        (void)write_edge(edge.data[i], f);

    return OK;
}

proc_err_t check_edge_arr(edge_arr_t &edge, int max_num)
{
    for (int i = 0; i < edge.size; ++i)
        if (check_edge(edge.data[i], max_num) != OK)
            return ERR_FILE_READ;

    return OK;
}
