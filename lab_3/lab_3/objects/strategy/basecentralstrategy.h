#ifndef BASECENTRALSTRATEGY_H
#define BASECENTRALSTRATEGY_H

#include <vector>

#include "objects/point.h"

class BaseCentralStrategy
{
public:
    BaseCentralStrategy() = default;
    virtual ~BaseCentralStrategy() = 0;
    virtual Point calcCenter(std::vector<Point> points) const = 0;
};

class CenterStrategy : public BaseCentralStrategy
{
public:
    CenterStrategy() = default;
    ~CenterStrategy() = default;
    Point calcCenter(std::vector<Point> points) const override;
};

#endif // BASECENTRALSTRATEGY_H
