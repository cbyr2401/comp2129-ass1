#include <stdio.h>
#include <stdlib.h>


int printGrid(int *p, int x, int y){
	printf("grid");
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			printf("%c", (p+i)[j]);
		}
		printf("\n");
	}
	return 0;
}

// int updateGridPlant(int *ptrGrid){
	// // NOTE: swapped x and y
	// for(int i=0; i < x; i++){
		// for(int j=0; j < y; j++){
			// if(j != x-1){
				// // right
				// ptrGrid[i][j+1] += 1;
			// }
			// if(j != 0){
				// // left
				// ptrGrid[i][j-1] += 1;
			// }
			// if(i != y-1){
				// // bottom
				// ptrGrid[i+1][j] += 1;
			// }
			// if(i != 0){
				// // top
				// ptrGrid[i-1][j] += 1;
			// }
			// if(j != 0 && i != 0){
				// // top left
				// ptrGrid[i-1][j-1] += 1;
			// }
			// if(i != 0 && j != x-1){
				// // top right
				// ptrGrid[i-1][j+1] += 1;
			// }
			// if(i != y-1 && j != 0){
				// // bottom left
				// ptrGrid[i+1][j-1] += 1;
			// }
			// if(i != y-1 && j != x-1){
				// //bottom right
				// ptrGrid[i+1][j+1] += 1;
			// }
		// }				
	// }
	// return 0;
// }

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
	int *pfield;
	
	// first command MUST be 'g':
	fflush(stdin);
	if (scanf("%c %d %d", &cmd, &x, &y) != 1 
		&& cmd=='g' 
		&& (x > 0 && x < 101) 
		&& (y > 0 && y < 101)
		&& (x * y > 9)
		)
	{
		char field[x][y];
		printf("DEBUG: %p", (int *)field);
		pfield = (int *)field;
		
		for(int i=0; i<x; i++){
			for(int j=0; j<y; j++){
				field[i][j] = 48;
			}
		}
		printGrid(field,x,y);
		printf("%c %d %d\n", cmd, x, y);
	}
	else{
		CleanExitError();
	}

	// second is 10 times 'b':
	int count = 0;
	
	while (count < 10){
		fflush(stdin);
		scanf("%c %d %d", &cmd, &x, &y);
		if(cmd=='b'){
			printf("%c %d %d\n", cmd, x, y);
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
