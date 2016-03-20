#include <stdio.h>
#include <stdlib.h>

#define COVERED 42
#define MINE 66
#define FLAG 102

#define ZERO 48

#define CORNER 43
#define HEDGE 45
#define VEDGE 124

// declare some constants for width and height:
int maxRows;
int maxCols;

// function declarations:
void initializeArr(char *p, char initial);
void plantMine(char *p, int row, int col);
void display(char const *p);
void printGridDebug(char const *p);
void CleanExitError(void);


int checkGrid(){
	return 0;
}

int main(int argc, char **argv){
	int x,y;
	char cmd;
	
	// first command MUST be 'g':
	fflush(stdin);
	if (scanf("%c %d %d", &cmd, &x, &y) == 1 
		|| cmd != 'g' 
		|| (x < 0 && x > 100) 
		|| (y < 0 && y > 100)
		|| (x * y < 10)
		)
	{
		// catch error conditions...
		CleanExitError();
	}
	// declare GLOBAL constants for 
	//  maximum number of Rows and Columns:
	maxRows = y;
	maxCols = x;
	
	// declare array (x:cols:width, y:rows:height):
	char field[maxRows * maxCols];
	char sweeper[maxRows * maxCols];

	// initialize array:
	initializeArr(field,ZERO);
	initializeArr(sweeper,COVERED);
	
	// DEBUG: print array:
	//printGridDebug(field);
	//display(sweeper);
	
	// print command:
	printf("%c %d %d\n", cmd, x, y);

	// second is 10 times 'b':
	int count = 0;
	
	while (count < 10){
		fflush(stdin);
		scanf("%c %d %d", &cmd, &x, &y);
		if(cmd=='b' && x>-1 && y>-1 && x<maxCols && y<maxRows){
			// updated grid (row major)
			plantMine(field,y,x);
			
			// print command:
			printf("%c %d %d\n", cmd, x, y);
			
			// increment count:
			count++;
		}else{
			CleanExitError();
		}
	}

	// after 10 successful 'b', print grid:
	display(sweeper);

	// GAME ON!!  Keep going until an exit condition is met.
	while(1){
		scanf("%c %d %d", &cmd, &x, &y);

		if(cmd=='u'){
			//updateGrid();
			checkGrid();
			printf("%c %d %d\n", cmd, x, y);
			//printGrid(pfield);
		}
		else if(cmd=='f'){
			//updateGrid();
			checkGrid();
			printf("%c %d %d\n", cmd, x, y);
			//printGrid(pfield);
		}
		else{
			printf("error");
		}
	}

	return 0;
}

// function used to check that mines are in correct location.
void printGridDebug(char const *p){
	for(int i=0; i<maxRows; i++){
		for(int j=0; j<maxCols; j++){
			printf("%c", p[i * maxCols+j]);
		}
		printf("\n");
	}
	fflush(stdout);
}

// function used to fill array with '0'
void initializeArr(char *p, char initial){
	for(int i=0; i<maxRows; i++){
		for(int j=0; j<maxCols; j++){
			p[i * maxCols+j] = initial;
		}
	}
}

// function to plant a mine with a few safety checks.
void plantMine(char *ptrGrid,int row, int col){
	/*
		Safety checks in place:
			1.  Check if mine already place
			2.  Check edges (are we on an edge?)
			3.  Check value (is there a bomb there?)
	*/
	
	if(ptrGrid[row*maxCols+col] == MINE){
		//CleanExitError();
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
	ptrGrid[row*maxCols+col] = MINE;
}

// function to display the minesweeper game board.
void display(char const *p){
	
	// top row:
	putchar(CORNER);
	for(int c = 0; c < maxCols; c++){
		putchar(HEDGE);
	}
	putchar(CORNER);
	printf("\n");
	
	// other rows:
	for(int i=0; i<maxRows; i++){
		printf("%c", VEDGE);
		for(int j=0; j<maxCols; j++){
			printf("%c", p[i * maxCols+j]);
		}
		printf("%c\n", VEDGE);
	}
	
	//bottom row:
	putchar(CORNER);
	for(int c = 0; c < maxCols; c++){
		putchar(HEDGE);
	}
	putchar(CORNER);
	printf("\n");
	
	// flush output:
	fflush(stdout);
}

// function to exit program.
void CleanExitError(void){
	printf("error");
	exit(0);
}
