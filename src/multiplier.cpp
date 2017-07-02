/*
 * multiplier.cpp
 *
 *  Created on: 2 July, 2017
 *  Author: Junsheng Fu
 */

#include "multiplier.h"
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

template <typename T>
double Multiplier<T>::compute(const vector<T>& arr){
  if(arr.empty()){
    throw "This an empty list!";
  }

  // compute the max number of digits that double can represent, and save it as threshold
  double MAX_DOUBLE = std::numeric_limits<double>::max();
  double threshold = std::floor(log10(MAX_DOUBLE)) ;

  double product = 1.0;

  for(const auto& tmp: arr){

    double d1 = log10(product); // current number of digits for product
    double tmp_d = double(tmp);
    double d2 = log10(tmp_d);   // number of digits for the value to be multiplied

    // check possibility of overflow for further multiply
    if(d1 + d2 > threshold){
      throw "These integers are too big for multiplication!";
    }
    else{
      product *= tmp_d;
    }
  }
  return product;
}


template class Multiplier<int>;
template class Multiplier<float>;
template class Multiplier<double>;