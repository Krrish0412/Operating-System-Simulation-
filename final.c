#include<stdio.h> 
#include<windows.h>

 
int main() 
{ 
      int i, limit, total = 0, x, counter = 0, time_quantum,TAT=0,WT=0; 
      int arrival_time[10], burst_time[10], temp[10],priority[10]; 
      float average_wait_time, average_turnaround_time;
      printf("\t\t--------------------------------Round Robin Scheduling with Priority and preemption-------------------------------------------------\t");
	  printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit); 
      x = limit; 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            printf("Priority:\t");
            scanf("%d",&priority[i]);
           
      } 
      for(i=0;i<limit;i++) 
      {
		int j;      	
      	for(j=i+1;j<limit;j++)
      	{
      		int swap=priority[i];
      		priority[i]=priority[j];
      		priority[j]=swap;
		  }
		  temp[i]=burst_time[i];
	  }
	  
      printf("\nProcess ID\t\tArrival Time||\tBurst Time||\t Turnaround Time||\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  TAT=total-arrival_time[i];
                  WT=TAT-burst_time[i];
                  if(TAT<0)
                {
				  TAT=0;
            	}
				  if(WT<0)
                {
				  WT=0;
              	}
				  printf("\nProcess %d\t\t%d\t\t%d\t\t %d\t\t\t %d", i + 1,arrival_time[i], burst_time[i], TAT, WT);	
				 
                  WT=WT+total-arrival_time[i]-burst_time[i];
				  TAT=TAT+total-arrival_time[i];
                  
                  if(WT<0)
                 {
				 	 WT=0;
                 }
				  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
            Sleep(100);
      } 
      average_wait_time = WT * 1.0 / limit;
      average_turnaround_time = TAT * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%0.2f", average_wait_time); 
      Sleep(100);
      printf("\nAvg Turnaround Time:\t%0.2f\n", average_turnaround_time); 
      return 0; 
  }
