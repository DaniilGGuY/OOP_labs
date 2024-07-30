#include "basemodel.h"

BaseModel::BaseModel() {}

BaseModel::~BaseModel() {}

BaseModel::iterator BaseModel::begin() { return iterator(); }

BaseModel::iterator BaseModel::end() { return iterator(); }

void BaseModel::add(std::shared_ptr<Object> obj) { (void)obj; };

void BaseModel::remove(const iterator &it) { (void)it; };

std::shared_ptr<Object> BaseModel::clone() const { return nullptr; };

void BaseModel::accept(std::shared_ptr<Visitor> visitor) { (void)visitor; }
