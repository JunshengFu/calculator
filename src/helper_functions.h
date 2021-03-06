/*
 * helper_functions.h
 *
 *  Created on: 2 July, 2017
 *  Author: Junsheng Fu
 */

#ifndef CALENG_FACTORY_HELPER_FUNCTIONS_H
#define CALENG_FACTORY_HELPER_FUNCTIONS_H

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

/**
 * Print the usage of the program
 */
void printUsage(){
  std::cout<< "--------------------------------------------------"<<std::endl
           << "Usage 1: calc <engine_name> <file_list>"<<std::endl
           << "Usage 2: calc <engine_name> <list of integers>" << std::endl;
}

/**
 * Check the input argument values are valid or not
 * @param argc number of arguments
 * @param argv list of arguments
 * @return true or false based on the validation
 */
bool checkValidArg(int argc, char* argv[]){
  if (argc < 3){
    std::cout << "No enough argument values: please follow these two usages."<<std::endl;
    printUsage();
    return false;
  }
  else{ // "naive" is the engine_name that has been implemented
    std::string engine_name = argv[1];
    if (engine_name != "Multiplier" and engine_name != "Divider" ){
      std::cout << "Invalid Math Engine: use either \"Multipiler\" or \"Divider\"."<<std::endl;
      return false;
    }
  }
  return true;
}

/**
 * Check the string's ending
 * @param source the string to be checked
 * @param ending the pattern ending string
 * @return true or false based on the result
 */
bool ending_check(std::string const & source, std::string const & ending)
{
  if (ending.size() > source.size()) return false;
  return std::equal(ending.rbegin(), ending.rend(), source.rbegin());
}

/**
 * Read the files contain numbers, and save them into arr.
 * Stop reading the numbers into arr as soon as meet a "illegal number" (e.g #)
 * @param file_list file lists that contains numbers
 * @param arr save all the numbers from the file lists
 * @return true or false based on the status
 */
bool readTxtFiles(std::vector <std::string>& file_list, std::vector <double>& arr){
  if (file_list.empty()){
    std::cout<<"Inputs Error: no input files are given!"<<std::endl;
    return false;
  }

  // read data into arr
  for(int i=0; i<file_list.size(); i++){
    std::fstream myfile(file_list[i].c_str(), std::ios_base::in);

    if(!myfile){
      std::cout<<"Input Error: Nonexistent *.txt file."<<std::endl;
      return false;
    }

    double a;

    while (myfile >> a)
    {
      arr.push_back(a);
    }
  }

  return true;

}

/**
 * Parse the list file or individual numbers given by the user through commands
 * @param arr a double vector which is used for saving the numbers
 * @param argc number of arguments
 * @param argv list of arguments
 * @return true or false based on the status
 */
bool getInputs(std::vector <double>& arr, int argc, char* argv[]){

  // read file_list or list of integers
  std::string arg;
  double n;
  std::string::size_type sz;   // alias of size_t
  std::string ending = ".txt";
  std::vector<std::string> file_list;

  arg = argv[2];
  if (arg == "input"){
    // read all .txt files to a vector, named file_list
    for (int i=3; i < argc; i++){
      arg = argv[i];
      if (ending_check(arg, ending)){// if the ending is ".txt"
        file_list.push_back(arg);
      }
      else{
        std::cout<<"Inputs Error: illegal input files! Please give *.txt file."<<std::endl;
        return false;
      }
    }

    // read integers in every files into arr
    if (!readTxtFiles(file_list, arr)){
      return false;
    } else{
      return true;
    }
  }
  else{ // check case of only integers
    for(int i=2; i< argc; i++){
      arg = argv[i];
      try {
        n = std::stod(arg, &sz);
      }
      catch (std::exception& e){
        //std::cout <<e.what()<<std::endl;
        std::cout <<"Inputs Error: illegal integers inputs!" << std::endl;
        return false;
      }
      arr.push_back(n);
    }
    return true;
  }
}

#endif //CALENG_FACTORY_HELPER_FUNCTIONS_H