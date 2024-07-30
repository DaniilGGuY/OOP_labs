#include "edge.h"

edge_t edge_init(int vertex1, int vertex2)
{
    edge_t new_edge;

    new_edge.vertex1 = vertex1;
    new_edge.vertex2 = vertex2;

    return new_edge;
}

proc_err_t read_edge(edge_t &edge, FILE *f)
{
    if (!f)
        return ERR_FILE;

    proc_err_t rc = OK;
    if (fscanf(f, "%d %d", &edge.vertex1, &edge.vertex2) != 2)
        rc = ERR_FILE_READ;

    return rc;
}

proc_err_t write_edge(edge_t &edge, FILE *f)
{
    if (!f)
        return ERR_FILE;

    fprintf(f, "%d %d\n", edge.vertex1, edge.vertex2);

    return OK;
}

proc_err_t check_edge(edge_t edge, int max_num)
{
    int vertex1 = edge.vertex1, vertex2 = edge.vertex2;
    if (vertex1 > max_num || vertex2 > max_num || vertex1 < 0 || vertex2 < 0)
        return ERR_FILE_READ;

    return OK;
}
