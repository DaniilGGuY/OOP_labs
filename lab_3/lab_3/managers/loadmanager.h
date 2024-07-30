#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "directors/directorsolution.h"
#include "readers/readersolution.h"

#define LIST_CARCAS_DIRECTOR_ID     1
#define MATRIX_CARCAS_DIRECTOR_ID   2

#define TXT_FILE_READER_ID          1

class LoadManager
{
public:
    LoadManager();
    ~LoadManager() = default;

    std::shared_ptr<Object> loadCarcas(size_t director_id, size_t reader_id, const char *filename);

private:
    DirectorSolution _dsol;
    ReaderSolution _rsol;
};

#endif // LOADMANAGER_H
