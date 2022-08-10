#include <stdio.h>
#include <stdlib.h>

int mutex=1,full=0,empty=3,x=0;

int wait(int x)
{
	return --x;
}

int signal(int x)
{
	return 	++x;
}

int producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\nProducer produces item %d",x);
	mutex=signal(mutex);
}

int consumer()
{
	mutex=wait(mutex);
	empty=signal(empty);
	full=wait(full);
	printf("\nConsumer consumes item %d",x);
	x--;
	mutex=signal(mutex);
}

int main()
{
	int n;
	while(1)
	{
		printf("\n1. PRODUCER\n2. CONSUMER\n3. EXIT\nEnter user choice :");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				if(mutex==1 && empty!=0)
					producer();
				else
					printf("\nBUFFER IS FULL");
				break;
			case 2:
				if(mutex==1 && full!=0)
					consumer();
				else
					printf("\nBUFFER IS EMPTY");
				break;
			case 3:
				exit(0);
			default :
				printf("\nInvalid code ");
		}

	}
	
	return 0;
}
