#include<stdio.h>
#include<conio.h>

int main()
{
	int x;
	int number_of_process;
	int process[20];
	int process_priority[20];
	int burst_time[20];
	int waiting_time[20];
	int turn_around_time[20];
	int average_waiting_time;
	int average_turn_around_time;
	int arrival_time[10];
	int time_quantum;
	
	printf("\t\tRound Robin Scheduling with Higher number Priority and preemption\t\n");
	printf("\nEnter the number of processes: ");
	scanf("%d",&number_of_process);
	printf("enter the time quantum: ");
	scanf("%d",&time_quantum);
	printf("Enter the details for processes\n");
	
	
	int i;
	for (i=0; i<number_of_process; i++)
	{
		printf("Process%d\n",i+1);
		printf("  Priority: ");
		scanf("%d", &process_priority[i]);
		printf("  Arrival Time: ");
		scanf("%d", &arrival_time[i]);
		printf("  Burst Time: ");
		scanf("%d", &burst_time[i]);
		printf("\n\n");
		process[i] = i+1;
	}
	
	
	int j;
	
	for (i=0; i<number_of_process-1; i++)
	{
		for (j=i+1; j<number_of_process; j++)
		{
			if(process_priority[i]<process_priority[j])
			{
				x = process_priority[i];
				process_priority[i] = process_priority[j];
				process_priority[j] = x;
				x = burst_time[i];
				burst_time[i] = burst_time[j];
				burst_time[j] = x;
				x = process[i];
				process[i] = process[j];
				process[j] = x;
			}
		}
	}

waiting_time[0] = 0;
average_waiting_time = 0;
turn_around_time[0] = burst_time[0];
average_turn_around_time = turn_around_time[0];

for(i=1; i<number_of_process; i++)
{
	if(time_quantum<number_of_process || time_quantum>number_of_process)
	{
		
		waiting_time[i] = turn_around_time[i-1];
		average_waiting_time += waiting_time[i];
		turn_around_time[i] = waiting_time[i] + burst_time[i];
		average_turn_around_time += turn_around_time[i];
		 
	}
	
	
	printf("\n");
	printf("Gantt chart\n");
	for(i=0; i<number_of_process; i++)
	{
		printf("Process%d", process[i]);
	}
	

	
}	
	
	
	printf("\nProcess_id |\tPriority |\tArrival Time |\tBurst Time | \t Waiting Time| \tTurn Around Time");
	
	
	
	for(i=0;i<number_of_process;i++)
	{
		printf("\n%d \t\t%d \t\t%d \t\t%d \t\t%d \t\t%d\n", i+1, process_priority[i], arrival_time[i], burst_time[i],waiting_time[i], turn_around_time[i]);
		
	}
	printf("Average_waiting_time = %f\n Average_turn_around_time =%f\n\n", (float)average_waiting_time/number_of_process, (float)average_turn_around_time/number_of_process);
		
	
	
}

