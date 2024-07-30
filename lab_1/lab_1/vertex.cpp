#include <math.h>

#include "vertex.h"

vertex_t vertex_init(double x, double y, double z)
{
    vertex_t new_vertex;

    new_vertex.x = x;
    new_vertex.y = y;
    new_vertex.z = z;

    return new_vertex;
}

transfer_t transfer_init(double dx, double dy, double dz)
{
    transfer_t transfer;

    transfer.dx = dx;
    transfer.dy = dy;
    transfer.dz = dz;

    return transfer;
}

scale_t scale_init(double kx, double ky, double kz)
{
    scale_t scale;

    scale.kx = kx;
    scale.ky = ky;
    scale.kz = kz;

    return scale;
}

rotate_t rotate_init(double x_rot, double y_rot, double z_rot)
{
    rotate_t rotate;

    rotate.x_rot = x_rot;
    rotate.y_rot = y_rot;
    rotate.z_rot = z_rot;

    return rotate;
}

double to_radians(double degrees)
{
    return degrees * M_PI / 180;
}

proc_err_t read_vertex(vertex_t &vertex, FILE *f)
{
    if (!f)
        return ERR_FILE;

    proc_err_t rc = OK;
    if (fscanf(f, "%lf %lf %lf", &vertex.x, &vertex.y, &vertex.z) != 3)
        rc = ERR_FILE_READ;

    return rc;
}

proc_err_t write_vertex(vertex_t &vertex, FILE *f)
{
    if (!f)
        return ERR_FILE;

    fprintf(f, "%lf %lf %lf\n", vertex.x, vertex.y, vertex.z);

    return OK;
}

void transfer_vertex(vertex_t &vertex, const transfer_t transfer)
{
    vertex.x += transfer.dx;
    vertex.y += transfer.dy;
    vertex.z += transfer.dz;
}

void scale_vertex(vertex_t &vertex, const scale_t scale)
{
    vertex.x = scale.center.x + scale.kx * (vertex.x - scale.center.x);
    vertex.y = scale.center.y + scale.ky * (vertex.y - scale.center.y);
    vertex.z = scale.center.z + scale.kz * (vertex.z - scale.center.z);
}

static void rotate_around_x(vertex_t &vertex, const double angle)
{
    double rad_angle = to_radians(angle);
    double cos_angle = cos(rad_angle);
    double sin_angle = sin(rad_angle);

    double tmp = vertex.y;
    vertex.y = vertex.y * cos_angle - vertex.z * sin_angle;
    vertex.z = vertex.z * cos_angle + tmp * sin_angle;
}

static void rotate_around_y(vertex_t &vertex, const double angle)
{
    double rad_angle = to_radians(angle);
    double cos_angle = cos(rad_angle);
    double sin_angle = sin(rad_angle);

    double tmp = vertex.x;
    vertex.x = vertex.x * cos_angle - vertex.z * sin_angle;
    vertex.z = vertex.z * cos_angle + tmp * sin_angle;
}

static void rotate_around_z(vertex_t &vertex, const double angle)
{
    double rad_angle = to_radians(angle);
    double cos_angle = cos(rad_angle);
    double sin_angle = sin(rad_angle);

    double tmp = vertex.x;
    vertex.x = vertex.x * cos_angle - vertex.y * sin_angle;
    vertex.y = vertex.y * cos_angle + tmp * sin_angle;
}

void rotate_vertex(vertex_t &vertex, const rotate_t rotate)
{
    vertex_t center = rotate.center;
    transfer_t forward = transfer_init(-center.x, -center.y, -center.z);
    transfer_t back = transfer_init(center.x, center.y, center.z);

    transfer_vertex(vertex, forward);

    rotate_around_x(vertex, rotate.x_rot);

    rotate_around_y(vertex, rotate.y_rot);

    rotate_around_z(vertex, rotate.z_rot);

    transfer_vertex(vertex, back);
}
