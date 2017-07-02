#ifndef CALENG_FACTORY_FACTORY_H
#define CALENG_FACTORY_FACTORY_H

/** @brief Factory method code

    @author Junsheng Fu
    @date 2 July 2017
    */


#include "divider.h"
#include "multiplier.h"
#include "base.h"

template <typename T>
Base<T> *Base<T>::select_engine(std::string &engine_name) {

  // select either one of the two engines
  if (engine_name.compare("Multiplier") == 0) {
    return  new Multiplier<T>;
  }
  else if (engine_name.compare("Divider") == 0) {
    return new Divider<T>;
  }
  else{
    throw "Invalid Math Engine: use either \"Multipiler\" or \"Divider!";
  }
}

#endif //CALENG_FACTORY_FACTORY_H
