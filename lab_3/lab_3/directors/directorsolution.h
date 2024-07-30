#ifndef DIRECTORSOLUTION_H
#define DIRECTORSOLUTION_H

#include <map>

#include "directorcreator.h"

class DirectorSolution
{
public:
    DirectorSolution();
    DirectorSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseDirectorCreator>>> list);
    ~DirectorSolution();

    void registration(size_t index, std::shared_ptr<BaseDirectorCreator> creator);
    bool check(size_t index);
    std::shared_ptr<BaseDirectorCreator> create(size_t index);

private:
    std::map<size_t, std::shared_ptr<BaseDirectorCreator>> _creators;
};

#endif // DIRECTORSOLUTION_H
