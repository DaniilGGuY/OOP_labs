#ifndef CARCASREADER_H
#define CARCASREADER_H

#include <vector>

#include "basereader.h"
#include "objects/point.h"
#include "objects/edge.h"

class CarcasReader : public BaseReader
{
public:
    CarcasReader() = default;
    virtual ~CarcasReader() = 0;

    virtual void open() = 0;
    virtual void close() = 0;

    virtual bool isOpen() = 0;

    virtual std::vector<Point> readPoints() = 0;
    virtual std::vector<Edge> readEdges() = 0;
    virtual Point readCenter() = 0;
};

#endif // CARCASREADER_H
