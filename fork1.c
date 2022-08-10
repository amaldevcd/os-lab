#include <stdio.h>
#include <unistd.h>
int main()
{
	int x=1;
	int pid1,pid2;
	int pid=fork();
	if(pid==-1)
	{
		printf("System call failed");
		return 0;
	}
	else if(pid==0)	
	{
		pid1=getpid();
		printf("%d is the id of the child\n",pid1);
	}
	else
	{
		pid2=getpid();
		printf("%d is the id of the parent \n",pid2);
	}
	return 0;
}
