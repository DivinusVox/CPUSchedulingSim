#include "processtable.h"
#include "scheduling.h"


// Project Entry Point
// main
// no parameters taken
// expects input via STDIN (redirect or direct entry)
//  input shall conform to 3 integers per line, spaced with whitespace
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
