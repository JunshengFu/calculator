/** @brief Main function for Calculation Engines

    @author Junsheng Fu
    @date 2 July 2017
    */

#include <iostream>
#include <vector>
#include <string>
#include "helper_functions.h"
#include "factory.h"

using namespace std;

int main(int argc, char* argv[]) {

  // check the input arguments
  if (!checkValidArg(argc, argv)) {
    return 0;
  }

  // get inputs list_files or integers
  std::vector<double> arr;
  if (!getInputs(arr, argc, argv)) {
    return 0;
  }

  // execute the user selected math engine: Multiplier or Divider
  std::string engine_name;
  engine_name = argv[1];
  if (!arr.empty()) {
    try {
      Base<double> *f = Base<double>::select_engine(engine_name);
      double res = f->compute(arr);
      std::cout << res<<std::endl;
    }
    catch (const char *msg) {
      std::cerr << msg << std::endl;
    }
  }

  return 0;
}