#include "Interfaces/Return_stream_recv_func.hpp"

namespace CompoMe {
Return_stream_recv_func::Return_stream_recv_func() {}
Return_stream_recv_func::~Return_stream_recv_func() {}

void Return_stream_recv_func::pull() {
  CompoMe::String t;
  this->func_recv(t);
  this->ss.clear();
  this->ss.str(t.str);
}

void Return_stream_recv_func::end() { this->ss.str(""); }

std::istream &Return_stream_recv_func::get_si() { return this->ss; }

} // namespace CompoMe
