#ifndef BASEREADER_H
#define BASEREADER_H

class BaseReader
{
public:
    BaseReader() = default;
    virtual ~BaseReader() = 0;

    virtual void open() = 0;
    virtual void close() = 0;

    virtual bool isOpen() = 0;
};

#endif // BASEREADER_H
