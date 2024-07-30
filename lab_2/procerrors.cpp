#include <string>

#include "procerrors.h"

Error::Error(const char *time, const char *filename, const size_t line,
             const char *classname, const char *methodname, const char *info)
{
    sprintf_s(msg, size, "Error! Time %s, file %s, line %zu, class %s, method %s, info: %s\n",
             time, filename, line, classname, methodname, info);
}

const char *Error::what() const noexcept
{
    return msg;
}

IteratorErr::IteratorErr(const char *time, const char *filename, const size_t line,
        const char *classname, const char *methodname, const char *info)
    : Error(time, filename, line, classname, methodname, info) {}

ListErr::ListErr(const char *time, const char *filename, const size_t line,
        const char *classname, const char *methodname, const char *info)
    : Error(time, filename, line, classname, methodname, info) {}

MemoryErr::MemoryErr(const char* time, const char* filename, const size_t line, 
        const char* classname, const char* methodname, const char* info)
    : Error(time, filename, line, classname, methodname, info) {}

RangeErr::RangeErr(const char* time, const char* filename, const size_t line, 
        const char* classname, const char* methodname, const char* info)
    : ListErr(time, filename, line, classname, methodname, info) {}

SizeErr::SizeErr(const char* time, const char* filename, const size_t line, 
        const char* classname, const char* methodname, const char* info)
    : ListErr(time, filename, line, classname, methodname, info) {}


EmptyErr::EmptyErr(const char* time, const char* filename, const size_t line, 
        const char* classname, const char* methodname, const char* info)
    : ListErr(time, filename, line, classname, methodname, info) {}


PointerErr::PointerErr(const char* time, const char* filename, const size_t line, 
        const char* classname, const char* methodname, const char* info)
    : IteratorErr(time, filename, line, classname, methodname, info) {}


ReferenceErr::ReferenceErr(const char* time, const char* filename, const size_t line, 
        const char* classname, const char* methodname, const char* info)
    : IteratorErr(time, filename, line, classname, methodname, info) {}

