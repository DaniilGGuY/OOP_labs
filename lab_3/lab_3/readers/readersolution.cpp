#include "readersolution.h"

ReaderSolution::ReaderSolution() : _creators(std::map<size_t, std::shared_ptr<BaseReaderCreator>>()) {}

ReaderSolution::ReaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseReaderCreator>>> list)
{
    for (const auto &it : list)
        _creators[it.first] = it.second;
}

ReaderSolution::~ReaderSolution() {}

void ReaderSolution::registration(size_t index, std::shared_ptr<BaseReaderCreator> creator)
{
    if (!check(index))
        _creators[index] = creator;
}

bool ReaderSolution::check(size_t index) { return _creators.find(index) != _creators.end(); }

std::shared_ptr<BaseReaderCreator> ReaderSolution::create(size_t index)
{
    if (check(index))
        return _creators[index];
    return std::shared_ptr<BaseReaderCreator>();
}
