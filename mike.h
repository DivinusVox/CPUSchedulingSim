// Shortest Job First
#include <stdio.h>
#define LARGENUMBER 1000000000

void ShortestJob(ProcessTable input)
{
	printf("Shortest Job First\n");

	while(MoreToDo(input) > 0)
	{
		int this_index;
		if ((this_index = find_shortest_index(input)) != -1)
			do_work_index(&input, this_index, -1);
	}
	
	print_table(input);
	/*
	int i, j;
	for(i = 0; i < input.size; ++i) // Loop until all jobs are done
	{
		int current_canidate = -1;
		for(j = 0; j < input.size; ++j) //Find Shorest Job's index
		{
			if (input.remaining_cycles[j] != 0)
			{
				if (current_canidate == -1)
				{
					current_canidate = j;
				}
				else if (input.remaining_cycles[j] > input.remaining_cycles[current_canidate])
				{
					current_canidate = j;
				}				
			}				
		}
		if (current_canidate != 1)
			do_work_index(&input, current_canidate, -1);
	}
	printf("Shortest Job First\n");
	print_table(input);
	*/
}


// Round Robin

void RoundRobin(ProcessTable input, float contextSwitch)
{
	printf("Round Robin: Context Switch %1.1f\n", contextSwitch);
	print_table(input);
}
