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
		int thisIndex; 
		thisIndex = FindShortestIndex(input);
		
		if (thisIndex != INVALID)
			DoWork(&input, thisIndex, INVALID);
		else
			input.time += 1;
	}
	PrintTable(input);
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
		int addIndex;
		while ((addIndex = FindSoonestIndex(input, time_now)) != -1)
		{
			PushBack(&q, addIndex);
			time_now = input.arrival[addIndex] + TENTHOFMILLISECOND;
		}
		time_now = input.time;
		// Reattach head to end of queue and add context switch
		if(head != INVALID)
		{
			
			if(input.remainingCycles[head] != 0)
			{		
				PushBack(&q, head);
			}
			input.time += contextSwitch;
		}		
		
		if ((head = PopFront(&q)) != INVALID)
		{
			DoWork(&input, head, WORKFOR);
		}
		else
		{
			input.time += TENTHOFMILLISECOND;
		}		
	}	
	PrintTable(input);
}

// First Come First Serve
// Simulates FCFS process scheduler
// Takes a populated struct
//    Consumes in order of structure's arrays

void FirstCome(ProcessTable input)
{
	int i;
	for (i=0; i<input.size; i++)
	{
		DoWork(&input, i, input.remainingCycles[i]);
	}
	
	printf("First Come First Served:\n\n");
	PrintTable(input);
}

// Shortest Remaining Time
// Simulates Shortest Remaining Time process scheduler
// Takes a populated struct
void ShortestRemaining(ProcessTable input)
{
	printf("Shortest Remaining\n\n");

	// Find shortest current job
	// run for 1 cycle
	// loop
	int x;

	while ((x = MoreToDo(input)) > 0)
	{
		int shortest = FindShortestIndex(input);
		if (shortest != -1)
			DoWork(&input, shortest, 1);
		else
			input.time += 1.0;
		getchar();
	}

	PrintTable(input);
}
