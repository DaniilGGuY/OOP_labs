#include "loadmanager.h"
#include "readers/readercreator.h"

LoadManager::LoadManager()
{
    _dsol.registration(LIST_CARCAS_DIRECTOR_ID, std::make_shared<ListCarcasDirectorCreator>());
    _dsol.registration(MATRIX_CARCAS_DIRECTOR_ID, std::make_shared<MatrixCarcasDirectorCreator>());

    _rsol.registration(TXT_FILE_READER_ID, std::make_shared<TxtCarcasReaderCreator>());
}

std::shared_ptr<Object> LoadManager::loadCarcas(size_t director_id, size_t reader_id, const char *filename)
{
    std::shared_ptr<BaseDirectorCreator> direct_cr = _dsol.create(director_id);
    std::shared_ptr<BaseReaderCreator> read_cr = _rsol.create(reader_id);

    std::shared_ptr<CarcasDirectorCreator> carcas_direct_cr = std::static_pointer_cast<CarcasDirectorCreator>(direct_cr);
    std::shared_ptr<CarcasReaderCreator> carcas_read_cr = std::static_pointer_cast<CarcasReaderCreator>(read_cr);

    std::shared_ptr<CarcasReader> carcas_reader = carcas_read_cr->create(std::move(filename));
    std::shared_ptr<BaseCarcasDirector> carcas_director = carcas_direct_cr->create(std::move(carcas_reader));

    return carcas_director->create();
}
