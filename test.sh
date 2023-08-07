#!usr/bin/bash

RED="\e[31m"
GREEN="\e[32m"
RESET="\e[0m"
BLUE="\e[94m"

make

echo -e ${BLUE} "   => Test 1 (1 2 +) <=      "${RESET} 
echo 1 2 + | ./calculator
echo
OUTPUT=$(find -name "Result is:" | wc -l)
echo ${OUTPUT}

echo -e ${BLUE} "   => Test 2 (3 4 * 2 5 * +) <=      "${RESET} 
echo "3 4 * 2 5 * +" | ./calculator
echo

echo -e ${BLUE} "   => Test 3 (100 200 + 2 / 5 * 7 +) <=      "${RESET} 
echo "100 200 + 2 / 5 * 7 +" | ./calculator
echo

echo -e ${BLUE} "   => Test 4 (5 2 + 3 1 - *) <=      "${RESET} 
echo "5 2 + 3 1 - *" | ./calculator
echo

make fclean

