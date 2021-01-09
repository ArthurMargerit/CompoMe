#pragma once

#include "Data/CompoMe.hpp"

#include "Interfaces/CompoMe/Component_Control/Component_Control.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace CompoMe {

class Component_Control_fake_stream : public CompoMe::Component_Control,
                                      public CompoMe::Fake_stream {
public:
  // constructor
  Component_Control_fake_stream(CompoMe::Function_stream_send &out,
                                CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Component_Control_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<CompoMe::Component_Control*>(new
  //   CompoMe::Component_Control_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void step() override;

  virtual void step2() override;

  virtual void start() override;

  virtual void stop() override;

  virtual void init() override;

  virtual void uninit() override;

  virtual void connect() override;

  virtual void configure() override;

  virtual CompoMe::String name() override;

  virtual CompoMe::Component_state state() override;

  virtual CompoMe::String status() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};

} // namespace CompoMe
