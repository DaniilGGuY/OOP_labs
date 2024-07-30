#ifndef MANAGER_H
#define MANAGER_H

#include "draw.h"
#include "figure.h"

enum types_rq_t
{
    INIT,
    LOAD_FILE,
    UPLOAD_FILE,
    DRAW,
    TRANSFER,
    SCALE,
    ROTATE,
    FREE
};

struct request_t
{
    types_rq_t type;
    union
    {
        const char *filename;
        transfer_t transfer;
        scale_t scale;
        rotate_t rotate;
        draw_t drawer;
    };
};

proc_err_t request_proc(request_t req);

#endif // MANAGER_H
