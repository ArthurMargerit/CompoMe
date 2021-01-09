#pragma once

#include <istream>

namespace CompoMe {
class Function_stream_recv {
public:
  virtual ~Function_stream_recv(){};
  virtual std::istream &get_si() = 0;

  virtual void pull() = 0;
  virtual void end() = 0;
  char get() { return this->get_si().get(); }
};

template <typename T>
CompoMe::Function_stream_recv &operator>>(CompoMe::Function_stream_recv &s,
                                          T &e) {
  s.get_si() >> e;
  return s;
}

} // namespace CompoMe