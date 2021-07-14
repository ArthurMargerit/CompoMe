#pragma once

#include "Interfaces/Fake_stream.hpp"
#include "Interfaces/Function_stream_send_func.hpp"
#include "Interfaces/Return_stream_recv_func.hpp"

namespace CompoMe {
namespace Posix {
struct Fake_pack {
  Fake_pack() : f(nullptr), fss(), rss() {}

  CompoMe::Fake_stream *f;
  CompoMe::Function_stream_send_func fss;
  CompoMe::Return_stream_recv_func rss;
};
}; // namespace Posix
}; // namespace CompoMe
