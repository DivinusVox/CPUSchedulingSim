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
			do_work_index(&input, this_index, INVALID);
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
	printf("Round Robin: Context Switch %1.1f\n", contextSwitch);
	int i;
	struct Queue q;
	InitQueue(&q);
	int head;
	while(MoreToDo(input) > 0) //Keep going until all work is done
	{
		printf("time: %f\n", input.time);
		sleep(1);
		float time_now = input.time;
		if ((head = PopFront(&q)) != INVALID)
		{	
			do_work_index(&input, head, WORKFOR);
		}
		else
		{
			input.time += TENTHOFMILLISECOND;
		}		
		// add anything to queue that needs to be added now that work is done
		int add_index;
		while ((add_index = find_soonest_index(input, time_now)) != -1)
		{
			PushBack(&q, add_index);
			time_now = input.arrival_time[add_index] + TENTHOFMILLISECOND;
		}			
		// Reattach head to end of queue and context switch
		if(head != INVALID)
		{
			PushBack(&q, head);
			input.time += contextSwitch;
		}
	}	
	print_table(input);
}
