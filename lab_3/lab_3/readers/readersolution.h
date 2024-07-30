#ifndef READERSOLUTION_H
#define READERSOLUTION_H

#include <map>

#include "basereader.h"
#include "basereadercreator.h"

class ReaderSolution
{
public:
    ReaderSolution();
    ReaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseReaderCreator>>> list);
    ~ReaderSolution();

    void registration(size_t index, std::shared_ptr<BaseReaderCreator> creator);
    bool check(size_t index);
    std::shared_ptr<BaseReaderCreator> create(size_t index);

private:
    std::map<size_t, std::shared_ptr<BaseReaderCreator>> _creators;
};

#endif // READERSOLUTION_H
