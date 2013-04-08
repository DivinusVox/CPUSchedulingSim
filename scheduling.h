#include <stdio.h>
#include "queue.h"

#define WORKFOR				4
#define INVALID				-1
#define TENTHOFMILLISECOND	.1f

// Shortest Job First
// Purpose: Simulates a shortest job first disk schudule
// pre: input is a populated struct
void ShortestJob(ProcessTable input)
{
	printf("Shortest Job First\n");
	int i;
	while((MoreToDo(input) > 0))
	{
		int this_index; 
		this_index = find_shortest_index(input);
		
		if (this_index != INVALID)
			do_work(&input, this_index, INVALID);
		else
			input.time += 1;
	}
	print_table(input);
}


// Round Robin
// Purpose: Simulates a round robin disk schdule
// pre: input is a populated struct, contextSwitch is > 0
void RoundRobin(ProcessTable input, float contextSwitch)
{
	printf("Round Robin with Context Switch of %1.1f\n", contextSwitch);
	int i;
	struct Queue q;
	InitQueue(&q);
	int head = INVALID;
	float time_now = -1;
	while(MoreToDo(input) > 0) //Keep going until all work is done
	{
		//printf("time: %5.2f \n", input.time);
		//sleep(1);
	
		// add anything to queue that needs to be added
		int add_index;
		while ((add_index = find_soonest_index(input, time_now)) != -1)
		{
			PushBack(&q, add_index);
			time_now = input.arrival_time[add_index] + TENTHOFMILLISECOND;
		}
		time_now = input.time;
		// Reattach head to end of queue and add context switch
		if(head != INVALID)
		{
			
			if(input.remaining_cycles[head] != 0)
			{		
				PushBack(&q, head);
			}
			input.time += contextSwitch;
		}		
		
		if ((head = PopFront(&q)) != INVALID)
		{
			do_work(&input, head, WORKFOR);
		}
		else
		{
			input.time += TENTHOFMILLISECOND;
		}		
	}	
	print_table(input);
}

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
