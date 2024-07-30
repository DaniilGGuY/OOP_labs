#ifndef DIRECTORCREATOR_HPP
#define DIRECTORCREATOR_HPP

#include "directorcreator.h"

template <typename Base, typename Deriv, typename... Args>
std::shared_ptr<Base> DirectorCreator<Base, Deriv, Args...>::create(Args&&... args) { return std::make_shared<Deriv>(args...); }

#endif // DIRECTORCREATOR_HPP
