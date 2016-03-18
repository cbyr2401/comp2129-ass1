#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
		int i = 4096;
		int * pointer = i;
		int * pointaddr = &i;
		
		printf("%d | %p | %p | %p", i, pointer, pointaddr, &i);
		printf("%d | %d | %d | %d", i, *pointer, *pointaddr, &i);
		return 0;	
}