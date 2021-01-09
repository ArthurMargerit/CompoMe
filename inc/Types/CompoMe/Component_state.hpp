#pragma once

#include <istream>
#include <ostream>

#include "Types/ui32.hpp"

namespace CompoMe {

enum class Component_state : ui32 {

  INITIALIZED = 1,

  CONFIGURED = 2,

  CONNECTED = 4,

  STARTED = 8,

  DEGRADED = 16,

  DEAD = 32,

  STRESSED = 64,

  UNKNOWN = 128

};

inline Component_state operator|(const Component_state a,
                                 const Component_state b) {
  return static_cast<Component_state>(static_cast<ui32>(a) |
                                      static_cast<ui32>(b));
}

inline Component_state operator&(const Component_state a,
                                 const Component_state b) {
  return static_cast<Component_state>(static_cast<ui32>(a) &
                                      static_cast<ui32>(b));
}

inline bool is(const Component_state a, const Component_state b) {
  return (a & b) == b;
}

} // namespace CompoMe

namespace std {

std::ostream &operator<<(std::ostream &os, const CompoMe::Component_state &);

std::istream &operator>>(std::istream &is, CompoMe::Component_state &);
} // namespace std
