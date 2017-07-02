# Calculation Engines

## Objective
This is a program that performs calculations on a series of numbers with two math engine, 
"Multiplier" and "Divider".


## Code & Files
### 1. Dependencies & environment

* cmake >= 3.5
* make >= 4.1
* gcc/g++ >= 5.4
* [bats](https://github.com/sstephenson/bats) (a unit test framework for bash) >= 0.4.0
   

### 2. How to run the code

1. Clone this repo: `$git clone https://github.com/JunshengFu/calculator.git`
2. Clean the project: `$./clean.sh`
3. Build the project: `$./build.sh` 
4. Run unit test for **Divider** engine: `$./run_unitTest_divider.sh`
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
* [run_unitTest_divider.sh](run_unitTest_divider.sh) runs the unit test for Divider.
* [unit_test](unit_test) folder contains the [unit test framework bats](https://github.com/sstephenson/bats) and 
my unit test code [divider.bats](unit_test/divider.bats). 
* [CMakeLists.txt](CMakeLists.txt) is the cmake file.
* [data](data) folder contains list of files contains number and characters.
* [src](src) folder contains the source code.


### 4. Code Style

* [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).


### 5. Release History

* 0.1.1
    * Fixed a bug regarding multiplication overflow
    * Added bash files for _build_, _clean_ and the _unit test_.
    * Create the documentation
    * Date 2 July 2017

* 0.1.0
    * Initiate the repo with the first release 
    * Date 2 July 2017

### 6. License

* [MIT License](https://opensource.org/licenses/MIT)
