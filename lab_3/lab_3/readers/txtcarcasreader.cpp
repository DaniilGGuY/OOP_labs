#include "txtcarcasreader.h"
#include "objects/strategy/basecentralstrategy.h"

TxtCarcasReader::TxtCarcasReader(const char *filename) : _filename(filename) {}

TxtCarcasReader::~TxtCarcasReader() { TxtCarcasReader::close(); }

void TxtCarcasReader::open()
{
    if (!_file.is_open())
    {
        _file.open(_filename);
    }
}

void TxtCarcasReader::close()
{
    if (_file.is_open())
        _file.close();
}

bool TxtCarcasReader::isOpen() { return _file.is_open(); }

std::vector<Point> TxtCarcasReader::readPoints()
{
    if (!_file.is_open())
        return std::vector<Point>();

    std::vector<Point> readed;
    _file.clear();
    _file.seekg(0, std::ios::beg);

    int size = 0;
    _file >> size;
    readed.resize(size);
    double x, y, z;
    for (int i = 0; i < size; ++i)
    {
        _file >> x >> y >> z;

        readed[i].setX(x);
        readed[i].setY(y);
        readed[i].setZ(z);

    }

    return readed;
}

std::vector<Edge> TxtCarcasReader::readEdges()
{
    if (!_file.is_open())
        return std::vector<Edge>();

    std::vector<Edge> readed;
    readPoints();

    int size = 0;
    _file >> size;
    readed.resize(size);
    size_t fst, sec;
    for (int i = 0; i < size; ++i)
    {
        _file >> fst >> sec;

        readed[i].setFirstVertex(fst - 1);
        readed[i].setSecondVertex(sec - 1);
    }

    return readed;
}

Point TxtCarcasReader::readCenter()
{
    std::vector<Point> points = readPoints();
    CenterStrategy strat;
    return strat.calcCenter(points);
}
