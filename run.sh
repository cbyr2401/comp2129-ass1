#!/bin/bash
echo "MINSWEEPER TESTING SCRIPT";
echo "If there is no output, all tests passed successfully.";
echo "running tests...";

echo -n "Testing first input..."
./minesweeper < tests/grid-empty.in | diff - tests/error-line1.out
./minesweeper < tests/grid-newline.in | diff - tests/error-line1.out

./minesweeper < tests/initial-bomb.in | diff - tests/error-line1.out
./minesweeper < tests/initial-flag.in | diff - tests/error-line1.out
./minesweeper < tests/initial-uncover.in | diff - tests/error-line1.out

./minesweeper < tests/grid-one-char-correct.in | diff - tests/error-line1.out
./minesweeper < tests/grid-one-char-wrong-letter.in | diff - tests/error-line1.out
./minesweeper < tests/grid-one-char-wrong-number.in | diff - tests/error-line1.out

./minesweeper < tests/grid-two-char-wrong-letters.in | diff - tests/error-line1.out
./minesweeper < tests/grid-two-char-wrong-numbers.in | diff - tests/error-line1.out
./minesweeper < tests/grid-two-char-correct-letters.in | diff - tests/error-line1.out
./minesweeper < tests/grid-two-char-correct-letternumber.in | diff - tests/error-line1.out

./minesweeper < tests/grid-three-char-wrong-numbers.in | diff - tests/error-line1.out
./minesweeper < tests/grid-three-char-wrong-letters.in | diff - tests/error-line1.out
./minesweeper < tests/grid-three-char-wrong-ltrnumltr.in | diff - tests/error-line1.out
./minesweeper < tests/grid-three-char-wrong-ltrltrnum.in | diff - tests/error-line1.out
./minesweeper < tests/grid-three-char-wrong-numnumltr.in | diff - tests/error-line1.out
./minesweeper < tests/grid-three-char-wrong-numltrltr.in | diff - tests/error-line1.out
./minesweeper < tests/grid-three-char-wrong-numltrnum.in | diff - tests/error-line1.out

./minesweeper < tests/grid-too-many-char-correct.in | diff - tests/error-line1.out
./minesweeper < tests/grid-too-many-char-wrong.in | diff - tests/error-line1.out

./minesweeper < tests/grid-ascii-correct.in | diff - tests/error-line1.out
./minesweeper < tests/grid-ascii-wrong.in | diff - tests/error-line1.out
echo "complete."
echo -n "Testing second input..."
# NOTE:  because the input is collected in the same way for each of the three,
#		  there is no point testing so brutally on the others.
./minesweeper < tests/mine-empty.in | diff - tests/error-line2.out
./minesweeper < tests/mine-newline.in | diff - tests/error-line2.out
./minesweeper < tests/mine-one-char-correct.in | diff - tests/error-line2.out

./minesweeper < tests/mine-random-input-1.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-2.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-3.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-4.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-5.in | diff - tests/error-line2.out
./minesweeper < tests/mine-random-input-6.in | diff - tests/error-line2.out

./minesweeper < tests/not-enough-mines-1.in | diff - tests/not-enough-mines-1.out
./minesweeper < tests/not-enough-mines-2.in | diff - tests/not-enough-mines-2.out
./minesweeper < tests/not-enough-mines-3.in | diff - tests/not-enough-mines-3.out
./minesweeper < tests/not-enough-mines-8.in | diff - tests/not-enough-mines-8.out
./minesweeper < tests/not-enough-mines-9.in | diff - tests/not-enough-mines-9.out
./minesweeper < tests/too-many-mines.in | diff - tests/too-many-mines.out

echo "complete."
echo -n "Testing third input..."
# NOTE:  because the input is collected in the same way for each of the three,
#		  there is no point testing so brutally on the others.

./minesweeper < tests/scott-example-won.in | diff - tests/scott-example-won.out
./minesweeper < tests/field10x10-lose.in | diff - tests/field10x10-lose.out
./minesweeper < tests/flag-all-lose.in | diff - tests/flag-all-lose.out

echo "complete."