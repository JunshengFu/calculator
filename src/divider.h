/** @brief Divider class for division

    @author Junsheng Fu
    @date 2 July 2017
    */

#ifndef CALENG_FACTORY_DIVIDER_H
#define CALENG_FACTORY_DIVIDER_H

#include <iostream>
#include "base.h"

template <typename T>
class Divider: public Base<T>{
public:

  /**
   * Constructor
   */
  Divider();

  /**
   * Destructor
   */
  virtual ~Divider();

  /**
   * Compute the division with given data
   * @param arr data to be divided
   * @return result of the division
   */
  double compute(const vector<T>& arr);
};


#endif //CALENG_FACTORY_DIVIDER_H