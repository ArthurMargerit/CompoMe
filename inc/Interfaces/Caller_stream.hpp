#pragma once

#include <sstream>

namespace CompoMe {

class Function_stream_recv;
class Return_stream_send;

class Caller_stream {
public:
  Caller_stream();
  virtual ~Caller_stream();

  virtual bool call(CompoMe::Function_stream_recv &is,
                    CompoMe::Return_stream_send &os) = 0;

  virtual bool call(std::string &name_function,
                    CompoMe::Function_stream_recv &is,
                    CompoMe::Return_stream_send &os) = 0;

  virtual void introspection(std::ostream &ss) {
    ss << "No Introspection Unavailable for <CompoMe::Interface>";
    return;
  }
};
} // namespace CompoMe