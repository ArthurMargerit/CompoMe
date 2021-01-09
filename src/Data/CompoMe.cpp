#include "Data/CompoMe.hpp"

#include "Components/CompoMe/Component_Core_fac.hpp"

void init_CompoMe() {

  static bool already_run = false;
  if (already_run) {
    return;
  }
  already_run = true;

  init_CompoMe_Log();

  CompoMe::Component_Core_fac::get_inst();
}