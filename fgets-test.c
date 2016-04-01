#include <stdio.h>

int main(void){
	char buffer[12];
	char *str;
	int nargs,x,y;
	char cmd;
	str = fgets(buffer, 10, stdin);
	nargs = sscanf(str, " %c %u %u", &cmd, &x, &y);
		
	printf("%d\n", nargs);
	printf("%c %u %u\n", cmd, x, y);
	fflush(stdin);
	return 0;
}
