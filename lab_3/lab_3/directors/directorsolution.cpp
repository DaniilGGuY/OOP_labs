#include "directorsolution.h"

DirectorSolution::DirectorSolution() : _creators(std::map<size_t, std::shared_ptr<BaseDirectorCreator>>()) {}

DirectorSolution::DirectorSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseDirectorCreator>>> list)
{
    for (const auto &it : list)
        _creators[it.first] = it.second;
}

DirectorSolution::~DirectorSolution() {}

void DirectorSolution::registration(size_t index, std::shared_ptr<BaseDirectorCreator> creator)
{
    if (!check(index))
        _creators[index] = creator;
}

bool DirectorSolution::check(size_t index) { return _creators.find(index) != _creators.end(); }

std::shared_ptr<BaseDirectorCreator> DirectorSolution::create(size_t index)
{
    if (check(index))
        return _creators[index];
    return std::shared_ptr<BaseDirectorCreator>();
}
