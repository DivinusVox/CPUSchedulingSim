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
		do_work_index(&input, i, input.remaining_cycles[i]);
	}
	
	printf("First Come First Served:\n\n");
	print_table(input);
}


// MoreTODO
//
int MoreToDo(ProcessTable input)
{
	int remaining = 0;
	int i;
	for (i=0; i<input.size; i++)
	{
		if (input.remaining_cycles[i] > 0)
			remaining++;
		//printf("%d\n",input.remaining_cycles[i]);
	}
	
	return remaining;
}

// Shortest Remaining Time
// takes array of ints,
// 	consumed in threes
void ShortestRemaining(ProcessTable input)
{
	printf("Shortest Remaining\n\n");

	//printf("Huh? %d\n", MoreToDo(input));
	
	//printf("Short =>%d\n", find_shortest_index(input));
	// Find shortest current job
	// run for 1 cycle
	// loop
	int x;

	while ((x = MoreToDo(input)) > 0)
	{
		printf("%d IMPLIES X AND STUFF! NOTICE ME!\n", x);
		//printf("More to do stuffs, yeah?");
		int shortest = find_shortest_index(input);
		if (shortest != -1)
			do_work_index(&input, 2, 1);
			do_work_index(&input, 1, 1);
		else
			input.time += 1.0;
	}
}


