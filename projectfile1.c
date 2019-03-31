#include<stdio.h>
 
int time_quantum;
int total_waiting_time=0;
int total_turn_around_time=0;
int n;

struct prog{
	int waiting_time;
	int burst_time;
	int turn_around_time;
	int flag;
	int temp;
	int priority;
	
}prog1[12];

void print_result()
{
	printf("\nProcess_id |\tPriority |\tBurst_time | \t Waiting_time|\tTurn_around_time");
	
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t%d \t\t%d \t\t%d \t\t%d\n", i, prog1[i].priority, prog1[i].burst_time, prog1[i].waiting_time, prog1[i].turn_around_time);
		
	}
	printf("Average_waiting_time = %f\n Average_turn_around_time =%f\n\n", (float)total_waiting_time/n, (float)total_turn_around_time/n);
	
	
}

void reschedule()
{
	int turn_around_time = 0, i=0;
	while(completed()==0)
	{
		if (prog1[i].flag == 0)
			{
				if(prog1[i].temp==0||prog1[i].temp<=time_quantum)
				{
					prog1[i].flag = 1;
					turn_around_time += prog1[i].temp;
					total_turn_around_time += prog1[i].turn_around_time = turn_around_time;
					prog1[i].temp = 0;
				}
				else
				{
				 	turn_around_time += time_quantum;
					 prog1[i].temp = time_quantum;	
				}
			}
			i = (i+1)%n;
	}
}

int completed()
{
	int sum =0, i;
	for (i=0;i<n;i++)
	{
		if(prog1[i].flag==1)
		sum++;
	}
	if(sum==n)
		return 1;
	else
		return 0;	
		
}


main()
{
	printf("-------------------------------PRIORITY BASED PREEMPTIVE ROUND ROBIN ALGORITHM----------------------------\n");
	int i;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	printf("\nEnter the time quantum for the process:\n");
	scanf("%d", &time_quantum);
	for (i=0; i<n; i++)
	{
		printf("\nEnter the burst time for process %d:\n",i);
		scanf("%d", &prog1[i].burst_time);
		prog1[i].flag = 0;
		prog1[i].temp = prog1[i].burst_time;	
	}
	prog1[0].waiting_time=0;
	int wtpmtr = 0;
	for(i=0; i<n-1; i++)
	{
		if(prog1[i].burst_time<time_quantum)
		{
			wtpmtr += prog1[i].burst_time;	
		}
		else{
		
			wtpmtr += time_quantum;
			prog1[i+1].waiting_time = wtpmtr;
			total_waiting_time += prog1[i+1].waiting_time;
		}
		
		
	}
	
	reschedule();
	print_result();
}
