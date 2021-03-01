#include "Components/CompoMe/Component_Core.hpp"
#include "Components/CompoMe/Component_Core_Component_Control_handle.hpp"
#include "Errors/CompoMe/Component_Core_ns/Wrong_state_transition.hpp"
#include <iostream>

namespace CompoMe {

void Component_Core_Component_Control_handle::step() {
  auto v_state = this->get_c().get_state();

  if (!is(v_state, Component_state::STARTED)) {
    C_ERROR("Wrong state translation",
            "to do a step you need to start component first");
    {
      Component_Core_ns::Wrong_state_transition s;
      s.set_to(v_state);
      s.set_from(v_state);
      s.set_msg("This component is not STARTED");
      s.real();
    }
    return;
  }

  if (is(v_state, Component_state::DEAD)) {
    C_ERROR("Wrong state translation",
            "to do a step your component need to stop and restart");
    {
      Component_Core_ns::Wrong_state_transition s;
      s.set_to(v_state);
      s.set_from(v_state);
      s.set_msg("This component is DEAD");
      s.real();
    }
    return;
  }

  // do component step
  this->get_c().step();
  return;
}
void Component_Core_Component_Control_handle::start() {

  auto v_state = this->get_c().get_state();

  if (!is(v_state, Component_state::CONFIGURED)) {
    C_ERROR("Wrong state translation",
            "to do a start you need to configure component first");
    {
      Component_Core_ns::Wrong_state_transition s;
      s.set_to(Component_state::STARTED);
      s.set_from(v_state);
      s.set_msg("This component is not CONFIGURED");
      s.real();
    }

    return;
  }

  if (!is(v_state, Component_state::CONNECTED)) {
    C_ERROR("Wrong state translation",
            "to do a start you need to connect component first");
    {
      Component_Core_ns::Wrong_state_transition s;
      s.set_to(Component_state::STARTED);
      s.set_from(v_state);
      s.set_msg("This component is not CONNECTED");
      s.real();
    }

    return;
  }

  if (is(v_state, Component_state::STARTED)) {
    C_ERROR("Wrong state translation",
            "You cannot call a start on a component already started");
    {
      Component_Core_ns::Wrong_state_transition s;
      s.set_to(Component_state::STARTED);
      s.set_from(v_state);
      s.set_msg("This component is already STARTED");
      s.real();
    }

    return;
  }

  // do component start
  this->get_c().start();
  this->get_c().set_state(v_state | Component_state::STARTED);
  return;
}
void Component_Core_Component_Control_handle::stop() {
  auto v_state = this->get_c().get_state();

  if (!is(v_state, Component_state::STARTED)) {
    C_ERROR("Wrong state translation",
            "to do a stop you need to start component first");
    {
      Component_Core_ns::Wrong_state_transition s;
      s.set_to(v_state);
      s.set_from(v_state);
      s.set_msg("This component is already STARTED");
      s.real();
    }

    return;
  }

  this->get_c().stop();
  this->get_c().set_state(v_state & ~Component_state::STARTED);
  return;
}
void Component_Core_Component_Control_handle::init() {
  auto v_state = this->get_c().get_state();
  this->get_c().set_state(v_state | Component_state::INITIALIZED);
  return;
}
void Component_Core_Component_Control_handle::uninit() {
  auto v_state = this->get_c().get_state();
  this->get_c().set_state(v_state & ~Component_state::INITIALIZED);
  return;
}
void Component_Core_Component_Control_handle::connect() {
  auto v_state = this->get_c().get_state();

  if (!CompoMe::is(v_state, Component_state::INITIALIZED) == true) {
    C_ERROR("Wrong state translation",
            "to do a configured you need to initialized component first");
    Component_Core_ns::Wrong_state_transition s;
    s.set_to(Component_state::CONNECTED);
    s.set_from(v_state);
    s.set_msg("This component is not initialized");
    s.real();
    return;
  }

  this->get_c().connection();
  this->get_c().set_state(v_state | Component_state::CONNECTED);
  return;
}
void Component_Core_Component_Control_handle::configure() {

  auto v_state = this->get_c().get_state();
  if (!is(v_state, Component_state::INITIALIZED)) {
    C_ERROR("Wrong state translation",
            "to do a configured you need to initialized component first");
    {
      Component_Core_ns::Wrong_state_transition s;
      s.set_to(Component_state::CONFIGURED);
      s.set_from(v_state);
      s.set_msg("This component is not initialized");
      s.real();
    }
    return;
  }

  this->get_c().configuration();
  this->get_c().set_state(v_state | Component_state::CONFIGURED);
  return;
}
CompoMe::String Component_Core_Component_Control_handle::name() {

  return this->get_c().get_name();
}
CompoMe::Component_state Component_Core_Component_Control_handle::state() {
  return this->get_c().get_state();
}
CompoMe::String Component_Core_Component_Control_handle::status() {
  return CompoMe::String("Test");
}
} // namespace CompoMe
