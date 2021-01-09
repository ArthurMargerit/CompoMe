#pragma once

#include "Data/CompoMe.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>
#include <tuple>

namespace CompoMe {
class Caller_stream;
class Fake_stream;

class Caller_dbus;
class Fake_dbus;

class Function_dbus_send;
class Return_dbus_recv;

class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace CompoMe {

class Component_Control_caller_stream;

class Component_Control_fake_stream;
class Component_Control_fake_dbus;

class Component_Control : public CompoMe::Interface {
public:
  using T_p_stream = std::tuple<Component_Control_fake_stream *,
                                CompoMe::Fake_stream *, Component_Control *>;
  using T_p_dbus = std::tuple<Component_Control_fake_dbus *,
                              CompoMe::Fake_dbus *, Component_Control *>;

  static T_p_stream get_fake_stream(CompoMe::Function_stream_send &fs,
                                    CompoMe::Return_stream_recv &rs);

  static T_p_dbus get_fake_dbus(CompoMe::Function_dbus_send &fs,
                                CompoMe::Return_dbus_recv &rs) {
    return std::make_tuple<Component_Control_fake_dbus *, CompoMe::Fake_dbus *,
                           Component_Control *>(nullptr, nullptr, nullptr);
  }

  using MyCallerStream = CompoMe::Component_Control_caller_stream;

  //// Caller function ////////////////////////////////////////////////////////
  CompoMe::Caller_stream *get_caller_stream() override;

  //! Default constructor
  Component_Control();

  //! Destructor
  virtual ~Component_Control() noexcept;
  virtual void step() = 0;
  virtual void step3() = 0;
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void init() = 0;
  virtual void uninit() = 0;
  virtual void connect() = 0;
  virtual void configure() = 0;
  virtual CompoMe::String name() = 0;
  virtual CompoMe::Component_state state() = 0;
  virtual CompoMe::String status() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  CompoMe::Caller_stream *a_caller_stream;
};

} // namespace CompoMe

#include "Interfaces/CompoMe/Component_Control/Component_Control_caller_stream.hpp"

#include "Interfaces/CompoMe/Component_Control/Component_Control_fake_stream.hpp"
