/*
 * divider.cpp
 *
 *  Created on: 2 July, 2017
 *  Author: Junsheng Fu
 */

#include <iostream>
#include <vector>
#include "divider.h"

using namespace std;

template <typename T>
Divider<T>::Divider() {};

template <typename T>
Divider<T>:: ~Divider(){};


template <typename T>
double Divider<T>::compute(const vector<T>& arr){
  if(arr.empty()){
    throw "This an empty input!";
  }

  double res = arr[0];
  for(int i=1; i< arr.size(); i++){
    if(arr[i] == 0){
      throw "There is at least one ZERO denominator!";
    }
    else{
      res /= double(arr[i]);
    }
  }
  return res;
}

template class Divider<int>;
template class Divider<float>;
template class Divider<double>;