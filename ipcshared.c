#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int shmid;
	char str[30];
	void *shared_memory;	
	key_t key = ftok(".",65);
	shmid = shmget(key,1024,0666|IPC_CREAT);
	if(shmid==-1) 
	{
		if(shmid=shmget(key,1024,0)==-1)
		{
			perror("shmget");
			exit(1);
		}
	}
	else
	{
		printf("\nCreating a new shared memory segment ");
	}
	printf("\nKey of shared memory is %d ",shmid);
	shared_memory =shmat(shmid,NULL,0);
	/*if(shared_memory==NULL)
	{
		perror("shmat");
		exit(1);
	}*/
	printf("\nProcess attached at : %p ",shared_memory);
	printf("\nEnter data to write into shared memory : ");
	gets(str);
	strcpy(shared_memory,str);
	printf("\nYou wrote : %s", (char*)shared_memory);
	printf("\nRemoving the shared segment");
	if(shmctl(shmid,IPC_RMID,0)==-1)
	{
		printf("\nCannot remove shared memory segment");
	}
	else
		printf("\nRemoved successfully");
}

