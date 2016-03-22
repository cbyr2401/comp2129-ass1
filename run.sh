#! /bin/bash
echo "MINSWEEPER TESTING SCRIPT";
echo "If there is no output, all tests passed successfully.";
echo "running tests...";

./minesweeper < tests/not-enough-mines-1.in | diff - tests/not-enough-mines-1.out
./minesweeper < tests/not-enough-mines-2.in | diff - tests/not-enough-mines-2.out
./minesweeper < tests/not-enough-mines-3.in | diff - tests/not-enough-mines-3.out
./minesweeper < tests/not-enough-mines-8.in | diff - tests/not-enough-mines-8.out
./minesweeper < tests/not-enough-mines-9.in | diff - tests/not-enough-mines-9.out
./minesweeper < tests/scott-example-won.in | diff - tests/scott-example-won.out
./minesweeper <  tests/field10x10-lose.in | diff - tests/field10x10-lose.out
./minesweeper < tests/flag-all-lose.in | diff - tests/flag-all-lose.out


echo "testing completed."
