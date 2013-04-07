#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define LENGTH 300
#define MAX_LINES 100

ssize_t input;

void main()
{
	char streamInput[MAX_LINES];
	int values[LENGTH];
	int i = 0;
	// get stdinput
	while(fgets(streamInput, 256, stdin) != NULL)
	{
		// fill arrays
		char* splitVals;
		splitVals = strtok(streamInput, " \t");
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

//int[] getInput( FILE* inputFile)
