#!/bin/bash
# Script to do unit test for divider

# Clone the unit test framework bats to unit_test folder
echo Cloning the unit_test framework bats!
cd `dirname $0`
cd unit_test
git clone https://github.com/sstephenson/bats.git
chmod +x ./bats/bin/bats
cd ..

echo Finish the clone!


# run the unit test
echo Start the unit_test with the Divider Engine!
./unit_test/bats/bin/bats ./unit_test/divider.bats
