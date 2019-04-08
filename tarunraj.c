#include<stdio.h> 
int main() 
{ 
  int count,j,n,time,remain,flag=0,time_quantum,s; 
  int wait_time=0,turnaround_time=0,ct,at[10],bt[10],rt[10]; 
  char sit[120];
  A:
  printf("Enter the kind of requests: 1 for student requests, 2 for faculty requests: ");
  scanf("%d",&s);
  switch(s)
  {
  	case 1: printf("Student Processes initiates here: ");
  			printf("Enter Total Process:\t "); 
  			scanf("%d",&n); 
  			remain=n; 
  			for(count=0;count<n;count++) 
  			{			 
    			printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    			scanf("%d",&at[count]); 
    			scanf("%d",&bt[count]); 
    			rt[count]=bt[count]; 
  			}		 
  			printf("Enter Time Quantum:\t"); 
  			scanf("%d",&time_quantum); 
  			printf("\n\nProcess\t|Turnaround Time|Waiting Time|Completion Time|Situation\n\n"); 
  			for(time=0,count=0;remain!=0;) 			{ 
    		if(rt[count]<=time_quantum && rt[count]>0) 
    		{ 
      			time+=rt[count]; 
      			rt[count]=0; 
      			flag=1; 
    		} 
    		else if(rt[count]>0) 
    		{		 
      			rt[count]-=time_quantum; 
      			time+=time_quantum; 
    		} 
    		if(rt[count]==0 && flag==1) 
    		{ 
      			remain--; 
      			wait_time+=time-at[count]-bt[count]; 
      			turnaround_time+=time-at[count]; 
				ct = turnaround_time+wait_time;
      			printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t",count+1,time-at[count],time-at[count]-bt[count],ct);
      			if(ct >= 120)
      			{
      				printf( "not Achievable\n");	
				}
				else
				{
					printf("Achievable\n");
				}
      			flag=0; 
    		} 
    		if(count==n-1) 
      		count=0; 
    		else if(at[count+1]<=time) 
      		count++; 
    		else 
      		count=0; 
  			} 
  			printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); //waiting time
  			printf("Avg Query time= %f",turnaround_time*1.0/n); //turn around time
			break;
	case 2:	printf("Faculty Processes initiates here: ");
  			printf("Enter Total Process:\t "); 
  			scanf("%d",&n); 
  			remain=n; 
  			for(count=0;count<n;count++) 
  			{			 
    			printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    			scanf("%d",&at[count]); 
    			scanf("%d",&bt[count]); 
    			rt[count]=bt[count]; 
  			}		 
  			printf("Enter Time Quantum:\t"); 
  			scanf("%d",&time_quantum); 
  			printf("\n\nProcess\t|Turnaround Time|Waiting Time|Completion Time|Situation\n\n"); 
  			for(time=0,count=0;remain!=0;) 
  			{ 
    		if(rt[count]<=time_quantum && rt[count]>0) 
    		{ 
      			time+=rt[count]; 
      			rt[count]=0; 
      			flag=1; 
    		} 
    		else if(rt[count]>0) 
    		{		 
      			rt[count]-=time_quantum; 
      			time+=time_quantum; 
    		} 
    		if(rt[count]==0 && flag==1) 
    		{ 
      			remain--; 
      			wait_time+=time-at[count]-bt[count]; 
      			turnaround_time+=time-at[count]; 
      			ct = turnaround_time+wait_time;
      			printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t",count+1,time-at[count],time-at[count]-bt[count],ct); 
			   if(ct >= 120)
      			{
      			          printf("not Achievable\n");	
				}
				else
				{
				          printf(" Achievable\n");
				}
				flag=0; 
    		} 
    		if(count==n-1) 
      		count=0; 
    		else if(at[count+1]<=time) 
      		count++; 
    		else 
      		count=0; 
  			} 
  			printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); //waiting time
  			printf("Avg Query time= %f",turnaround_time*1.0/n); //turn around time
			break;
	default: printf("Entered choices other than 1 or 2: ");
		    goto A;
  }
  return 0;
}




