#! /bin/bash
echo "MINSWEEPER TESTING SCRIPT";
echo "If there is no output, all tests passed successfully.";
echo "running tests...";

echo "**INITIAL INPUT (not grid)...starting";
./minesweeper < tests/initial-bomb.in | diff - tests/error-line1.out
./minesweeper < tests/initial-flag.in | diff - tests/error-line1.out
./minesweeper < tests/initial-uncover.in | diff - tests/error-line1.out
echo "**INITIAL INPUT (not grid)...complete!";

echo "**INITIAL RANDOM INPUT...starting!";
./minesweeper < tests/initial-random-input-1.in | diff - tests/error-line1.out
./minesweeper < tests/initial-random-input-2.in | diff - tests/error-line1.out
./minesweeper < tests/initial-random-input-3.in | diff - tests/error-line1.out
./minesweeper < tests/initial-random-input-4.in | diff - tests/error-line1.out
./minesweeper < tests/initial-random-input-5.in | diff - tests/error-line1.out
./minesweeper < tests/initial-random-input-6.in | diff - tests/error-line1.out
echo "**INITIAL RANDOM INPUT...complete!";

echo "**MINE RANDOM INPUT...starting!";
./minesweeper < tests/mine-random-input-1.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-2.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-3.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-4.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-5.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-6.in | diff - tests/error-line2.out
echo "**MINE RANDOM INPUT...complete!";

echo "**MISSING PARAMETER TESTS...starting";
./minesweeper < tests/initial-missingparam-1.in | diff - tests/error-line1.out
./minesweeper < tests/initial-missingparam-2.in | diff - tests/error-line1.out
./minesweeper < tests/initial-missingparam-3.in | diff - tests/error-line1.out


echo "**MISSING PARAMETER TESTS...starting";

echo "**MINE PLANTING TESTS...starting";
./minesweeper < tests/not-enough-mines-1.in | diff - tests/not-enough-mines-1.out
./minesweeper < tests/not-enough-mines-2.in | diff - tests/not-enough-mines-2.out
./minesweeper < tests/not-enough-mines-3.in | diff - tests/not-enough-mines-3.out
./minesweeper < tests/not-enough-mines-8.in | diff - tests/not-enough-mines-8.out
./minesweeper < tests/not-enough-mines-9.in | diff - tests/not-enough-mines-9.out
./minesweeper < tests/too-many-mines.in | diff - tests/too-many-mines.out
echo "**MINE PLANTING TESTS...completed!";

echo "**WINNERS AND LOSERS TESTS...starting";
./minesweeper < tests/scott-example-won.in | diff - tests/scott-example-won.out
./minesweeper <  tests/field10x10-lose.in | diff - tests/field10x10-lose.out
./minesweeper < tests/flag-all-lose.in | diff - tests/flag-all-lose.out
echo "**WINNERS AND LOSERS TESTS...complete!";



echo "testing completed."
