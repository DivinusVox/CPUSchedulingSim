#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include "processtable.h"
#include "kacey.h"
#include "mike.h"

void main()
{
	ProcessTable pTable;
	initializeTable(&pTable);
	
	//int j;
	//for (j=0; j<pTable.size; j++)
	//	printf("PID: %d\n", pTable.pid[j]);
	
	// do fcfs
	FirstCome(pTable);
	// do shortest job
	ShortestJob(pTable);
	// do shortest remaining job
	ShortestRemaining(pTable);
	// do round robin
	RoundRobin(pTable, 0);
	RoundRobin(pTable, 0.4);
}
