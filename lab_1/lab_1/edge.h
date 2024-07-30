#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>

#include "processerror.h"

struct edge_t
{
    int vertex1;
    int vertex2;
};

edge_t edge_init(int vertex1, int vertex2);

proc_err_t read_edge(edge_t &edge, FILE *f);

proc_err_t write_edge(edge_t &edge, FILE *f);

proc_err_t check_edge(edge_t edge, int max_num);

#endif // EDGE_H
