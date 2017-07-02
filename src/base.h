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

  /**
   * Constructor
   */
  Base(){};

  /**
   * Destructor
   */
  virtual ~Base(){};

  /**
   * Select one math engine by giving the engine name
   * @param engine_name name of a math engine
   * @return a point to a selected engine
   */
  static Base *select_engine(std::string& engine_name);

  /**
   * Compute the input data
   * @param arr data given by the users
   * @return result of computation
   */
  virtual double compute(const vector<T>& arr) = 0;

};

#endif //CALENG_FACTORY_CALCULATOR_H
