#!/bin/bash
echo "MINSWEEPER TESTING SCRIPT";
echo "If there is no output, all tests passed successfully.";
echo "running tests...";

echo -n "Testing first input..."
./minesweeper < ntests/grid-empty.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-newline.in | diff - ntests/error-line1.out

./minesweeper < ntests/initial-bomb.in | diff - ntests/error-line1.out
./minesweeper < ntests/initial-flag.in | diff - ntests/error-line1.out
./minesweeper < ntests/initial-uncover.in | diff - ntests/error-line1.out

./minesweeper < ntests/grid-one-char-correct.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-one-char-wrong-letter.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-one-char-wrong-number.in | diff - ntests/error-line1.out

./minesweeper < ntests/grid-two-char-wrong-letters.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-two-char-wrong-numbers.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-two-char-correct-letters.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-two-char-correct-letternumber.in | diff - ntests/error-line1.out

./minesweeper < ntests/grid-three-char-wrong-numbers.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-three-char-wrong-letters.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-three-char-wrong-ltrnumltr.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-three-char-wrong-ltrltrnum.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-three-char-wrong-numnumltr.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-three-char-wrong-numltrltr.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-three-char-wrong-numltrnum.in | diff - ntests/error-line1.out

./minesweeper < ntests/grid-too-many-char-correct.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-too-many-char-wrong.in | diff - ntests/error-line1.out

./minesweeper < ntests/grid-ascii-correct.in | diff - ntests/error-line1.out
./minesweeper < ntests/grid-ascii-wrong.in | diff - ntests/error-line1.out
echo "complete."
echo -n "Testing second input..."
# NOTE:  because the input is collected in the same way for each of the three,
#		  there is no point testing so brutally on the others.
./minesweeper < ntests/mine-empty.in | diff - ntests/error-line2.out
./minesweeper < ntests/mine-newline.in | diff - ntests/error-line2.out
./minesweeper < ntests/mine-one-char-correct.in | diff - ntests/error-line2.out

./minesweeper < ntests/mine-random-input-1.in | diff - ntests/error-line2.out
./minesweeper < ntests/mine-random-input-2.in | diff - ntests/error-line2.out
./minesweeper < ntests/mine-random-input-3.in | diff - ntests/error-line2.out
./minesweeper < ntests/mine-random-input-4.in | diff - ntests/error-line2.out
./minesweeper < ntests/mine-random-input-5.in | diff - ntests/error-line2.out
./minesweeper < ntests/mine-random-input-6.in | diff - ntests/error-line2.out

./minesweeper < ntests/not-enough-mines-1.in | diff - ntests/not-enough-mines-1.out
./minesweeper < ntests/not-enough-mines-2.in | diff - ntests/not-enough-mines-2.out
./minesweeper < ntests/not-enough-mines-3.in | diff - ntests/not-enough-mines-3.out
./minesweeper < ntests/not-enough-mines-8.in | diff - ntests/not-enough-mines-8.out
./minesweeper < ntests/not-enough-mines-9.in | diff - ntests/not-enough-mines-9.out
./minesweeper < ntests/too-many-mines.in | diff - ntests/too-many-mines.out

echo "complete."
echo -n "Testing third input..."
# NOTE:  because the input is collected in the same way for each of the three,
#		  there is no point testing so brutally on the others.

./minesweeper < ntests/scott-example-won.in | diff - ntests/scott-example-won.out
./minesweeper < ntests/field10x10-lose.in | diff - tests/field10x10-lose.out
./minesweeper < ntests/flag-all-lose.in | diff - tests/flag-all-lose.out

echo "complete."