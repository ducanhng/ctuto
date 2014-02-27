#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100
#define EXIT 1
void movedisk(int, int, int, int);
int movecount;
int main(){	
	int c, index, numtowers;
	char input[MAXLINE];
	while (1 != 0){
		printf("input the number of towers:");
		index = 0;
		movecount = 0;
		while ((c = getchar()) != EOF && c != '\n'){
			input[index++] = c;		
		}
		input[index] = '\0';//end of line
		// process tring
		numtowers = atoi(input);		
		printf("number of towers: %d\n",numtowers);
		movedisk(numtowers, 1, 2, 3);
		printf("number of movings: %d\n", movecount);
		if (c == EOF)
			break;
	}
}

// n is number of disks:
// a,b,c are pegs number. ex:1,2,3
void movedisk(int n, int a, int b, int c){
	if (n > 0){
		movedisk(n-1, a, c, b);
		//printf("move disk[%d] from peg %d to peg %d\n",n, a, c);	
		movecount++;
		movedisk(n-1, b, a, c);
	}
}

