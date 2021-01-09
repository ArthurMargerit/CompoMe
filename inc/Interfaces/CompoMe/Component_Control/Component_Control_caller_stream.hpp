#pragma once

#include "Interfaces/CompoMe/Component_Control/Component_Control.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace CompoMe {

class Component_Control_caller_stream : public CompoMe::Caller_stream {
private:
  CompoMe::Component_Control &comp;

public:
  Component_Control_caller_stream(CompoMe::Component_Control &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool step(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool start(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);

  bool stop(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool init(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool uninit(CompoMe::Function_stream_recv &is,
              CompoMe::Return_stream_send &os);

  bool connect(CompoMe::Function_stream_recv &is,
               CompoMe::Return_stream_send &os);

  bool configure(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);

  bool name(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool state(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);

  bool status(CompoMe::Function_stream_recv &is,
              CompoMe::Return_stream_send &os);
};

} // namespace CompoMe
