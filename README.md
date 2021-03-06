# Calculation Engines

## Objective
This is a program that performs calculations on a series of numbers with two math engine, 
"Multiplier" and "Divider". It is implemented with template and factory method in C++.


## Code & Files
### 1. Dependencies & environment

* cmake >= 3.5
* make >= 4.1
* gcc/g++ >= 5.4
* [bats](https://github.com/sstephenson/bats) (a unit test framework for bash) >= 0.4.0, 
and **it will be automatically downloaded** when user runs bash file `$ ./run_unittest_divider.sh`
   

### 2. How to run the code

1. Clone this repo: `$git clone https://github.com/JunshengFu/calculator.git`
2. Clean the project: `$./clean.sh`
3. Build the project: `$./build.sh` 
4. Run unit tests for **Divider** engine: `$ ./run_unittest_divider.sh`

```
 ✓ (Divider engine) Illegal Input test: input no enough arguments
 ✓ (Divider engine) Illegal Input test: input wrong math engine
 ✓ (Divider engine) Illegal Input test: input illegal *.txt file
 ✓ (Divider engine) Illegal Input test: input non-exist *.txt file
 ✓ (Divider engine) Integers inputs test: inputs 0 integer
 ✓ (Divider engine) Integers inputs test: inputs 1 integer
 ✓ (Divider engine) Integers inputs test: inputs 2 integers
 ✓ (Divider engine) Integers inputs test: contain non-intergers
 ✓ (Divider engine) Integers inputs test: ZERO denominator
 ✓ (Divider engine) List_files inputs test: input 0 list_file
 ✓ (Divider engine) List_files inputs test: input 1 list_file
 ✓ (Divider engine) List_files inputs test: input 2 list_files
 ✓ (Divider engine) List_files inputs test: contain non-integers
 ✓ (Divider engine) List_files inputs test: ZERO denominator

14 tests, 0 failures

```

5. Command line usages:
 
```
Usage 1: calc <engine_name> <file_list>
Usage 2: calc <engine_name> <list of integers>

Example 1: input numbers with commands
(a) Divider
$./build/calc Divider 10 2
$5

$./build/calc Divider 10 2 0
$There is at least one ZERO denominator!

(b) Multiplier
$./build/calc Multiplier 10 2
$20

$./build/calc Multiplier 3.0e300 1.0e100
$These integers are too big for multiplication!


Example 2: input *.txt files
(a) Divider
$./build/calc Divider input ./data/1.txt
$10

$./build/calc Divider input ./data/1.txt ./data/2.txt
$0.5

(b) Multiplier
$./build/calc Multiplier input ./data/1.txt
$1000

$./build/calc Multiplier input ./data/1.txt ./data/2.txt
$20000

```

### 3. My project files 

* [clean.sh](clean.sh) cleans the project.
* [build.sh](build.sh) builds the project.
* [run_unittest_divider.sh](run_unittest_divider.sh) runs the unit test for Divider.
* [unit_test](unit_test) folder contains the [unit test framework bats](https://github.com/sstephenson/bats)(it will 
be automatically downloaded when run the bash of unit_test) and my unit test code [divider.bats](unit_test/divider.bats). 
* [CMakeLists.txt](CMakeLists.txt) is the cmake file.
* [data](data) folder contains list of files contains number and characters.
* [src](src) folder contains the source code.


### 4. Design documentation and API documentation

* Automatically created documentation by [Doxygen](http://www.stack.nl/~dimitri/doxygen/) is
available here [documents/html/index.html](documents/html/index.html).

**Brief summary of the code design**:
* [`base.h`](src/base.h) is the base class for any calculation engine.
    
    ```
    template <typename T>
    class Base{
    public:
    
      /**
       * Default Constructor
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
    
    ```
    
* [`multiplier.h`](src/multiplier.h) and [`multiplier.cpp`](src/multiplier.cpp) are the derived class for multiplication.
    
    ```
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
    ```
    
    
* [`divider.h`](src/divider.h) and [`divider.cpp`](src/divider.cpp) are the derived class for division. 
    ```
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
   ```

* [`factory.h`](src/factory.h) is the code of factory method.

   ```
    template <typename T>
    Base<T> *Base<T>::select_engine(std::string &engine_name) {
    
      // select either one of the two engines
      if (engine_name.compare("Multiplier") == 0) {
        return  new Multiplier<T>;
      }
      else if (engine_name.compare("Divider") == 0) {
        return new Divider<T>;
      }
      else{
        throw "Invalid Math Engine: use either \"Multipiler\" or \"Divider!";
      }
    }
   ```
* [`helper_functions.h`](src/helper_functions.h) contains some help functions for arguments parsing.
* [`main.cpp`](src/main.cpp) is the main function.
 

### 5. Code Style

* [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).


### 6. Release History

* 0.1.1
    * Fixed a bug regarding multiplication overflow
    * Added bash files for _build_, _clean_ and the _unit test_.
    * Create the documentation
    * Date 2 July 2017

* 0.1.0
    * Initiate the repo with the first release 
    * Date 2 July 2017

### 7. License

* [MIT License](https://opensource.org/licenses/MIT)

