#pragma once

#include <ostream>
namespace CompoMe {

class Function_stream_send {
public:
  virtual ~Function_stream_send(){};
  virtual std::ostream &get_so() = 0;
  virtual void start() = 0;
  virtual void send() = 0;
};

template <typename T>
CompoMe::Function_stream_send &operator<<(CompoMe::Function_stream_send &s,
                                          const T &e) {
  s.get_so() << e;
  return s;
}

} // namespace CompoMe