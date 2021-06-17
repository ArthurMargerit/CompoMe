#pragma once

#include "Interfaces/Function_stream_send.hpp"
#include "Types/CompoMe/String.hpp"
#include <functional>
#include <sstream>

namespace CompoMe {
class Function_stream_send_func : public CompoMe::Function_stream_send {
private:
  using f_bs = std::function<bool(CompoMe::String &)>;
  f_bs func_send;
  std::stringstream ss;

public:
  const f_bs get_func_send() const { return func_send; }
  void set_func_send(const f_bs func_send) { this->func_send = func_send; }

  Function_stream_send_func();
  Function_stream_send_func(const CompoMe::Function_stream_send_func&){}
  virtual ~Function_stream_send_func();

  std::ostream &get_so() override;
  void start() override;
  void send() override;

  CompoMe::Function_stream_send_func &
  operator=(const CompoMe::Function_stream_send_func &t) {
    if (this == &t) {
      return *this;
    }

    return *this;
  }
};
} // namespace CompoMe
