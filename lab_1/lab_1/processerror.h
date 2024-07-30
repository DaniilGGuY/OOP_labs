#ifndef PROCESSERROR_H
#define PROCESSERROR_H

#define ERR_FILE_MSG                                             "Ошибка файла"
#define ERR_FILE_READ_MSG                          "Ошибка при чтении из файла"
#define ERR_TRANSFER_MSG                                  "Ошибка при переносе"
#define ERR_SCALE_MSG                              "Ошибка при масштабировании"
#define ERR_ROTATE_MSG                                    "Ошибка при повороте"
#define ERR_UNKNOWN_MESSAGE                                "Неизвестная ошибка"
#define ERR_MEM_MSG                                   "Ошибка работы с памятью"
#define ERR_UI_FORMS_MSG                 "Ошибка в веденных на форме значениях"
#define ERR_EDGE_MSG   "Ошибка: проведение ребра с такими вершинами невозможно"
#define ERR_DRAWER_MSG                            "Ошибка при отрисовке фигуры"

enum proc_err_t
{
    OK,
    ERR_UNKNOWN,
    ERR_FILE,
    ERR_FILE_READ,
    ERR_TRANSFER,
    ERR_SCALE,
    ERR_ROTATE,
    ERR_MEM,
    ERR_UI_FORMS,
    ERR_EDGE,
    ERR_DRAW,
};

void throw_error(const proc_err_t err);

#endif // PROCESSERROR_H
