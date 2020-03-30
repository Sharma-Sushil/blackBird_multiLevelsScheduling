#include <stdio.h>
int arrivalTime[10],burstTime[10],priorityValue[10],totalTime = 0,i=0,totalprocessOfQueue1=0,timeOfQueue1=0,timeOfQueue2=0,timeOfQueue3=0,totalprocessOfQueue2=0,totalprocessOfQueue3=0;
int arrivalTimeOfQueue1[10],burstTimeOfQueue1[10],dummy[10],down,temp,count=0;
float avgWaitingTimeOfQueue1=0.0,avgTurnaroundTimeOfQueue1=0.0;
int arrivalTimeOfQueue2[10],burstTimeOfQueue2[10],waitingTimeOfQueue2[10],turnaroundTimeOfQueue2[10],priorityForQueue2[10],temp1,processOfQueue2[10];
float avgWaitingTimeOfQueue2=0.0,avgTurnaroundTimeOfQueue2=0.0;
int arrivalTimeOfQueue3[10],burstTimeOfQueue3[10],waitingTimeOfQueue3[10],turnaroundTimeOfQueue3[10];
float avgWaitingTimeOfQueue3=0.0,avgTurnaroundTimeOfQueue3=0.0;

void exit(int s);

void getData()
{
    int numberOfProcess;
	printf("Enter the number of process:");
	scanf("%d",&numberOfProcess);
	if(numberOfProcess>10)
	{
		printf("Not possible \nAs size of each queue is 10 only\nAnd all process can be inserted into same queue as well\n ");
		exit(0);
	}
	if(numberOfProcess<1)
    {
        printf("\nWrong Input or no process is entered.\n");
        printf("Try again.");
        exit(0);
    }
	for(i=0;i<numberOfProcess;i++)
	{
		printf("Enter details of process %d \n",i+1);
		printf("Arrival Time:");
		scanf("%d",&arrivalTime[i]);
		printf("Burst Time:");
		scanf("%d",&burstTime[i]);
	 a1:printf("Enter Priority  between 1 to 30:");
		scanf("%d",&priorityValue[i]);
		if(priorityValue[i]>30 || priorityValue[i]<1)
        {
            printf("Enter the priority value in given range only\n");
            goto a1;
        }
		totalTime=totalTime+burstTime[i];
	}

	for(i=0;i<numberOfProcess;i++)
	{
		if(priorityValue[i]>=1&&priorityValue[i]<=10)
		{   printf("\nThe given process %d is inserted into Queue 1\n",i+1);
			arrivalTimeOfQueue1[totalprocessOfQueue1]=arrivalTime[i];
			burstTimeOfQueue1[totalprocessOfQueue1]=burstTime[i];
			totalprocessOfQueue1++;
			timeOfQueue1=timeOfQueue1+burstTime[i];
		}

		else if(priorityValue[i]>=11&&priorityValue[i]<=20)
		{
			printf("The given process %d is inserted into Queue 2\n",i+1);
			arrivalTimeOfQueue2[totalprocessOfQueue2]=arrivalTime[i];
			burstTimeOfQueue2[totalprocessOfQueue2]=burstTime[i];
			priorityForQueue2[totalprocessOfQueue2]=priorityValue[i];
			processOfQueue2[totalprocessOfQueue2]=totalprocessOfQueue2+1;
			totalprocessOfQueue2++;
			timeOfQueue2=timeOfQueue2+burstTime[i];
		}

		else if(priorityValue[i]>=21&&priorityValue[i]<=30)
		{
			printf("The given process %d is inserted into Queue 3\n\n",i+1);
			arrivalTimeOfQueue3[totalprocessOfQueue3]=arrivalTime[i];
			burstTimeOfQueue3[totalprocessOfQueue3]=burstTime[i];
			totalprocessOfQueue3++;
			timeOfQueue3=timeOfQueue3+burstTime[i];
		}
	}
}

void quantumQueue()
{
	printf("Quantum time between the 3 queues is given 10 seconds.\n");
	for(i=1;i<totalTime;i=i+10)
	{
		if(timeOfQueue1>10)
		{
			printf("Queue 1 is running for 10 seconds\n");
			timeOfQueue1=timeOfQueue1-10;
		}
		else if(timeOfQueue1<=10&&timeOfQueue1!=0)
		{
			printf("Queue 1 is running for %d seconds.\n",timeOfQueue1);
			timeOfQueue1=0;
		}
		if(timeOfQueue2>10)
		{
			printf("Queue 2 is running for 10 seconds.\n");
			timeOfQueue2=timeOfQueue2-10;
		}
		else if(timeOfQueue2<=10&&timeOfQueue2!=0)
		{
			printf("Queue 2 is running for %d seconds.\n",timeOfQueue2);
			timeOfQueue2=0;
		}
		if(timeOfQueue3>10)
		{
			printf("Queue 3 is running for 10 seconds.\n");
			timeOfQueue3=timeOfQueue3-10;
		}
		else if(timeOfQueue3<=10&&timeOfQueue3!=0)
		{
			printf("Queue 3 is running for %d seconds.\n",timeOfQueue3);
			timeOfQueue3=0;
		}
	}
}

void roundRobin()
{   if(totalprocessOfQueue1<1)
    {
        return ;
    }
    printf("\nRound robin algorithm is processing...\n\n");
	printf("Quantum time for queue 1 is given 4 seconds.\n");
	for(i=0;i<totalprocessOfQueue1;i++)
	{
		dummy[i]=burstTimeOfQueue1[i];
	}
	down=totalprocessOfQueue1;
	i=0;temp=0;
    while(down!=0)
    {
    	if(dummy[i]<=4&&dummy[i]>0)
        {
			printf("\nProcess %d of Queue 1 is running for %d seconds.",i+1,dummy[i]);
            temp=temp+dummy[i];
            dummy[i]=0;
            count=1;
        }
        else if(dummy[i]>0)
        {
			printf("\nProcess %d of Queue 1 is running for 4 seconds.",i+1);
            dummy[i]=dummy[i]-4;
            temp=temp+4;
        }
        if(dummy[i]==0&&count==1)
        {
            down--;
            printf("\n\nProcess ID : Process %d is completed.\nBurst Time:%d\nTurnaround Time:%d\nwaiting Time:%d\n",i+1,burstTimeOfQueue1[i],temp-arrivalTimeOfQueue1[i],temp-arrivalTimeOfQueue1[i]-burstTimeOfQueue1[i]);
            avgWaitingTimeOfQueue1=avgWaitingTimeOfQueue1+temp-arrivalTimeOfQueue1[i]-burstTimeOfQueue1[i];
            avgTurnaroundTimeOfQueue1=avgTurnaroundTimeOfQueue1+temp-arrivalTimeOfQueue1[i];
            count = 0;
        }
        if(i==totalprocessOfQueue1-1)
        {
            i=0;
        }
        else if(arrivalTimeOfQueue1[i+1]<=temp)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    avgWaitingTimeOfQueue1=avgWaitingTimeOfQueue1/totalprocessOfQueue1;
    avgTurnaroundTimeOfQueue1=avgTurnaroundTimeOfQueue1/totalprocessOfQueue1;
    printf("\nAverage Waiting Time:%.2f",avgWaitingTimeOfQueue1);
    printf("\nAverage Turnaround Time:%.2f\n",avgTurnaroundTimeOfQueue1);
}

void priority()
{   if(totalprocessOfQueue2<1)
    {
        return;
    }
    printf("\n\nPriority scheduling algorithm  is processing...\n");
    int sumForCalculation=0,a;
    int currentLocation;
	for(i=0;i<totalprocessOfQueue2;i++)
    {
        currentLocation=i;
        a=i+1;

        for(a;a<totalprocessOfQueue2;a++)
        {
            if(priorityForQueue2[a]<priorityForQueue2[currentLocation])
            {
                currentLocation=a;
            }
        }
        temp1=priorityForQueue2[i];
        priorityForQueue2[i]=priorityForQueue2[currentLocation];
        priorityForQueue2[currentLocation]=temp1;

        temp1=burstTimeOfQueue2[i];
        burstTimeOfQueue2[i]=burstTimeOfQueue2[currentLocation];
        burstTimeOfQueue2[currentLocation]=temp1;

        temp1=processOfQueue2[i];
        processOfQueue2[i]=processOfQueue2[currentLocation];
        processOfQueue2[currentLocation]=temp1;
    }
    waitingTimeOfQueue2[0]=0;
    for(i=1;i<totalprocessOfQueue2;i++)
    {
        waitingTimeOfQueue2[i]=0;
        for(a=0;a<i;a++)
        {
            waitingTimeOfQueue2[i]=waitingTimeOfQueue2[i]+burstTimeOfQueue2[totalprocessOfQueue1];
        }
        sumForCalculation=sumForCalculation+waitingTimeOfQueue2[i];
    }
    avgWaitingTimeOfQueue2=sumForCalculation/totalprocessOfQueue2;
    sumForCalculation=0;
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i=0;i<totalprocessOfQueue2;i++)
    {
    	turnaroundTimeOfQueue2[i]=burstTimeOfQueue2[i]+waitingTimeOfQueue2[i];
        sumForCalculation=sumForCalculation+turnaroundTimeOfQueue2[i];
        printf("\nProcess %d\t\t%d\t\t %d\t\t %d\n",processOfQueue2[i],burstTimeOfQueue2[i],waitingTimeOfQueue2[i],turnaroundTimeOfQueue2[i]);
    }
    avgTurnaroundTimeOfQueue2=sumForCalculation/totalprocessOfQueue2;
    printf("\nAverage Waiting Time: %.2f",avgWaitingTimeOfQueue2);
    printf("\nAverage Turnaround Time: %0.2f\n",avgTurnaroundTimeOfQueue2);

    for(i=0;i<totalprocessOfQueue2;i++)
    {
    	while(burstTimeOfQueue2[i]!=0)
    	{
    		if(burstTimeOfQueue2[i]>10)
    		{
				printf("\nProcess %d of Queue 2 is running for 10 seconds",i+1);
				burstTimeOfQueue2[i]=burstTimeOfQueue2[i]-10;
			}
			else if(burstTimeOfQueue2[i]<=10)
			{
				printf("\nProcess %d of Queue 2 is running for %d seconds",i+1,burstTimeOfQueue2[i]);
				burstTimeOfQueue2[i]=0;
			}
		}
	}

}


void firstComeFirstServe()
{   if(totalprocessOfQueue3<1)
    {
        return;
    }
    printf("\n\nFirst Come First Serve algorithm is processing...\n");
	waitingTimeOfQueue3[0] = 0;
    for(i=1;i<totalprocessOfQueue3;i++)
    {
        waitingTimeOfQueue3[i] = 0;
        for(int p=0;p<totalprocessOfQueue3;p++)
        {
            waitingTimeOfQueue3[i]=waitingTimeOfQueue3[i]+burstTimeOfQueue3[p];
        }
    }
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<totalprocessOfQueue3;i++)
    {
        turnaroundTimeOfQueue3[i]=burstTimeOfQueue3[i]+waitingTimeOfQueue3[i];
        avgWaitingTimeOfQueue3=avgWaitingTimeOfQueue3+waitingTimeOfQueue3[i];
        avgTurnaroundTimeOfQueue3=avgTurnaroundTimeOfQueue3+turnaroundTimeOfQueue3[i];
        printf("\nProcess %d\t%d\t\t%d\t\t%d\n",i+1,burstTimeOfQueue3[i],waitingTimeOfQueue3[i],turnaroundTimeOfQueue3[i]);
    }
    avgWaitingTimeOfQueue3=avgWaitingTimeOfQueue3/totalprocessOfQueue3;
    avgTurnaroundTimeOfQueue3=avgTurnaroundTimeOfQueue3/totalprocessOfQueue3;
    printf("\nAverage Waiting Time=%.2f",avgWaitingTimeOfQueue3);
    printf("\nAverage Turnaround Time=%.2f",avgTurnaroundTimeOfQueue3);
    for(i=0;i<totalprocessOfQueue3;i++)
    {
    	while(burstTimeOfQueue3[i]!=0)
    	{
    		if(burstTimeOfQueue3[i]>10)
    		{
				printf("\nProcess %d of Queue3 is running for 10 seconds.",i+1);
				burstTimeOfQueue3[i]=burstTimeOfQueue3[i]-10;
			}
			else if(burstTimeOfQueue3[i]<=10)
			{
				printf("\nProcess %d of Queue3 is running for %d seconds.",i+1,burstTimeOfQueue3[i]);
				burstTimeOfQueue3[i]=0;
			}
		}
	}
}



int main()
{
    	getData();
	quantumQueue();
    	roundRobin();
    	firstComeFirstServe();
    	priority();

	return 0;
}
