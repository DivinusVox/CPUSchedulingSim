#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include "processtable.h"
#include "kacey.h"
#include "mike.h"

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
		char* splitVals1;
                char* splitVals2; 
		char* splitVals3;
		splitVals1 = strtok(streamInput, " \t\n");
		if (splitVals1 != NULL)
		{
			splitVals2 = strtok(NULL, " \t\n");
			splitVals3 = strtok(NULL, " \t\n");

			//printf("%s", splitVals2);
			
			pTable.pid[i] = atoi(splitVals1);
			pTable.arrival_time[i] = atoi(splitVals2);
			pTable.base_cycles[i] = atoi(splitVals3);
			pTable.remaining_cycles[i] = atoi(splitVals3);
			
			//printf("%d, %d, %d\n", a, b, c);
		}	
		
		
		//printf("returning to stream\n");
		i++;
	}
	pTable.size = i;
	pTable.time = 0;
	
	int j;
	for (j=0; j<i; j++)
		printf("PID: %d\n", pTable.pid[j]);
	
	// do fcfs
	FirstCome(pTable);
	// do shortest job
	ShortestJob(pTable);
	// do shortest remaining job
	ShortestRemaining(pTable);
	// do round robin
	RoundRobin(pTable);
}
