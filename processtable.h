#define	TABLESIZE	100
#define DEBUGMODE	1
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

/* Do work by pid
 * Purpose does work on a function by pid.
 * Arguments required: 
 *						- table: a table with some indexes
 *						- work_pid: the pid of the job to do work on
 *						- cycles: The number of cycles of work to do. 
 *									pass -1 to go until done.
 * Return values: 
 *						- 0 if there is no work to be done on a job.
 *						- -1 for pid doesn't exist
 *						- Otherwise a positive interger with the number of rounds
 *							actually worked.
 */
int do_work_pid(ProcessTable* table, int work_pid, int cycles)
{
	//find pid in table
	int i;
	int pid_index = -1;
	for( i = 0; i < table->size; i++)
	{
		if (table->pid[i] == work_pid)
			pid_index = i;
	}
	if (pid_index == -1)	// pid was not found return with error.
		return pid_index; 
	
	return do_work_index(table, pid_index, cycles);
	
}

/* Do work by index
 * Purpose does work on a function by pid.
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
int do_work_index(ProcessTable* table, int index, int cycles)
{
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
		printf("%5d%8.2f%12.2f",table.pid[i], table.wait_time[i], turn_around);
		if (DEBUGMODE != 0)
			printf("%8.2f%10.2f", table.arrival_time[i],table.time_completed[i]);
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
