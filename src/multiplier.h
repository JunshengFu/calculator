#ifndef CALENG_FACTORY_MULTIPLIER_H
#define CALENG_FACTORY_MULTIPLIER_H

/** @brief Multiplier class for multiplication

    @author Junsheng Fu
    @date 2 July 2017
    */

#include <iostream>
#include "base.h"

template <typename T>
class Multiplier: public Base<T>{

public:

  /**
   * Constructor
   */
  Multiplier();

  /**
   * Destructor
   */
  virtual ~Multiplier();

  /**
   * Compute the multiplication with given data
   * @param arr data to be multiplied
   * @return result of the multiplication
   */
  double compute(const vector<T>& arr);
};


#endif //CALENG_FACTORY_MULTIPLIER_H