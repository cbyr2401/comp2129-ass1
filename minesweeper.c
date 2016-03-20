#include <stdio.h>
#include <stdlib.h>

#define COVERED 42
#define FLAG 102
#define MINE 66
#define SIZE 10

//char field[100*100];
//char *ptrField = field;

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

int updateGridPlant(char *ptrGrid,int x, int y, int rows, int cols){
	//  GRID
	//  TL  TC  TR
	//  L    *   R
	//  BL  BC  BR
	/*
		Safety checks in place:
			1.  Check edges (are we on an edge?)
			2.  Check value (is there a bomb there?)
			3.  
	*/
	//x -= 1;
	//y -= 1;
	// Left
	if(x-1>0 && y-1>0){
		//top
		if(ptrGrid[(x-1)*cols+(y-1)] != MINE){
			//ptrGrid[(x-1)*(cols+(y-1))] = 'c';
			ptrGrid[(x-1)*cols+(y-1)] += 1;
		}
	}
	if(y-1>0){
		// centre
		if(ptrGrid[(x)*cols+(y-1)] != MINE){
			ptrGrid[(x)*cols+(y-1)] += 1;
		}	
	}
	if(x+1<rows && y-1<cols){
		//bottom
		if(ptrGrid[(x+1)*cols+(y-1)] != MINE){
			ptrGrid[(x+1)*cols+(y-1)] += 1;
		}	
	}
	// Centre
	if(x-1>0){
		//top
		if(ptrGrid[(x-1)*cols+(y)] != MINE){
			ptrGrid[(x-1)*cols+(y)] += 1;
		}
	}
	if(x+1<rows){
		// bottom
		if(ptrGrid[(x+1)*cols+(y)] != MINE){
			ptrGrid[(x+1)*cols+(y)] += 1;
		}
	}
	// Right
	if(x-1>0 && y+1<cols){
		//top
		if(ptrGrid[(x-1)*cols+(y+1)] != MINE){
			ptrGrid[(x-1)*cols+(y+1)] += 1;
			printf("%d | %d\n", x, y);
		}
	}
	if(y+1<cols){
		// centre
		if(ptrGrid[(x)*cols+(y+1)] != MINE){
			ptrGrid[(x)*cols+(y+1)] += 1;
		}
	}
	if(x+1<rows && y+1<cols){
		//bottom
		if(ptrGrid[(x+1)*cols+(y+1)] != MINE){
			ptrGrid[(x+1)*cols+(y+1)] += 1;
		}
	}
	ptrGrid[x*cols+y] = MINE;
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
	
	// initialize array:
	initializeArr(field,x,y);
	
	// DEBUG: print array:
	printGrid(field,x,y);
	
	// print command:
	printf("%c %d %d\n", cmd, x, y);

	// declare some constants for width and height:
	int const numRows = y;
	int const numCols = x;

	// second is 10 times 'b':
	int count = 0;
	
	while (count < 10){
		fflush(stdin);
		scanf("%c %d %d", &cmd, &x, &y);
		if(cmd=='b'){
			// updated grid:
			updateGridPlant(field,x,y,numRows,numCols);
			
			// print command:
			printf("%c %d %d\n", cmd, x, y);
			
			// DEBUG: print array:	
			printGrid(field,numRows,numCols);
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
