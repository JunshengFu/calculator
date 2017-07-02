/*
 * multiplier.cpp
 *
 *  Created on: 2 July, 2017
 *  Author: Junsheng Fu
 */

#include "multiplier.h"
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
double Multiplier<T>::compute(const vector<T>& arr){
  if(arr.empty()){
    throw "This an empty list!";
  }

  int THRESHOLD = 100;
  double product = 1.0;
  double d1 = log10(product); // number of digits

  for(const auto& tmp: arr){
    double tmp_d = double(tmp);
    double d2 = log10(tmp_d);

    // check possibility of overflow for further multiply
    if(d1 + d2 > THRESHOLD){
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
