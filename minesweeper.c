#include <stdio.h>
#include <stdlib.h>

#define COVERED 42
#define FLAG 102
#define MINE 66
#define SIZE 10

//char field[100*100];
//char *ptrField = field;
// declare some constants for width and height:
int maxRows;
int maxCols;

// function declarations:


int printGrid(char const *p, int rows, int cols){
	printf("PRINTGRID: ptr: %p | x: %d | y: %d\n", p, rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			printf("%c", p[i * cols+j]);
		}
		printf("\n");
	}
	fflush(stdout);
	return 0;
}

int initializeArr(char *p, int rows, int cols){
	
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			p[i * cols+j] = 48;
		}
	}
	return 0;
}

int updateGridPlant(char *ptrGrid,int row, int col, int maxRows, int maxCols){
	//  GRID
	//  TL  TC  TR
	//  L    *   R
	//  BL  BC  BR
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
	return 0;
}

int CleanExitError(void){
	printf("error");
	exit(0);
	return 0;
}

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
	// declare array (x:cols:width, y:rows:height):
	char field[y * x];
	
	// declare some constants for width and height:
	maxRows = y;
	maxCols = x;
	
	// initialize array:
	initializeArr(field,maxRows,maxCols);
	
	// DEBUG: print array:
	printGrid(field,maxRows,maxCols);
	
	// print command:
	printf("%c %d %d\n", cmd, x, y);

	// second is 10 times 'b':
	int count = 0;
	
	while (count < 10){
		fflush(stdin);
		scanf("%c %d %d", &cmd, &x, &y);
		if(cmd=='b' && x>-1 && y>-1 && x<maxCols && y<maxRows){
			// updated grid (row major)
			updateGridPlant(field,y,x,maxRows,maxCols);
			
			// print command:
			printf("%c %d %d\n", cmd, x, y);
			
			// DEBUG: print array:	
			printGrid(field,maxRows,maxCols);
			count++;
		}else{
			CleanExitError();
		}
	}

	// after 10 successful 'b', print grid:
	//printGrid();

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
