#define	TABLESIZE	100
struct ProcessTable
{
	int pid[TABLESIZE];
	int arrival_time[TABLESIZE];
	int wait_time[TABLESIZE];
	int time_completed[TABLESIZE];
	int remaining_cycles[TABLESIZE];
	int time[TABLESIZE];
}

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
int do_work_pid(struct ProcessTable table, int work_pid, int cycles)
{
	//find pid in table
	int i;
	int pid_index = -1;
	for( i = 0; i < TABLESIZE; i++)
	{
		if (table.pid[i] == work_pid)
			pid_index = i;
	}
	if (pid_index == -1)	// pid was not found return with error.
		return pid_index; 
	

	for(i = 0; (i < cycles) && (table.remaining_cycles > 0); i++)
	{
		time++;
		
	}
}
int do_work_index