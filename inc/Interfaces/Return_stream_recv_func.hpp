#pragma once

#include "Interfaces/Return_stream_recv.hpp"
#include "Types/CompoMe/String.hpp"
#include <sstream>
#include <functional>

namespace CompoMe {
class Return_stream_recv_func : public Return_stream_recv {
private:
  using f_bs = std::function<bool(CompoMe::String &)>;
  f_bs func_recv;
  std::stringstream ss;

public:
  const f_bs get_func_recv() const { return func_recv; }
  void set_func_recv(const f_bs func_recv) { this->func_recv = func_recv; }

  Return_stream_recv_func();
  virtual ~Return_stream_recv_func();

  std::istream &get_si() override;

  void pull() override;
  void end() override;
};
} // namespace CompoMe
