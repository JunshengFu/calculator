/*
 * multiplier.h
 *
 *  Created on: 2 July, 2017
 *  Author: Junsheng Fu
 */

#ifndef CALENG_FACTORY_MULTIPLIER_H
#define CALENG_FACTORY_MULTIPLIER_H

#include <iostream>
#include "base.h"

template <typename T>
class Multiplier: public Base<T>{
public:
  double compute(const vector<T>& arr);
};


#endif //CALENG_FACTORY_MULTIPLIER_H
