#include "Types/CompoMe/Component_state.hpp"

#include "Serialization_context.hpp"
#include <string>

namespace CompoMe {} // namespace CompoMe

namespace std {
namespace {
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}
} // namespace

std::ostream &operator<<(std::ostream &os, const CompoMe::Component_state &c) {
  switch (c) {

  case CompoMe::Component_state::INITIALIZED:
    os << "CompoMe::Component_state::INITIALIZED";
    break;

  case CompoMe::Component_state::CONFIGURED:
    os << "CompoMe::Component_state::CONFIGURED";
    break;

  case CompoMe::Component_state::CONNECTED:
    os << "CompoMe::Component_state::CONNECTED";
    break;

  case CompoMe::Component_state::STARTED:
    os << "CompoMe::Component_state::STARTED";
    break;

  case CompoMe::Component_state::DEGRADED:
    os << "CompoMe::Component_state::DEGRADED";
    break;

  case CompoMe::Component_state::DEAD:
    os << "CompoMe::Component_state::DEAD";
    break;

  case CompoMe::Component_state::STRESSED:
    os << "CompoMe::Component_state::STRESSED";
    break;

  case CompoMe::Component_state::UNKNOWN:
    os << "CompoMe::Component_state::UNKNOWN";
    break;

  default:
    os << "ERROR";
  }

  return os;
}

std::istream &operator>>(std::istream &is, CompoMe::Component_state &c) {
  std::string str;
  str = CompoMe::get_word(is, {',', ')'}).first;
  switch (str2int(str.c_str())) {

  case str2int("1"):           // value
  case str2int("INITIALIZED"): // no namespace and typename space
  case str2int("Component_state::INITIALIZED"):          // no namespace space
  case str2int("CompoMe::Component_state::INITIALIZED"): // namespace
    c = CompoMe::Component_state::INITIALIZED;
    break;

  case str2int("2"):          // value
  case str2int("CONFIGURED"): // no namespace and typename space
  case str2int("Component_state::CONFIGURED"):          // no namespace space
  case str2int("CompoMe::Component_state::CONFIGURED"): // namespace
    c = CompoMe::Component_state::CONFIGURED;
    break;

  case str2int("4"):                          // value
  case str2int("CONNECTED"):                  // no namespace and typename space
  case str2int("Component_state::CONNECTED"): // no namespace space
  case str2int("CompoMe::Component_state::CONNECTED"): // namespace
    c = CompoMe::Component_state::CONNECTED;
    break;

  case str2int("8"):                        // value
  case str2int("STARTED"):                  // no namespace and typename space
  case str2int("Component_state::STARTED"): // no namespace space
  case str2int("CompoMe::Component_state::STARTED"): // namespace
    c = CompoMe::Component_state::STARTED;
    break;

  case str2int("16"):                        // value
  case str2int("DEGRADED"):                  // no namespace and typename space
  case str2int("Component_state::DEGRADED"): // no namespace space
  case str2int("CompoMe::Component_state::DEGRADED"): // namespace
    c = CompoMe::Component_state::DEGRADED;
    break;

  case str2int("32"):                    // value
  case str2int("DEAD"):                  // no namespace and typename space
  case str2int("Component_state::DEAD"): // no namespace space
  case str2int("CompoMe::Component_state::DEAD"): // namespace
    c = CompoMe::Component_state::DEAD;
    break;

  case str2int("64"):                        // value
  case str2int("STRESSED"):                  // no namespace and typename space
  case str2int("Component_state::STRESSED"): // no namespace space
  case str2int("CompoMe::Component_state::STRESSED"): // namespace
    c = CompoMe::Component_state::STRESSED;
    break;

  case str2int("128"):                      // value
  case str2int("UNKNOWN"):                  // no namespace and typename space
  case str2int("Component_state::UNKNOWN"): // no namespace space
  case str2int("CompoMe::Component_state::UNKNOWN"): // namespace
    c = CompoMe::Component_state::UNKNOWN;
    break;
  }
  return is;
}
} // namespace std
