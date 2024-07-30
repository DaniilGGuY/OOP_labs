#include "object.h"

size_t getObjectId()
{
    static size_t id = 0;
    return id++;
}

Object::Object() : _id(getObjectId()) {}

Object::~Object() {}

Object::iterator Object::begin() { return iterator(); }

Object::iterator Object::end() { return iterator(); }

void Object::add(std::shared_ptr<Object> obj) { (void)obj; };

void Object::remove(const iterator &it) { (void)it; };

std::shared_ptr<Object> Object::clone() const { return nullptr; };

void Object::accept(std::shared_ptr<Visitor> visitor) { (void)visitor; }

size_t Object::getId() const { return _id; }
