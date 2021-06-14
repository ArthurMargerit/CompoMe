#include "Interfaces/Function_stream_send_func.hpp"
#include <iostream>

namespace CompoMe {

Function_stream_send_func::Function_stream_send_func() {}

Function_stream_send_func::~Function_stream_send_func() {}

void Function_stream_send_func::start() { this->ss.str(""); }
void Function_stream_send_func::send() {
  CompoMe::String t (this->ss.str());
  this->func_send(t);
  return;
}

std::ostream &Function_stream_send_func::get_so() { return this->ss; };
} // namespace CompoMe
