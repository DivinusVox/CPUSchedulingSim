#include <stdio.h>
//#include "processtable.h"

// First Come First Serve
// takes array of ints
// 	consumed in threes

void FirstCome(ProcessTable input)
{
	int i;
	for (i=0; i<input.size; i++)
	{
		do_work(&input, i, input.remaining_cycles[i]);
	}
	
	printf("First Come First Served:\n\n");
	print_table(input);
}

// Shortest Remaining Time
// takes array of ints,
// 	consumed in threes
void ShortestRemaining(ProcessTable input)
{
	printf("Shortest Remaining\n\n");

	// Find shortest current job
	// run for 1 cycle
	// loop
	int x;

	while ((x = MoreToDo(input)) > 0)
	{
		int shortest = find_shortest_index(input);
		if (shortest != -1)
			do_work(&input, shortest, 1);
		else
			input.time += 1.0;
		getchar();
	}

	print_table(input);
}
