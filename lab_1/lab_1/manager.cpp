#include "manager.h"

proc_err_t request_proc(request_t req)
{
    static figure_t figure = figure_init();
    proc_err_t rc = OK;

    switch (req.type)
    {
        case INIT:
            break;
        case LOAD_FILE:
            rc = read_figure(figure, req.filename);
            break;
        case UPLOAD_FILE:
            rc = write_figure(figure, req.filename);
            break;
        case DRAW:
            rc = draw_figure(figure, req.drawer);
            break;
        case TRANSFER:
            rc = figure_transfer(figure, req.transfer);
            break;
        case SCALE:
            rc = figure_scale(figure, req.scale);
            break;
        case ROTATE:
            rc = figure_rotate(figure, req.rotate);
            break;
        case FREE:
            free_figure(figure);
            break;
        default:
            rc = ERR_UNKNOWN;
    }

    return rc;
}
