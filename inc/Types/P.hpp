#pragma once

#include <istream>
#include <ostream>

#include "CompoMe/Pointer.hpp"

template <typename T> using P = CompoMe::Pointer<T>;

namespace std {

template <typename T> std::ostream &operator<<(std::ostream &os, const P<T> &) {
  return os;
}

template <typename T> std::istream &operator>>(std::istream &is, P<T> &) {
  return is;
}
} // namespace std
