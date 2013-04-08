// Shortest Job First
#include <stdio.h>
#define LARGENUMBER 1000000000

void ShortestJob(ProcessTable input)
{
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
	printf("Shortest Job First");
	print_table(input);
	
}


// Round Robin

void RoundRobin(ProcessTable input)
{
}
