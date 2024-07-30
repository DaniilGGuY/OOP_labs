#ifndef PROCERRORS_H
#define PROCERRORS_H

#include <exception>


class Error : public std::exception
{
public:
    Error(const char *time, const char *filename, const size_t line,
          const char *classname, const char *methodname, const char *info);
    virtual const char *what() const noexcept override;
protected:
    static const size_t size = 512;
    char msg[size] = "";
};


class IteratorErr : public Error
{
public:
    IteratorErr(const char *time, const char *filename, const size_t line,
                const char *classname, const char *methodname, const char *info = "Iterator error");
};


class ListErr : public Error
{
public:
    ListErr(const char *time, const char *filename, const size_t line,
            const char *classname, const char *methodname, const char *info = "List error");
};


class MemoryErr : public Error
{
public:
    MemoryErr(const char* time, const char* filename, const size_t line,
        const char* classname, const char* methodname, const char* info = "Memory error");
};


class RangeErr : public ListErr 
{
public:
    RangeErr(const char* time, const char* filename, const size_t line,
        const char* classname, const char* methodname, const char* info = "List out of range");
};


class SizeErr : public ListErr 
{
public:
    SizeErr(const char* time, const char* filename, const size_t line,
        const char* classname, const char* methodname, const char* info = "Invalid size");
};


class EmptyErr : public ListErr 
{
public:
    EmptyErr(const char* time, const char* filename, const size_t line,
        const char* classname, const char* methodname, const char* info = "List is empty");
};


class PointerErr : public IteratorErr
{
public:
    PointerErr(const char* time, const char* filename, const size_t line,
        const char* classname, const char* methodname, const char* info = "Error with *");
};


class ReferenceErr : public IteratorErr
{
public:
    ReferenceErr(const char* time, const char* filename, const size_t line,
        const char* classname, const char* methodname, const char* info = "Error with ->");
};


#include "procerrors.cpp"

#endif // PROCERRORS_H
