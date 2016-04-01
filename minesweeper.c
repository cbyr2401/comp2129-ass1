/**
 * 	COMP2129 Assignment 1
 * 	Cian Byrne
 *	cbyr2401
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COVERED 42
#define MINE 66
#define FLAG 102

#define CORNER 43
#define HEDGE 45
#define VEDGE 124
#define NEWLINE 10

#define ZERO 48

// declare sosme constants for width and height:
int maxRows;
int maxCols;

// function declarations:
void initializeArr(char *p, char initial);
void plantMine(char *p, int row, int col);
void display(char const *p);
int check(char const *f, char const *s);
void CleanExitError(void);
void CleanExitLost(void);
void printGridDebug(char const *p);

int main(int argc, char **argv){
	int x,y,nargs;
	char cmd, buffer[14];
	char *input;
	char extra[5];
	
	// get input from user and check it is valid
	input = fgets(buffer, 12, stdin);
	// check for null
	if(input=='\0') CleanExitError();
	// parse
	nargs = sscanf(input, " %c %u %u %s", &cmd, &x, &y, extra);
	// error checking
	if(strlen(input)>10 || strlen(input)<2 || nargs != 3) CleanExitError();

	// first command MUST be 'g':
	if (nargs != 3
		|| cmd != 'g' 
		|| (x < 0 && x > 100) 
		|| (y < 0 && y > 100)
		|| (x * y < 10)
		)
	{
		// catch error conditions...
		CleanExitError();
	}
	// set GLOBAL constants for maximum Rows and Columns:
	maxRows = y;
	maxCols = x;
	
	// declare array (x:cols:width, y:rows:height):
	char field[maxRows * maxCols];
	char sweeper[maxRows * maxCols];

	// initialize arrays:
	initializeArr(field,ZERO);
	initializeArr(sweeper,COVERED);
	
	// print command:
	printf("%c %d %d\n", cmd, x, y);

	// second is 10 times 'b':
	for(int count=0; count < 10; count++){
		// get input from user and check it is valid
		input = fgets(buffer, 12, stdin);
		// check for null
		if(input=='\0') CleanExitError();
		// parse
		nargs = sscanf(input, " %c %u %u %s", &cmd, &x, &y, extra);
		// error checking
		if(strlen(input)>10 || strlen(input)<2 || nargs != 3) CleanExitError();
		
		if(cmd=='b' && x>-1 && y>-1 && x<maxCols && y<maxRows){
			// updated grid (row major)
			plantMine(field,y,x);
			
			// print command:
			printf("%c %d %d\n", cmd, x, y);
		}
		else{
			CleanExitError();
		}
	}

	// after 10 successful 'b', print grid:
	display(sweeper);

	// GAME ON!!  Keep going until an exit condition is met.
	int flag_count = 0;
	
	for(int count=0; count < maxRows * maxCols; count++){
		// get input from user and check it is valid
		input = fgets(buffer, 12, stdin);
		// check for null
		if(input=='\0') CleanExitError();
		// parse
		nargs = sscanf(input, " %c %u %u %s", &cmd, &x, &y, extra);
		// error checking
		if(strlen(input)>10 || strlen(input)<2 || nargs != 3) CleanExitError();
		
		if(cmd=='u'){
			if(field[y*maxCols+x] != MINE && sweeper[y*maxCols+x] == COVERED){
				// move value to game surface.
				sweeper[y*maxCols+x] = field[y*maxCols+x];				
				// output:
				printf("%c %d %d\n", cmd, x, y);
				display(sweeper);
			}
			else if(field[y*maxCols+x] == MINE){
				// player uncovered a mine and has lost.
				printf("%c %d %d\n", cmd, x, y);
				CleanExitLost();
			}
			else{
				// incorrect move, exit immediately.
				CleanExitError();
			}
		}
		else if(cmd=='f'){
			if(sweeper[y*maxCols+x] == MINE|| sweeper[y*maxCols+x] == COVERED){
				// flag square
				sweeper[y*maxCols+x] = FLAG;
				
				// increment flags:
				flag_count++;
				
				if(flag_count>10){
					// too many flags placed, exit.
					CleanExitError();
				}
				
				// output:
				printf("%c %d %d\n", cmd, x, y);
				display(sweeper);
			}
			else{
				// incorrect move, exit immediately.
				CleanExitError();
			}
		}
		else{
			// incorrect move, exit immediately.
			CleanExitError();
		}		
	}
	// check win conditions:
	if(check(field,sweeper)==0){
		printf("won\n");
		exit(0);
	}
	else{
		CleanExitLost();
	}

	return 0;
}

/*
	DEBUG ONLY: prints out grid with all squares uncovered.
	Used to check that mines are in correct location.
*/
void printGridDebug(char const *p){
	for(int i=0; i<maxRows; i++){
		for(int j=0; j<maxCols; j++){
			printf("%c", p[i * maxCols+j]);
		}
		printf("\n");
	}
	fflush(stdout);
}


/*
	Initialize 2D matrix array (given as pointer) with given initial value.
*/
void initializeArr(char *p, char initial){
	for(int i=0; i<maxRows; i++){
		for(int j=0; j<maxCols; j++){
			p[i * maxCols+j] = initial;
		}
	}
}

/*
	Plants a mine and increments squares around mine location.
	Method for each sqaure:
		1) Check if mine already place
		2) Check edges (are we on an edge?)
		3) Check value (is there a bomb there?)
*/
void plantMine(char *ptrGrid,int row, int col){
	// check if there is already a mine in that square
	if(ptrGrid[row*maxCols+col] == MINE){
		CleanExitError();
	}
	
	// Left
	if(col>0 && row>0){
		//top
		if(ptrGrid[(row-1)*maxCols+(col-1)] != MINE){
			ptrGrid[(row-1)*maxCols+(col-1)] += 1;
		}
	}
	if(col>0){
		// centre
		if(ptrGrid[(row)*maxCols+(col-1)] != MINE){
			ptrGrid[(row)*maxCols+(col-1)] += 1;
		}	
	}
	if(col>0 && row<maxRows-1){
		//bottom
		if(ptrGrid[(row+1)*maxCols+(col-1)] != MINE){
			ptrGrid[(row+1)*maxCols+(col-1)] += 1;
		}	
	}
	// Centre
	if(row>0){
		//top
		if(ptrGrid[(row-1)*maxCols+(col)] != MINE){
			ptrGrid[(row-1)*maxCols+(col)] += 1;
		}
	}
	if(row<maxRows-1){
		// bottom
		if(ptrGrid[(row+1)*maxCols+(col)] != MINE){
			ptrGrid[(row+1)*maxCols+(col)] += 1;
		}
	}
	// Right
	if(row>0 && col<maxCols-1){
		//top
		if(ptrGrid[(row-1)*maxCols+(col+1)] != MINE){
			ptrGrid[(row-1)*maxCols+(col+1)] += 1;
		}
	}
	if(col<maxCols-1){
		// centre
		if(ptrGrid[(row)*maxCols+(col+1)] != MINE){
			ptrGrid[(row)*maxCols+(col+1)] += 1;
		}
	}
	if(row<maxRows-1 && col<maxCols-1){
		//bottom
		if(ptrGrid[(row+1)*maxCols+(col+1)] != MINE){
			ptrGrid[(row+1)*maxCols+(col+1)] += 1;
		}
	}
	// plant the mine...
	ptrGrid[row*maxCols+col] = MINE;
}

/*
	Displays the grid corresponding the the specification:
		+----+
		|****|
		|****|
		|****|
		|****|
		+----+
	Where:
		CORNER  = '+'
		VEDGE   = '|'
		HEDGE   = '-'
		NEWLINE = '\n'
*/
void display(char const *p){
	// top row:
	putchar(CORNER);
	for(int c = 0; c < maxCols; c++){
		putchar(HEDGE);
	}
	putchar(CORNER);
	putchar(NEWLINE);
	
	// middle rows:
	for(int i=0; i<maxRows; i++){
		putchar(VEDGE);
		for(int j=0; j<maxCols; j++){
			putchar(p[i * maxCols+j]);
		}
		putchar(VEDGE);
		putchar(NEWLINE);
	}
	
	//bottom row:
	putchar(CORNER);
	for(int c = 0; c < maxCols; c++){
		putchar(HEDGE);
	}
	putchar(CORNER);
	putchar(NEWLINE);
	
	// flush output:
	fflush(stdout);
}


/* 
	Check to see if player has won the game:
	Win conditions:
		1) All squares visited
		2) Flags in correct positions
		3) All squares have been uncovered
*/
int check(char const *f, char const *s){
	for(int i=0; i<maxRows; i++){
		for(int j=0; j<maxCols; j++){
			if(f[i * maxCols+j] == MINE && s[i * maxCols+j] == FLAG){
				// correct - mine has been flagged
			}
			else if(f[i * maxCols+j] == s[i * maxCols+j]){
				// correct - cell has been uncovered
			}
			else{
				// incorrect - cell does not correspond to master
				return -1;
			}
		}
	}
	return 0;
}

/*
	Prints "error" and exits immediately
*/
void CleanExitError(void){
	printf("error\n");
	exit(0);
}

/*
	Prints "lost" and exits immediately
*/
void CleanExitLost(void){
	printf("lost\n");
	exit(0);
}
