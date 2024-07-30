#include <QMessageBox>

#include "processerror.h"

void throw_error(const proc_err_t err)
{
    switch (err)
    {
        case OK:
            break;
        case ERR_FILE:
            QMessageBox::critical(NULL, "Ошибка", ERR_FILE_MSG);
            break;
        case ERR_FILE_READ:
            QMessageBox::critical(NULL, "Ошибка", ERR_FILE_READ_MSG);
            break;
        case ERR_ROTATE:
            QMessageBox::critical(NULL, "Ошибка", ERR_ROTATE_MSG);
            break;
        case ERR_SCALE:
            QMessageBox::critical(NULL, "Ошибка", ERR_SCALE_MSG);
            break;
        case ERR_TRANSFER:
            QMessageBox::critical(NULL, "Ошибка", ERR_TRANSFER_MSG);
            break;
        case ERR_MEM:
            QMessageBox::critical(NULL, "Ошибка", ERR_MEM_MSG);
            break;
        case ERR_UI_FORMS:
            QMessageBox::critical(NULL, "Ошибка", ERR_UI_FORMS_MSG);
            break;
        case ERR_EDGE:
            QMessageBox::critical(NULL, "Ошибка", ERR_EDGE_MSG);
            break;
        case ERR_DRAW:
            QMessageBox::critical(NULL, "Ошибка", ERR_DRAWER_MSG);
            break;
        default:
            QMessageBox::critical(NULL, "Ошибка", ERR_UNKNOWN_MESSAGE);
            break;
    }
}
