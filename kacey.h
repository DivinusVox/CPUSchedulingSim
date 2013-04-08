//#include <stdio.h>
//#include "processtable.h"

// First Come First Serve
// takes array of ints
// 	consumed in threes

void FirstCome(ProcessTable input)
{
	int i;
	for (i=0; i<input.size; i++)
	{
		do_work_index(&input, i, input.base_cycles[i]);
	}
	
	printf("First Come First Served:\n\n");
	print_table(input);
}


// Shortest Remaining Time
// takes array of ints,
// 	consumed in threes
void ShortestRemaining(ProcessTable input)
{
	printf("%d\n", input.pid[0]);
}
