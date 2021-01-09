
#include "Interfaces/CompoMe/Component_Control/Component_Control.hpp"

namespace CompoMe {

Component_Control::Component_Control() : a_caller_stream(nullptr) {}

Component_Control::~Component_Control() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Component_Control::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace CompoMe
