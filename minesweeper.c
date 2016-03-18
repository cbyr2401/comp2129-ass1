#include <stdio.h>

int main(int args, char * argv[]){
	int x,y;
	char cmd;


	// first command MUST be 'g':
	scanf("%c %d %d", &cmd, &x, &y);

	if(cmd=='g'){
		printf("%c %d %d\n", cmd, x, y);
	}else{
		CleanExitError();
	}

	// second is 10 times 'b':
	int count = 0;
	while (count < 10){
		scanf("%c %d %d", &cmd, &x, &y);
		if(cmd=='b'){
			printf("%c %d %d\n", cmd, x, y);
			count++;
		}else{
			CleanExitError();
		}
	}

	// after 10 successful 'b', print grid:
	printGrid();

	// GAME ON!!  Keep going until an exit condition is met.
	while(1){
		scanf("%c %d %d", &cmd, &x, &y);

		if(cmd=='u'){
			updateGrid();
			checkGrid();
			printf("%c %d %d\n", cmd, x, y);
			printGrid();
		}
		else if(cmd=='f'){
			updateGrid();
			checkGrid();
			printf("%c %d %d\n", cmd, x, y);
			printGrid();
		}
		else{
			printf("error");
		}
	}

	return 0;
}

int printGrid(void){
	printf("grid");
	return 0;
}

int updateGrid(void){
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


