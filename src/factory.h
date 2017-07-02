/*
 * factory.h
 *
 *  Created on: 2 July, 2017
 *  Author: Junsheng Fu
 */

#ifndef CALENG_FACTORY_FACTORY_H
#define CALENG_FACTORY_FACTORY_H

#include "divider.h"
#include "multiplier.h"
#include "base.h"

template <typename T>
Base<T> *Base<T>::select_engine(std::string &engine_name) {

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
