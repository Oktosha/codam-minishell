
#!bin/bash

# CUnit test
sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev

# Valgring (leaks check)
sudo apt-get install valgrind

# Python (norminette)
sudo apt-get install python3

# Norminette
python3 -m pip install --upgrade pip setuptools
python3 -m pip install norminette
