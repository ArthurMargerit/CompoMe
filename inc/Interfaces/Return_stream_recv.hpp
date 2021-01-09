#pragma once

#include <istream>

namespace CompoMe {

class Return_stream_recv {
public:
  virtual ~Return_stream_recv(){};
  virtual std::istream &get_si() = 0;

  virtual void pull() = 0;
  virtual void end() = 0;
};

template <typename T>
CompoMe::Return_stream_recv &operator>>(CompoMe::Return_stream_recv &s, T &e) {
  s.get_si() >> e;
  return s;
}

} // namespace CompoMe