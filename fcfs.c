#include <stdio.h>
#include <stdlib.h>
typedef struct fcfs
	{
			int pid,atime,btime,wtime,ttime,ctime;
	}fcfs;

struct fcfs p[10],temp;
	float totwtime=0, tottime=0;
int main()
{
	int n;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
			p[i].pid=i+1;
			printf("Enter arrival time and burst time of process %d : ",p[i].pid);
			scanf("%d %d",&p[i].atime,&p[i].btime);
	}
	printf("\nProcess\tAT\tBt\t\n");
	for(int i=0;i<n;i++)
	{
			printf("%d\t%d\t%d\n",p[i].pid,p[i].atime,p[i].btime);
	}
	for(int i=1;i<n;i++)
	{
			if(p[i-1].atime>p[i].atime)
			{
					temp.pid=p[i-1].pid;
					temp.atime=p[i-1].atime;
					temp.btime=p[i-1].btime;
					temp.wtime=p[i-1].wtime;
					temp.ttime=p[i-1].ttime;
					p[i-1].pid=p[i].pid;
					p[i-1].atime=p[i].atime;
					p[i-1].btime=p[i].btime;
					p[i-1].wtime=p[i].wtime;
					p[i-1].ttime=p[i].ttime;
					p[i].pid=temp.pid;
					p[i].atime=temp.atime;
					p[i].btime=temp.btime;
					p[i].wtime=temp.wtime;
					p[i].ttime=temp.ttime;
			}
	}
	printf("\nProcess\tAT\tBt\t\n");
	for(int i=0;i<n;i++)
	{
			printf("%d\t%d\t%d\n",p[i].pid,p[i].atime,p[i].btime);
	}
	p[0].ctime=p[0].atime+p[0].btime;
	p[0].ttime=p[0].ctime-p[0].atime;
	p[0].wtime=p[0].ttime-p[0].btime;
	totwtime=p[0].wtime;
	tottime=p[0].ttime;
	for(int i=1;i<n;i++)
	{
			if(p[i-1].ctime<p[i].atime)
			{
					p[i].ctime=p[i].atime+p[i].btime;
					p[i].ttime=p[i].ctime-p[i].atime;
					p[i].wtime=p[i].ttime-p[i].btime;
					totwtime+=p[i].wtime;
					tottime+=p[i].ttime;
					
			}
			else
			{
					p[i].ctime=p[i-1].ctime+p[i].btime;
					p[i].ttime=p[i].ctime-p[i].atime;
					p[i].wtime=p[i].ttime-p[i].btime;
					totwtime+=p[i].wtime;
					tottime+=p[i].ttime;
			}
	}
	printf("\nProcess\tAT\tBt\tCT\tTT\tWT\t\n");
	for(int i=0;i<n;i++)
	{
			printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].ttime,p[i].wtime);
	}
	float avgttime=(tottime/n),avgwtime=(totwtime/n);
	printf("\n\n Average turnaround time = %f",avgttime);
	printf("\n\n Average waiting time =  %f", avgwtime);
}
