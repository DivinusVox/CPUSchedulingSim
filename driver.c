#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define LENGTH = 100

ssize_t input;

void main()
{
	int[3*LENGTH] values;
	int i = 0;
	// get stdinput
	while((input = read(STDIN_FILENO, buf, sizeof buf)) > 0)
	{
		// fill arrays
		char* splitVals;
		splitVals = strtok(input, " \t");
		while(splitVals != NULL)
		{
			printf("%s\n", splitVals);
			splitVals = strtok(input, " \t");			
		}
		i++;
	}
	
	// do fcfs
	// do shortest job
	// do shortest remaining job
	// do round robin
}

int[] getInput( FILE* inputFile)
