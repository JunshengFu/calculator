/*
 * base.h
 *
 *  Created on: 2 July, 2017
 *  Author: Junsheng Fu
 */

#ifndef CALENG_FACTORY_CALCULATOR_H
#define CALENG_FACTORY_CALCULATOR_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Base{
public:
  static Base *select_engine(std::string& engine_name);
  virtual double compute(const vector<T>& arr) = 0;

};

#endif //CALENG_FACTORY_CALCULATOR_H
