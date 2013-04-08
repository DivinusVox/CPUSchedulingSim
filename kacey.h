//#include <stdio.h>
//#include "processtable.h"

// First Come First Serve
// takes array of ints
// 	consumed in threes

void FirstCome(ProcessTable input)
{
	printf("%d\n", input.pid[0]);
	input.pid[0]=999;
	printf("%d\n", input.pid[0]);
}


// Shortest Remaining Time
// takes array of ints,
// 	consumed in threes
void ShortestRemaining(ProcessTable input)
{
	printf("%d\n", input.pid[0]);
}
