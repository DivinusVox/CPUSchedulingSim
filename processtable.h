#include <stdio.h>
#include <string.h>

#define DEBUGMODE	0
#define	TABLESIZE	100
#define LENGTH 300
#define MAX_LINES 100

typedef struct
{
	int pid[TABLESIZE];
	float arrival_time[TABLESIZE];
	float wait_time[TABLESIZE];
	float time_completed[TABLESIZE];
	int remaining_cycles[TABLESIZE];
	float time;
	int size;
} ProcessTable;

/* initialize table
 * Purpose: initialized import values in the table.
 * Pre: stdin is populated with set of three variables.
 * Post: table is properly initialized
 */
void initializeTable(ProcessTable* pTable)
{
	char streamInput[MAX_LINES];
	int values[LENGTH];
	int i = 0;
	// get stdinput
	while(fgets(streamInput, 256, stdin) != NULL)
	{
		// fill arrays
		char* splitVals1;
                char* splitVals2; 
		char* splitVals3;
		splitVals1 = strtok(streamInput, " \t\n");
		if (splitVals1 != NULL)
		{
			splitVals2 = strtok(NULL, " \t\n");
			splitVals3 = strtok(NULL, " \t\n");
			
			pTable->pid[i] = atoi(splitVals1);
			pTable->arrival_time[i] = atoi(splitVals2);
			pTable->remaining_cycles[i] = atoi(splitVals3);
			pTable->wait_time[i] = -1;
		}	
		i++;
	}
	pTable->size = i;
	pTable->time = 0;
	
}

/* More to do
 * Purpose: Interates through the process table's remaining cycles
 * and returns the number of expected remaining cycles.
 * Pre: input.remaining_cycles set for all in size range
 */
int MoreToDo(ProcessTable input)
{
	int remaining = 0;
	int i;
	for (i=0; i<input.size; i++)
	{
		if (input.remaining_cycles[i] > 0)
			remaining++;
	}
	
	return remaining;
}

/* Do work
 * Purpose does work on an element in the table
 * Arguments required: 
 *						- table: a table with some indexes
 *						- index: the index of the variables to do work on
 *						- cycles: The number of cycles of work to do. 
 *									pass -1 to go until done.
 * Return values: 
 *						- 0 if there is no work to be done on a job.
 *						- Otherwise a positive interger with the number of rounds
 *							actually worked.
 */
int do_work(ProcessTable* table, int index, int cycles)
{
	if (DEBUGMODE != 0) printf("Working on pid: %d. %d time remaining.\n", table->pid[index], table->remaining_cycles[index]);
	int i = 0;
	if(table->wait_time[index] == -1)
		table->wait_time[index] = table->time - table->arrival_time[index];
	if (cycles == -1)
		cycles = table->remaining_cycles[index];
	for(i = 0; (i < cycles) && (table->remaining_cycles[index] > 0); i++)
	{
		table->remaining_cycles[index] -= 1;
		if (table->remaining_cycles[index] == 0)
		{
			table->time += 1;
			table->time_completed[index] = table->time;
			break;
		}
		table->time += 1;
	}
	return i;
}
/*	Print Table
 *	Purpose: Print out formatted results of a Process that has been run
 * 	Pre: An alorithmn has been run on the ProcessTable table so that
 *	the time_complteted and arrival_time are populated.
 */
void print_table(ProcessTable table)
{
	int i;
	float average_wait = 0;
	float average_turn_around = 0;
	printf("%5s%8s%12s", "Pid","Wait","Turnaround");
	if (DEBUGMODE != 0)
		printf("%8s%10s", "Entry","Complete");
	printf("\n");
	printf("%5s%8s%12s", "---","----","----------");
	if (DEBUGMODE != 0)
		printf("%8s%10s", "-----","--------");
	printf("\n");
	for(i = 0; i < table.size; i++)
	{
		float turn_around = table.time_completed[i] - table.arrival_time[i];
		printf("%5d%8.1f%12.1f",table.pid[i], table.wait_time[i], turn_around);
		if (DEBUGMODE != 0)
			printf("%8.1f%10.1f", table.arrival_time[i],table.time_completed[i]);
		printf("\n");
		average_wait += table.wait_time[i];
		average_turn_around += turn_around;
	}
	average_wait = average_wait / i;
	average_turn_around = average_turn_around / i;
	printf("Average wait: %f Average turnaround: %f\n\n", average_wait, average_turn_around);
}
/* Find Shortest Index
 * Purpose: find the index of the smallest element of a member of an array that is currently in the queue.
 */
int find_shortest_index(ProcessTable table)
{
	int current_canidate = -1;
	int i;
	for(i = 0; i < table.size; ++i)
	{
		if (table.time >= table.arrival_time[i] && (table.remaining_cycles[i] != 0)) //Test that entry exists
		{
			// Test that it is shorter than the current canidate and not done
			if ((current_canidate == -1) || (table.remaining_cycles[current_canidate] > table.remaining_cycles[i]))
				current_canidate = i;
		}
	}
	
	return current_canidate;
}

/* Find Shortest Index
 * Purpose: find the index of the soonest element in the time range
 * between start and table.time.
 */
int find_soonest_index(ProcessTable table, float start)
{
	int current_canidate = -1;
	int i;
	for(i = 0; i < table.size; ++i)
	{
		if (DEBUGMODE > 1) printf("%f >= %f >= %f\n", table.time, table.arrival_time[i], start);
		if (table.time >= table.arrival_time[i] && (table.arrival_time[i] > start)) //Test that entry exists
		{
			if (DEBUGMODE != 0) printf("Find soonest index considering:%d\n", i);
			// Test that it is shorter than the current canidate and not done
			if ((current_canidate == -1) || (table.arrival_time[current_canidate] > table.arrival_time[i]))
				current_canidate = i;
		}		
	}	
	//if (DEBUGMODE != 0) printf("\n");
	return current_canidate;
}