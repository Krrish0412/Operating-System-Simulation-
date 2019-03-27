#include<stdio.h>
int number_of_process, time_quantum,total_waiting_time=0, total_turn_around_time=0;
struct prog{
	int waiting_time;
	int burst_time;
	int turn_around_time;
	int flag;
	int temp;
	int priority;
};prog1[]

void print_result()
{
	printf("\nProcess_id |\tPriority |\tBurst_time | \t Waiting_time|\tTurn_around_time");
	
	int i;
	int n = number_of_process;
	for(i=0;i<n,i++)
	{
		printf("\n%d \t\t%d \t\t%d \t\t%d \t\t%d\n", i, priority[i], burst_time[i], waiting_time[i], turn_around_time);
		
	}
	printf("Average_waiting_time = %f\n Average_turn_around_time =%f\n\n", (float)total_waiting_time/n, (float)total_turn_around_time/n);
	
	
}


main()
{
	printf("-------------------PRIORITY BASED PREEMPTIVE ROUND ROBIN ALGORITHM--------------------";)
	
}
