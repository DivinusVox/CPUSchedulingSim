#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include "processtable.h"

#define LENGTH 300
#define MAX_LINES 100

ssize_t input;

void main()
{
    ProcessTable pTable;
	char streamInput[MAX_LINES];
	int values[LENGTH];
	int i = 0;
	// get stdinput
	while(fgets(streamInput, 256, stdin) != NULL)
	{
		// fill arrays
		char* splitVals1, splitVals2, splitVals3;
		splitVals1 = strtok(streamInput, " \t\n");
		while (splitVals1 != NULL)
		{
			//printf("%s\n", splitVals);
			splitVals2 = strtok(NULL, " \t\n");
			splitVals3 = strtok(NULL, " \t\n");
		//pTable.pid[i] = splitVals;
		}	
		
		printf("returning to stream\n");
		i++;
	}
	
	// do fcfs
	// do shortest job
	// do shortest remaining job
	// do round robin
}
