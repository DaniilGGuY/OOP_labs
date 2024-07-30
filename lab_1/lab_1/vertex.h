#ifndef VERTEX_H
#define VERTEX_H

#include <stdio.h>

#include "processerror.h"

struct vertex_t
{
    double x;
    double y;
    double z;
};

struct transfer_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_t
{
    double kx;
    double ky;
    double kz;
    vertex_t center;
};

struct rotate_t
{
    double x_rot;
    double y_rot;
    double z_rot;
    vertex_t center;
};

vertex_t vertex_init(double x, double y, double z);

transfer_t transfer_init(double dx, double dy, double dz);

scale_t scale_init(double kx, double ky, double kz);

rotate_t rotate_init(double x_rot, double y_rot, double z_rot);

double to_radians(double degrees);

proc_err_t read_vertex(vertex_t &vertex, FILE *f);

proc_err_t write_vertex(vertex_t &vertex, FILE *f);

void transfer_vertex(vertex_t &vertex, const transfer_t transfer);

void scale_vertex(vertex_t &vertex, const scale_t scale);

void rotate_vertex(vertex_t &vertex, const rotate_t rotate);

#endif // VERTEX_H
