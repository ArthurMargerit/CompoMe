
#include "Interfaces/CompoMe/Component_Control/Component_Control_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace CompoMe {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Component_Control_caller_stream::Component_Control_caller_stream(
    Component_Control &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Component_Control_caller_stream::call(CompoMe::Function_stream_recv &is,
                                           CompoMe::Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool Component_Control_caller_stream::call(std::string &name_function,
                                           CompoMe::Function_stream_recv &is,
                                           CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("step"):
    result = this->step(is, os);
    break;

  case str2int("start"):
    result = this->start(is, os);
    break;

  case str2int("stop"):
    result = this->stop(is, os);
    break;

  case str2int("init"):
    result = this->init(is, os);
    break;

  case str2int("uninit"):
    result = this->uninit(is, os);
    break;

  case str2int("connect"):
    result = this->connect(is, os);
    break;

  case str2int("configure"):
    result = this->configure(is, os);
    break;

  case str2int("name"):
    result = this->name(is, os);
    break;

  case str2int("state"):
    result = this->state(is, os);
    break;

  case str2int("status"):
    result = this->status(is, os);
    break;
  };

  return result;
}

bool Component_Control_caller_stream::step(CompoMe::Function_stream_recv &is,
                                           CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.step();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Component_Control_caller_stream::start(CompoMe::Function_stream_recv &is,
                                            CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.start();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Component_Control_caller_stream::stop(CompoMe::Function_stream_recv &is,
                                           CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.stop();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Component_Control_caller_stream::init(CompoMe::Function_stream_recv &is,
                                           CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.init();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Component_Control_caller_stream::uninit(CompoMe::Function_stream_recv &is,
                                             CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.uninit();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Component_Control_caller_stream::connect(CompoMe::Function_stream_recv &is,
                                              CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.connect();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Component_Control_caller_stream::configure(
    CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.configure();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Component_Control_caller_stream::name(CompoMe::Function_stream_recv &is,
                                           CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.name();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Component_Control_caller_stream::state(CompoMe::Function_stream_recv &is,
                                            CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.state();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Component_Control_caller_stream::status(CompoMe::Function_stream_recv &is,
                                             CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    os << this->comp.status();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace CompoMe
