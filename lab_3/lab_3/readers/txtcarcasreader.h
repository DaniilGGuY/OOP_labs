#ifndef TXTCARCASREADER_H
#define TXTCARCASREADER_H

#include <memory>
#include <fstream>

#include "carcasreader.h"

class TxtCarcasReader : public CarcasReader
{
public:
    TxtCarcasReader(const char *filename);
    ~TxtCarcasReader();

    void open() override;
    void close() override;

    bool isOpen() override;

    std::vector<Point> readPoints() override;
    std::vector<Edge> readEdges() override;
    Point readCenter() override;

private:
    const char *_filename;
    std::ifstream _file;
};

#endif // TXTCARCASREADER_H
