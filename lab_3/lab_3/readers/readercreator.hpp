#ifndef READERCREATOR_HPP
#define READERCREATOR_HPP

#include "readercreator.h"

template <typename Base, typename Deriv, typename... Args>
std::shared_ptr<Base> ReaderCreator<Base, Deriv, Args...>::create(Args&&... args) { return std::make_shared<Deriv>(args...); }

#endif // READERCREATOR_HPP
