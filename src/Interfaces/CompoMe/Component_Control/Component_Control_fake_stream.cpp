#include "Interfaces/CompoMe/Component_Control/Component_Control_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

namespace CompoMe {

Component_Control::T_p_stream
Component_Control::get_fake_stream(CompoMe::Function_stream_send &fs,
                                   CompoMe::Return_stream_recv &rs) {
  Component_Control_fake_stream *a = new Component_Control_fake_stream(fs, rs);
  std::tuple<Component_Control_fake_stream *, CompoMe::Fake_stream *,
             Component_Control *>
      rr(a, a, a);
  return rr;
}

Component_Control_fake_stream::Component_Control_fake_stream(
    CompoMe::Function_stream_send &out, CompoMe::Return_stream_recv &in)
    : CompoMe::Fake_stream(out, in) {}

Component_Control_fake_stream::~Component_Control_fake_stream() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Component_Control
// ////////////////////////////////////////////////

void Component_Control_fake_stream::start() {
  this->get_o().start();
  this->get_o() << "start("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void Component_Control_fake_stream::stop() {
  this->get_o().start();
  this->get_o() << "stop("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void Component_Control_fake_stream::init() {
  this->get_o().start();
  this->get_o() << "init("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void Component_Control_fake_stream::uninit() {
  this->get_o().start();
  this->get_o() << "uninit("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void Component_Control_fake_stream::connect() {
  this->get_o().start();
  this->get_o() << "connect("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

void Component_Control_fake_stream::configure() {
  this->get_o().start();
  this->get_o() << "configure("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  return;
}

CompoMe::String Component_Control_fake_stream::name() {
  this->get_o().start();
  this->get_o() << "name("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  CompoMe::String ri = CompoMe::String();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

CompoMe::Component_state Component_Control_fake_stream::state() {
  this->get_o().start();
  this->get_o() << "state("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  CompoMe::Component_state ri = CompoMe::Component_state();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

CompoMe::String Component_Control_fake_stream::status() {
  this->get_o().start();
  this->get_o() << "status("
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if (this->get_i().get_si().peek() == '!') {
    this->get_i().get_si().get(); // remove !
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  CompoMe::String ri = CompoMe::String();
  this->get_i() >> ri;
  this->get_i().end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Component_Control
// /////////////////////////////////////////////////

} // namespace CompoMe
