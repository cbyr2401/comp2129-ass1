#include <stdio.h>
#include <stdlib.h>

#define COVERED 42
#define FLAG 102
#define MINE 66

//char field[100*100];
//char *ptrField = field;

int printGrid(char const *p, int w, int h){
	printf("PRINTGRID: ptr: %p | x: %d | y: %d\n", p, w, h);
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			printf("%c", p[i * h+j]);
		}
		printf("\n");
	}
	fflush(stdout);
	return 0;
}

int initializeArr(char *p, int w, int h){
	
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			p[i * h+j] = 48;
		}
	}
	return 0;
}

int updateGridPlant(char *ptrGrid,int x,int y,int width,int height){
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
	x -= 1;
	y -= 1;
	// Left
	if(x-1>0 && y-1>0){
		//top
		if(ptrGrid[(x-1)*(height+(y-1))] != MINE){
			ptrGrid[(x-1)*(height+(y-1))] = 'c';
		}
	}
	if(x-1>0){
		// centre
		if(ptrGrid[(x-1)*(height+y)] != MINE){
			ptrGrid[(x-1)*(height+y)] += 3;
		}	
	}
	if(x-1>0 && y+1<height){
		//bottom
		if(ptrGrid[(x-1)*(height+(y+1))] != MINE){
			ptrGrid[(x-1)*(height+(y+1))] += 4;
		}	
	}
	// Centre
	if(y-1>0){
		//top
		if(ptrGrid[(x)*(height+(y-1))] != MINE){
			ptrGrid[(x)*(height+(y-1))] += 5;
		}
	}
	if(y+1<height){
		// bottom
		if(ptrGrid[(x)*(height+(y+1))] != MINE){
			ptrGrid[(x)*(height+(y+1))] += 6;
		}
	}
	// Right
	if(x+1<width && y-1>0){
		//top
		if(ptrGrid[(x+1)*(height+(y-1))] != MINE){
			ptrGrid[(x+1)*(height+(y-1))] += 7;
		}
	}
	if(x+1<width){
		// centre
		if(ptrGrid[(x+1)*(height+y)] != MINE){
			ptrGrid[(x+1)*(height+y)] += 8;
		}
	}
	if(x+1<width && y+1<height){
		//bottom
		if(ptrGrid[(x+1)*(height+(y+1))] != MINE){
			ptrGrid[(x+1)*(height+(y+1))] += 9;
		}
	}
	ptrGrid[x*height+y] = 'b';
	ptrGrid[x*height+1] = 'm';
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
	// declare array:
	char field[x * y];
	
	// initialize array:
	initializeArr(field,x,y);
	
	// DEBUG: print array:
	printGrid(field,x,y);
	
	// print command:
	printf("%c %d %d\n", cmd, x, y);

	// declare some constants for width and height:
	int const width = x;
	int const height = y;

	// second is 10 times 'b':
	int count = 0;
	
	while (count < 10){
		fflush(stdin);
		scanf("%c %d %d", &cmd, &x, &y);
		if(cmd=='b'){
			updateGridPlant(field,x,y,width,height);
			printf("%c %d %d\n", cmd, x, y);
			
			//printf("ptr: %p | width: %d | height: %d\n", ptrField, width, height);
			//printf("-------------------------------------\n");
			
			// DEBUG: print array:	
			printGrid(field,width,height);
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
