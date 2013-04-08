#include <stdio.h>
#include "queue.h"


#define WORKFOR				4
#define INVALID				-1
#define TENTHOFMILLISECOND	.1

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
	int head = -1;
	while(MoreToDo(input) > 0) //Keep going until all work is done
	{
		float time_now = input.time;
		if (q->head != NULL)
		{	
			head = PopFront(q);
			do_work_index(&input, i, WORKFOR);
		}
		else// ELSE pass .1ms cycle
		{
			input.time += TENTHOFMILLISECOND;
		}
		
		// REGARDLESS add anything to queue that needs to be added now that work is done
		int add_index;
		while ((add_index = find_soonest_index(Process, time_now)) != -1)
		{
			PushBack(q, add_index);
			time_now = input.arrival_time + TENTHOFMILLISECOND; //test for already inside somehow
		}			
		// Reattach head to end of queue and context switch
		if(head != INVALID)
		{
			PushBack(q, head);
			input.time += contextSwitch;
		}
	}	
	print_table(input);
}
