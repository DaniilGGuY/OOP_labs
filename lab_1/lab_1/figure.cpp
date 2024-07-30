#include "figure.h"

figure_t figure_init(void)
{
    figure_t tmp;

    tmp.edges = edge_arr_init();
    tmp.vertexes = vertex_arr_init();

    return tmp;
}

void copy_figure(figure_t &figure, figure_t tmp)
{
    vertex_arr_copy(figure.vertexes, tmp.vertexes);
    edge_arr_copy(figure.edges, tmp.edges);
}

proc_err_t read_fields_figure(figure_t &tmp, FILE *f)
{
    proc_err_t rc = read_vertex_arr(tmp.vertexes, f);
    if (!rc)
    {
        rc = read_edge_arr(tmp.edges, f);
        if (rc)
            free_vertexes(tmp.vertexes);
    }

    return rc;
}

proc_err_t read_figure(figure_t &figure, const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return ERR_FILE;

    figure_t tmp = figure_init();

    proc_err_t rc = read_fields_figure(tmp, f);

    fclose(f);

    if (!rc)
    {
        rc = check_figure(figure);
        if (rc)
            free_figure(tmp);
        else
        {
            free_figure(figure);
            figure = figure_init();
            copy_figure(figure, tmp);
        }
    }

    return rc;
}

proc_err_t write_figure(figure_t &figure, const char *filename)
{
    FILE *f = fopen(filename, "w");
    if (!f)
        return ERR_FILE;

    proc_err_t rc = write_vertex_arr(figure.vertexes, f);
    if (!rc)
        rc = write_edge_arr(figure.edges, f);

    fclose(f);

    return rc;
}

proc_err_t figure_transfer(figure_t &figure, const transfer_t transfer)
{
    return transfer_vertex_arr(figure.vertexes, transfer);
}

proc_err_t figure_scale(figure_t &figure, const scale_t scale)
{
    return scale_vertex_arr(figure.vertexes, scale);
}

proc_err_t figure_rotate(figure_t &figure, const rotate_t rotate)
{
    return rotate_vertex_arr(figure.vertexes, rotate);
}

proc_err_t check_figure(figure_t &figure)
{
    return check_edge_arr(figure.edges, figure.vertexes.size);
}

void free_figure(figure_t &figure)
{
    free_edges(figure.edges);
    free_vertexes(figure.vertexes);
}

void free_vertexes(vertex_arr_t &vertexes)
{
    free_vertex_arr(vertexes.data);
}

void free_edges(edge_arr_t &edges)
{
    free_edge_arr(edges.data);
}
